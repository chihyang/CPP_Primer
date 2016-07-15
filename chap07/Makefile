# This makefile is the same as the one in chapter 5, except that the recipe does
# not begin with a `-'. You can pass the flag `-k' to ignore errors.

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
