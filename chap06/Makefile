cc=g++
cflag = -std=c++11 -Wall
suffix = gcc

ifeq ($(cc),gcc++)
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
