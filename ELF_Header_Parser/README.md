<h1 align = "center"> ELF Header Parser </h1>

## Introduction
This application parses `ELF` files and prints the `ELF` header content, similar to the `readelf -h` command. <br>
The only missing part is the `OS/ABI:` part as there's a lot of values and including all of them in a switch case
would take a lot of time and make the code look overwhelming. <br>
The program works by passing the path to the required file to the program and it automatically prints the `ELF` headers it parsed.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic task2.c -o task2.exe
```

## Outputs

`readelf -h task2.exe :` <br>
```text
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Position-Independent Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1140
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14320 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
```

`./task2.exe task2.exe :` <br>
```text
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  ABI Version:                       0
  Type:                              3
  Machine:                           62
  Version:                           0x1
  Entry point address:               0x1140
  Start of program headers:          64 (bytes into file)
  Start of section headers:          14320 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
```
