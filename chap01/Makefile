# This makefile uses neither variables nor implicit rules. You can only make all
# or each target one after another. Besides, this makefile supports only g++ as
# compiler. You cannot use visual studio or clang or any other compilers. Last
# but not the least, every executable file is generated in source file folder
# rather than in a separate folder, which makes the folder dirty.

all: avg_price.exe \
		Exer01_01.exe \
		Exer01_02.exe \
		Exer01_03.exe \
		Exer01_04.exe \
		Exer01_05.exe \
		Exer01_08.exe \
		Exer01_09.exe \
		Exer01_10.exe \
		Exer01_11.exe \
		Exer01_12.exe \
		Exer01_13_1.exe \
		Exer01_13_2.exe \
		Exer01_13_3.exe \
		Exer01_18.exe \
		Exer01_19.exe \
		Exer01_20.exe \
		Exer01_21.exe \
		Exer01_22.exe \
		Exer01_24.exe \
		Exer01_25.exe
	cp *.exe ./obj/

avg_price.exe: avg_price.cpp Sales_item.h
	g++ -std=c++11 -Wall -o avg_price.exe avg_price.cpp

Exer01_01.exe: Exer01_01.cpp
	g++ -std=c++11 -Wall -o Exer01_01.exe Exer01_01.cpp

Exer01_02.exe: Exer01_02.cpp
	g++ -std=c++11 -Wall -o Exer01_02.exe Exer01_02.cpp

Exer01_03.exe: Exer01_03.cpp
	g++ -std=c++11 -Wall -o Exer01_03.exe Exer01_03.cpp

Exer01_04.exe: Exer01_04.cpp
	g++ -std=c++11 -Wall -o Exer01_04.exe Exer01_01.cpp

Exer01_05.exe: Exer01_05.cpp
	g++ -std=c++11 -Wall -o Exer01_05.exe Exer01_05.cpp

Exer01_07.exe: Exer01_07.cpp
	g++ -std=c++11 -Wall -o Exer01_07.exe Exer01_07.cpp

Exer01_08.exe: Exer01_08.cpp
	g++ -std=c++11 -Wall -o Exer01_08.exe Exer01_08.cpp

Exer01_09.exe: Exer01_09.cpp
	g++ -std=c++11 -Wall -o Exer01_09.exe Exer01_09.cpp

Exer01_10.exe: Exer01_10.cpp
	g++ -std=c++11 -Wall -o Exer01_10.exe Exer01_10.cpp

Exer01_11.exe: Exer01_11.cpp
	g++ -std=c++11 -Wall -o Exer01_11.exe Exer01_11.cpp

Exer01_12.exe: Exer01_12.cpp
	g++ -std=c++11 -Wall -o Exer01_12.exe Exer01_12.cpp

Exer01_13_1.exe: Exer01_13_1.cpp
	g++ -std=c++11 -Wall -o Exer01_13_1.exe Exer01_13_1.cpp

Exer01_13_2.exe: Exer01_13_2.cpp
	g++ -std=c++11 -Wall -o Exer01_13_2.exe Exer01_13_2.cpp

Exer01_13_3.exe: Exer01_13_3.cpp
	g++ -std=c++11 -Wall -o Exer01_13_3.exe Exer01_13_3.cpp

Exer01_16.exe: Exer01_16.cpp
	g++ -std=c++11 -Wall -o Exer01_16.exe Exer01_16.cpp

Exer01_18.exe: Exer01_18.cpp
	g++ -std=c++11 -Wall -o Exer01_18.exe Exer01_18.cpp

Exer01_19.exe: Exer01_19.cpp
	g++ -std=c++11 -Wall -o Exer01_19.exe Exer01_19.cpp

Exer01_20.exe: Exer01_20.cpp Sales_item.h
	g++ -std=c++11 -Wall -o Exer01_20.exe Exer01_20.cpp

Exer01_21.exe: Exer01_21.cpp Sales_item.h
	g++ -std=c++11 -Wall -o Exer01_21.exe Exer01_21.cpp

Exer01_22.exe: Exer01_22.cpp Sales_item.h
	g++ -std=c++11 -Wall -o Exer01_22.exe Exer01_22.cpp

Exer01_24.exe: Exer01_24.cpp Sales_item.h
	g++ -std=c++11 -Wall -o Exer01_24.exe Exer01_24.cpp

Exer01_25.exe: Exer01_25.cpp Sales_item.h
	g++ -std=c++11 -Wall -o Exer01_25.exe Exer01_25.cpp

clean:
	rm *.exe
	rm obj/*
