## Relocation

- Relocating sections and symbol definitions
- Relocating symbol references within sections

## Loading Executable Object Files

any linux program can invoke the loader by calling the `execve` function

loader jumps to `_start` function is defined in  system object file *crt1.o*, then `_start` calls the *system startup function* `__libc_start_main`, which is defined in *libc.so*, then calls `main`