# Machine Level Programming V Advanced

## X86-64 Linux Memory Layout

- Stack
    - Runtime Stack (8MB limit)
    - E. g.local variables
- Heap
    - Dynamically allocated as needed
    - When call malloc(), calloc(), new()
- Data
    - statically allocated data
    - E.g. global vars , static vars, string constants
    
- Text /Shared Libraries
    - Executable machine instructions
    - Read-only
    
    ```
    00007FFFFFFFFFF┌──────────────────────────┐
                   │                          │
                   │          Stack           │
                   │                          │
                   ├────────────┬─────────────┤ 8MB
                   │            │             │
                   │            │             │
                   │            ▼             │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │    Shared Libraries      │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │             ▲            │
                   │             │            │
                   │             │            │
                   │             │            │
                   │             │            │
                   ├─────────────┴────────────┤
                   │                          │
                   │           Heap           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │           Data           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   │           Text           │
                   │                          │
                   ├──────────────────────────┤
                   │                          │
                   └──────────────────────────┘
    ```