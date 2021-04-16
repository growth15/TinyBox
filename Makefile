
VERSION = 0.01
BUILDTIME = $(shell date "+%Y%m%d-%H%M")

APPLETS = cat ls
OBJECTS = tinybox.o utility.o $(patsubst %, %.o, $(APPLETS))
TARGET = tinybox
INSTALL_DIR ?= _install

CFLAGS += -DTB_VER='"$(VERSION)"'
CFLAGS += -DTB_BT='"$(BUILDTIME)"'
CFLAGS += -g -Wall
RM = rm -rf

all: $(TARGET)

install: $(TARGET) | $(INSTALL_DIR)
	cp $< $(INSTALL_DIR)
	$(foreach applet, $(APPLETS), \
		ln -s tinybox "$(INSTALL_DIR)/$(applet)"; \
		)

$(INSTALL_DIR):
	$(RM) $@
	mkdir -p $@

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $< $(LIBRARIES)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBRARIES)

.PHONY: all clean distclean force $(INSTALL_DIR)

clean:
	$(RM) $(TARGET) $(INSTALL_DIR) *.o

distclean: clean
	$(RM) $(TARGET) $(INSTALL_DIR)

force:
