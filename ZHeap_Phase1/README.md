<h1 align = "center"> Virtual Heap Memory Manager </h1>

## Introduction
<h2 align = "center"> Virtual heap memory manager built with C. </h2>

![ZHeap](https://github.com/user-attachments/assets/97ea99a7-e9d0-4ab8-b17a-7f5053f5777b)
![Zmalloc](https://github.com/user-attachments/assets/1bebcc48-e6ab-409e-ae40-097a07f1c1b7)
![Zfree](https://github.com/user-attachments/assets/a15d7341-afd6-4d2f-b661-6fb5cae397bf)

<br><hr>

For more clear view of the flowcharts, please visit : <br>
[ZHeap](https://www.canva.com/design/DAGOBxPBd4E/bCsOFm86_FA-AJEdeVDPNA/edit?utm_content=DAGOBxPBd4E&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
<br>
[Zmalloc](https://www.canva.com/design/DAGOBlWWlpk/cavKyrgBLZgLTIQkDpbsIw/edit?utm_content=DAGOBlWWlpk&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
<br>
[Zfree](https://www.canva.com/design/DAGOB2ICYbA/pyQv9pCPscG3oK4ysCvUQA/edit?utm_content=DAGOB2ICYbA&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 -static *.c -o test1.exe
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./test1.exe :` <br>
```text
the program break incremented by 128 bytes
the heap size now is 128 bytes
heap can be increased more by: 1048448 bytes if needed

the program break incremented by 128 bytes
the heap size now is 256 bytes
heap can be increased more by: 1048320 bytes if needed

Storing some initial data
value sotred at 0x4c9318 is 123456
value sotred at 0x4c9334 is a
value sotred at 0x4c934d is 325682
value sotred at 0x4c9369 is b
value sotred at 0x4c9382 is 1
value sotred at 0x4c9386 is 2
value sotred at 0x4c938a is 3
value sotred at 0x4c938e is 4
value sotred at 0x4c9392 is 5
value sotred at 0x4c9396 is 6
value sotred at 0x4c939a is 7
value sotred at 0x4c939e is 8
value sotred at 0x4c93a2 is 9
value sotred at 0x4c93a6 is 10
value sotred at 0x4c93c2 is hello
Start of the heap: 0x4c9300
Program break: 0x4c9400
The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 0
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 64 bytes
free: 0
next: 0x4c93aa
**************
start: 0x4c93aa
size: 30 bytes
free: 0
next: 0x4c93c8
**************
start: 0x4c93c8
size: 56 bytes
free: 1
next: (nil)
**************
Freeing first block

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 1
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 64 bytes
free: 0
next: 0x4c93aa
**************
start: 0x4c93aa
size: 30 bytes
free: 0
next: 0x4c93c8
**************
start: 0x4c93c8
size: 56 bytes
free: 1
next: (nil)
**************
Freeing last block (will merge with the block after if exists)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 1
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 64 bytes
free: 0
next: 0x4c93aa
**************
start: 0x4c93aa
size: 86 bytes
free: 1
next: (nil)
**************
Freeing the block before the last (will merge with the block after)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 1
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 150 bytes
free: 1
next: (nil)
**************
Allocate memory for int (first fit in the 1st block)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 0
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 150 bytes
free: 1
next: (nil)
**************
Freeing first block
Freeing the block after the first (will merge with the block before)

The blocks in heap:

start: 0x4c9300
size: 53 bytes
free: 1
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 150 bytes
free: 1
next: (nil)
**************
Allocate memory for int (first fit in the 1st block)
Initializing the value of the first block to 400 to see if it can reserve state after some processes
Allocate memory for char (first fit in the 2nd block)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 0
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 0
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 25 bytes
free: 0
next: 0x4c936a
**************
start: 0x4c936a
size: 150 bytes
free: 1
next: (nil)
**************
Freeing the second block
Freeing the fourth block (will merge with the block after)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 0
next: 0x4c931c
**************
start: 0x4c931c
size: 25 bytes
free: 1
next: 0x4c9335
**************
start: 0x4c9335
size: 28 bytes
free: 0
next: 0x4c9351
**************
start: 0x4c9351
size: 175 bytes
free: 1
next: (nil)
**************
Freeing the third block (2nd, 3rd, 4th blocks will merge)

The blocks in heap:

start: 0x4c9300
size: 28 bytes
free: 0
next: 0x4c931c
**************
start: 0x4c931c
size: 228 bytes
free: 1
next: (nil)
**************
value sotred at 0x4c9318 is 400
```
