## Machine-Level Programming V: Advanced Topics

### x86-64 Linux Memory Layout

- **Stack**
  - Runtime stack(8MB limit)
  - E.g., local varibles
- **Heap**
  - Dynamiclly allocated as needed
  - when call malloc(), calloc(), new()
- **Data**
  - Statically allocated data
  - E.g., global vars , static vars, string constants
- **Text  /  Shared Libraries**
  - Executable machine instructions
  - Read-only

### Buffer Overflow

### Unions

