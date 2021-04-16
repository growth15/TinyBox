# TinyBox
[Tiny BusyBox](https://github.com/growth15/TinyBox)

## format `tinybox.c`

```bash
clang-tidy tinybox.c -fix-errors -checks="readability-braces-around-statements"
clang-format -i tinybox.c
```

## install

```bash
make install
# or
make install INSTALL_DIR=install_dir
```
