## Dynamic Linking with Shared Library

Static libraries, like all software, need to be maintained and updated periodically

**shared** in two differeny ways

- First, in any given file system, there is exactly one .so file for a particular library. 
- Second, a single copy of the .text section of a shared library in memory can be shared by different running processes.

```
linux> gcc -shared -fpic -o libvector.so addvec.c multvec.c
```

