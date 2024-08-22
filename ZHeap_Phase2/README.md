<h1 align = "center"> Heap Memory Manager </h1>

## Introduction
<h2 align = "center"> heap memory manager built with C. </h2>

Heap memory manager dynamic shared library used to run several processes like bash, vim, nano...etc. Libz can run any process that's not multi threaded as it does not handle race conditions.

![ZHeap](https://github.com/user-attachments/assets/972d1600-ed94-4a06-843a-336f99e2215b)
![Zmalloc](https://github.com/user-attachments/assets/ab3a6d29-f033-4288-a10e-5538f7a34396)
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
gcc -shared -fPIC -g *.c -o libz.so
```

## Outputs
`LD_PRELOAD=./libz.so bash:` <br>
```text
zkrallah@Zkrr:/mnt/e/STM/ZHeap_Phase2$
```
