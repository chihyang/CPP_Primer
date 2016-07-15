# This makefile has the same function as the one in chapter 5 but implements in
# a different way. You must pass the variable `cc' a value to choose different
# compilers, as showed below.
#
# Pass compiler info to make, such as:
#
# make cc=cl
# make cc=clang++
# make cc=g++
#
# The optional compilers are g++, clang++ and cl, as listed above. If no
# compiler is offered, it uses g++ as default.

cc=g++
cflag = -std=c++11 -Wall
suffix = gcc

ifeq ($(cc),g++)
	cflag = -std=c++11 -Wall
	suffix = gcc
else ifeq ($(cc),clang++)
	cflag = -std=c++11 -stdlib=libstdc++ -Wall
	suffix = clang
else ifeq ($(cc),cl)
	cflag = -EHsc -W4
	suffix = cl
endif

objdir := obj
objects := $(addprefix $(objdir)/,$(patsubst %.cpp,%-$(suffix).exe,$(wildcard *.cpp)))

all: $(objects)

# add `-' before a command to ignore errors
$(objects): $(objdir)/%-$(suffix).exe: %.cpp | $(objdir)
ifeq ($(cc),cl)
	-$(cc) $(cflag) $< -Fo./$(subst .exe,.obj,$@) -Fe./$@
else
	-$(cc) $(cflag) -o $@ $<
endif

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
