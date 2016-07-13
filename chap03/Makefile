# This makefile generates executable files directly in a separate folder. It
# uses order-only prerequisites to make the object folder in case it does not
# exist. It uses wildcard character % to match every executable file and the
# corresponding source file, thus avoiding writing the same file names multiple
# times.

objdir := obj
objects := $(addprefix $(objdir)/,Exer03_01_1.exe \
			Exer03_01_2.exe \
			Exer03_01_3.exe \
			Exer03_02_1.exe \
			Exer03_02_2.exe \
			Exer03_04.exe \
			Exer03_05.exe \
			Exer03_06.exe \
			Exer03_07.exe \
			Exer03_08.exe \
			Exer03_10.exe \
			Exer03_12.exe \
			Exer03_13.exe \
			Exer03_14.exe \
			Exer03_15.exe \
			Exer03_16.exe \
			Exer03_17.exe \
			Exer03_20.exe \
			Exer03_21_2.exe \
			Exer03_22.exe \
			Exer03_23.exe \
			Exer03_24.exe \
			Exer03_25.exe \
			Exer03_31.exe \
			Exer03_32_1.exe \
			Exer03_32_2.exe \
			Exer03_35.exe \
			Exer03_36_1.exe \
			Exer03_36_2.exe \
			Exer03_39.exe \
			Exer03_40.exe \
			Exer03_41.exe \
			Exer03_42.exe \
			Exer03_43.exe \
			Exer03_44.exe \
			Exer03_45.exe \
			Page095_subscript.exe \
			Page112_iterator.exe \
			Page128_array.exe \
			Page130_typealias.exe)


all: $(objects)

$(objdir)/%.exe: %.cpp
	g++ -std=c++11 -Wall -o $@ $<

$(objects): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
