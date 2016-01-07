#Tools to improve efficiency

Scripts under this directory are tools that helps save your energy. Some of them have completed
their tasks and shouldn't be used again.

##[Create chapter folders](CreateAllChapters.sh)

This script is used to create folders for every chapter. It __shouldn't__ be used 
again if you clone the project.

##[Format file names](FormatFileName.sh)

This script is used to insert prefix 0 into the name of existing files. For example,
an existing file is named as `Exer1_01.cpp`. The script will rename it as `Exer01_01.cpp`.
This script __shouldn't__ be used again if you clone the project.

##[Set object folders under every chapter](SetUpObjectionFolder.sh)

This script is used to create `obj` folder under the directory `chapXX`, where `XX` is between
`01` and `19`. If you clone the project, you can copy this script into the root directory of the project
and use it to setup `obj` folder under every chapter.

All of the scripts above are tested under windows with `Git Bash`. They may not work on real linux
platforms.

##Insert source file names into README.md

This is a tool for practising using C++. It includes 3 files:

- [InsertAnswer.h](InsertAnswer.h) 
- [ListFile.cpp](ListFile.cpp) 
- [InsertAnswer.cpp](InsertAnswer.cpp)

This tool is written with STL and windows API functions, it might not compile on Linux or other
platforms. The feature of the tool is to insert source file names in terms of Markdown style into
appropriate locations of a README.md file.

When we offer the path of a chapter , e.g. `../chap01`, as an argument, the tool will find all
of the C++ source files under the path and analyse the names of the source files, 
then it will associate the source files with corresponding exercises and insert 
the names of the source files into README.md under the path.

For example, the README.md of chapter 1 has the following contents:

>##Exercise 1.1
> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the _main_ program from page 2.
>##Exercise 1.2
> Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from _main_.

If the source file of exercise 1.1 exists, the tool will insert the name of the source file as below:

>##Exercise 1.1
> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the _main_ program from page 2.

>\[Exer01_01.cpp\]\(Exer01_01.cpp\)

>##Exercise 1.2
> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from _main_.

The string `[Exer01_01.cpp](Exer01_01.cpp)` will be converted to a hyper link by github.
If there are more than one source files associated with one exercise, they will be separated by " | ":

>\[Exer04_22_1.cpp\]\(Exer04_22_1.cpp\) | \[Exer04_22_2.cpp\]\(Exer04_22_2.cpp\)

This tool __shouldn't__ be used again if you clone the project.