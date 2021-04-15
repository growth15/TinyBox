
VERSION = 0.01
BUILDTIME = $(shell date "+%Y%m%d-%H%M")

OBJECTS = tinybox.o
TARGET = tinybox

CFLAGS += -DTB_VER='"$(VERSION)"'
CFLAGS += -DTB_BT='"$(BUILDTIME)"'
CFLAGS += -g -Wall

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ -c $< $(LIBRARIES)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) $(LIBRARIES)

.PHONY: all clean distclean force

clean:
	$(RM) $(TARGET) *.o 

distclean: clean
	$(RM) $(TARGET)

force:
