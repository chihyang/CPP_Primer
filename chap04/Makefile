# This make file eliminates all of the source file names by using builtin
# functions of make. It uses $@ to refer to the current target and $< the first
# of corresponding prerequisites. The `-' before `g++' tells make to ignore
# errors and keep going on. Except these, this one is the same as the one in
# chapter 3.

objdir := obj
objects := $(addprefix $(objdir)/,$(patsubst %.cpp,%.exe,$(wildcard *.cpp)))

all: $(objects)

# add `-' before a command to ignore errors
$(objdir)/%.exe: %.cpp
	-g++ -std=c++11 -Wall -o $@ $<

$(objects): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
