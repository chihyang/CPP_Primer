# This makes file is similar to the one in chapter 4. The difference is that you
# can choose different compilers by passing command line parameters. For
# example, you can use `make gcc' to generate choose g++ compiler, `make cl' to
# choose visual studio compiler and so on.

objdir := obj
objects_gcc := $(addprefix $(objdir)/,$(patsubst %.cpp,%-gcc.exe,$(wildcard *.cpp)))
objects_cl := $(subst gcc,cl,$(objects_gcc))
objects_clang := $(subst gcc,clang,$(objects_gcc))

gcc: $(objects_gcc)

cl: $(objects_cl)

clang: $(objects_clang)

# add `-' before a command to ignore errors
$(objdir)/%-gcc.exe: %.cpp
	-g++ -std=c++11 -Wall -o $@ $<

$(objects_gcc): | $(objdir)

$(objdir)/%-cl.exe: %.cpp
	-cl -EHsc -W4 $< -Fo./$(subst .exe,.obj,$@) -Fe./$@

$(objects_cl): | $(objdir)

$(objdir)/%-clang.exe: %.cpp
	-clang++ -std=c++11 -stdlib=libstdc++ -Wall -o $@ $<

$(objects_clang): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
