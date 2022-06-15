Every pointer has an associated type. This type indicates what kind of object the pointer points to. Using the following pointer declarations as illustrations

```
       int *ip;
       char **cpp;
```


variable ip is a pointer to an object of type int, while cpp is a pointer to an object that itself is a pointer to an object of type char. In general, if the object has type T , then the pointer has type *T . The special void * type represents a generic pointer. For example, the malloc function returns a generic pointer, which is converted to a typed pointer via either an explicit cast or by the implicit casting of the assignment operation. Pointer types are not part of machine code; they are an abstraction provided by C to help programmers avoid addressing errors.
. Every pointer has a value. This value is an address of some object of the designated type. The special NULL (0) value indicates that the pointer does not point anywhere.
. Pointers are created with the ‘&’ operator. This operator can be applied to any C expression that is categorized as an lvalue, meaning an expression that can appear on the left side of an assignment. Examples include variables and the elements of structures, unions, and arrays. We have seen that the machine- code realization of the ‘&’ operator often uses the leaq instruction to compute the expression value, since this instruction is designed to compute the address of a memory reference.
. Pointers are dereferenced with the ‘*’ operator. The result is a value having the type associated with the pointer. Dereferencing is implemented by a memory reference, either storing to or retrieving from the specified address.
. Arrays and pointers are closely related. The name of an array can be referenced (but not updated) as if it were a pointer variable. Array referencing (e.g., a[3]) has the exact same effect as pointer arithmetic and dereferencing (e.g., *(a+3)). Both array referencing and pointer arithmetic require scaling the offsets by the object size. When we write an expression p+i for pointer p with value p, the resulting address is computed as p + L . i, where L is the size of the data type associated with p.
