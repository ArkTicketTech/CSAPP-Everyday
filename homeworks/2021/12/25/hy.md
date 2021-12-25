# Symbols and Symbol Tables

3 kins of symbols:

- **Global symbols:** defined by module *m* and can be referenced by other module

	- nonstatic functions and global variables

- **Externals:** global symbols that are referenced by module *m* but defined by other module

	- nonstatic functions and global variables that are defined by other modules

- **Local symbols:** defined and referenced exclusively by module *m*

	- static variables

```c
// ELF symbol table entry
typedef struct {
  int name; /* String table offset */
  char type:4, /* Function or data (4 bits) */
  binding:4; /* Local or global (4 bits) */
  char reserved; /* Unused */
  short section; /* Section header index */
  long value; /* Section offset or absolute address */
  long size; /* Object size in bytes */
} Elf64_Symbol;

```

## Symbol Resolution


