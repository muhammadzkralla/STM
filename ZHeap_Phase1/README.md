<h1 align = "center"> Virtual Heap Memory Manager </h1>

## Introduction

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -static *.c -o test1.exe
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./test1.exe :` <br>
```text

the system break incremented by 512 bytes
the heap size now is 512 bytes
remaining in the heap: 1048064 bytes

Storing some initial data
value sotred at 0x4c8318 is 123456
value sotred at 0x4c8334 is a
value sotred at 0x4c834d is 325682
value sotred at 0x4c8369 is b
value sotred at 0x4c8382 is 1
value sotred at 0x4c8386 is 2
value sotred at 0x4c838a is 3
value sotred at 0x4c838e is 4
value sotred at 0x4c8392 is 5
value sotred at 0x4c8396 is 6
value sotred at 0x4c839a is 7
value sotred at 0x4c839e is 8
value sotred at 0x4c83a2 is 9
value sotred at 0x4c83a6 is 10
value sotred at 0x4c83c2 is Hello World!
Start of the heap: 0x4c8300

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 0
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 64 bytes
free: 0
next: 0x4c83aa
**************
start: 0x4c83aa
size: 36 bytes
free: 0
next: 0x4c83ce
**************
start: 0x4c83ce
size: 256 bytes
free: 1
next: (nil)
**************
Freeing first block

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 1
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 64 bytes
free: 0
next: 0x4c83aa
**************
start: 0x4c83aa
size: 36 bytes
free: 0
next: 0x4c83ce
**************
start: 0x4c83ce
size: 256 bytes
free: 1
next: (nil)
**************
Freeing last block (will merge with the block after if exists)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 1
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 64 bytes
free: 0
next: 0x4c83aa
**************
start: 0x4c83aa
size: 292 bytes
free: 1
next: (nil)
**************
Freeing the block before the last (will merge with the block after)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 1
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 356 bytes
free: 1
next: (nil)
**************
Allocate memory for int (first fit in the 1st block)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 0
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 356 bytes
free: 1
next: (nil)
**************
Freeing first block
Freeing the block after the first (will merge with the block before)

The blocks in heap:

start: 0x4c8300
size: 53 bytes
free: 1
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 356 bytes
free: 1
next: (nil)
**************
Allocate memory for int (first fit in the 1st block)
Allocate memory for char (first fit in the 2nd block)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 0
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 0
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 25 bytes
free: 0
next: 0x4c836a
**************
start: 0x4c836a
size: 356 bytes
free: 1
next: (nil)
**************
Freeing the second block
Freeing the fourth block (will merge with the block after)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 0
next: 0x4c831c
**************
start: 0x4c831c
size: 25 bytes
free: 1
next: 0x4c8335
**************
start: 0x4c8335
size: 28 bytes
free: 0
next: 0x4c8351
**************
start: 0x4c8351
size: 381 bytes
free: 1
next: (nil)
**************
Freeing the third block (2nd, 3rd, 4th blocks will merge)

The blocks in heap:

start: 0x4c8300
size: 28 bytes
free: 0
next: 0x4c831c
**************
start: 0x4c831c
size: 434 bytes
free: 1
next: (nil)
**************
Storing a value in the first block
value sotred at 0x4c8318 is 400
```
