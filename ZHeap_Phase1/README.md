<h1 align = "center"> Virtual Heap Memory Manager </h1>

## Introduction

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -static *.c -o test.exe
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./test.exe :` <br>
```text
the system break incremented by 512 bytes
the heap size now is 512 bytes
remaining in the heap: 1048064 bytes
start of the heap: 0x4c7300
ptr1: 0x4c7318
ptr2: 0x4c7334
ptr3: 0x4c734d
ptr4: 0x4c7369
ptr5: 0x4c7382

The blocks in heap:

start: 0x4c7300
size: 28 bytes
free: 0
next: 0x4c731c
**************
start: 0x4c731c
size: 25 bytes
free: 0
next: 0x4c7335
**************
start: 0x4c7335
size: 28 bytes
free: 0
next: 0x4c7351
**************
start: 0x4c7351
size: 25 bytes
free: 0
next: 0x4c736a
**************
start: 0x4c736a
size: 28 bytes
free: 0
next: 0x4c7386
**************
start: 0x4c7386
size: 378 bytes
free: 1
next: (nil)
**************
the value of ptr1: 69
the value of ptr2: a
the value of ptr3: 420
the value of ptr4: b
the value of ptr5: 18
```
