# gotRoot
Similiar to the last challenge but this time we are not intersted in reading data, we want to write to pointers.
The pointer is in the first few lines of the code and can be written to by passing a string that reads data from the stack until it reaches the pointer upon which we use `%n` to write a non-zero number to the pointer.
The address of the struct is the same as the one of the auth variable.
