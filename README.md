# C++ Primer Solutions
My solutions of C++ Primer(5th edition) exercises, including problems that perplex me. Makefile for visual studio compiler and gcc compiler will be added subsequently.

## Compiler version
```cl```: visual studio 2013, version 18.00.40629

```gcc```: (tdm64-1) 5.1.0

## File Format
Every chapter is a bipartite collection: one part is solutions of exercises that need programming and another verification of key points that perplex me. Files of the former are named in this way: ```Exer01_01.cpp```, where ```01_01``` corresponds to the chapter and exercise number. Some files are named such as ```Exer01_01_1.cpp```, ```Exer01_01_2.cpp```. They correspond to different questions in an exercise. Files of the latter part are named in this way: ```Page001_keypoint.cpp```, where ```001``` the page number and ```keypoint``` is the perplexing key point. Other files such as headers are named according to the requirement in question. Makefile is named as Makefile.

Most files contain appropriate comments to help myself understand some key points.

Not every file could be compiled successfully. Some programs are intended for repeating an error so that I can know definitely what is correct and what is not. Every program that cannot be compiled successfully begins with a WARNING comment like the following one:

```cpp
// Warning: This is for verifying. It CANNOT be compiled successfully by both compiler.
// The problem lies in line XX.
```

Sometimes it depends on complier whether an error is an error. So the WARNING info might be a little different(but still lucid enough). If necessary, compiler info is appended to the end of such files to show details.

Before or after ```line XX```, there are comments for concrete explanation of the error. 