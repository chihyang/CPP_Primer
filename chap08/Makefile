# This makefile is the same as the one in chapter 5, except that the recipe does
# not begin with a `-'. You can pass the flag `-k' to ignore errors.
# To compile multiple files at the same time, use flag `-j [n]', where n is the
# maximum number of job slots. The default value of n is 1.

objdir := obj
objects_gcc := $(addprefix $(objdir)/,$(patsubst %.cpp,%-gcc.exe,$(wildcard *.cpp)))
objects_cl := $(subst gcc,cl,$(objects_gcc))
objects_clang := $(subst gcc,clang,$(objects_gcc))

gcc: $(objects_gcc)

cl: $(objects_cl)

clang: $(objects_clang)

# add `-' before a command to ignore errors
$(objdir)/%-gcc.exe: %.cpp
	g++ -std=c++11 -Wall -o $@ $<

$(objects_gcc): | $(objdir)

$(objdir)/%-cl.exe: %.cpp
	cl -EHsc -W4 $< -Fo./$(subst .exe,.obj,$@) -Fe./$@
$(objects_cl): | $(objdir)

$(objdir)/%-clang.exe: %.cpp
	clang++ -std=c++11 -stdlib=libstdc++ -Wall -o $@ $<

$(objects_clang): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
