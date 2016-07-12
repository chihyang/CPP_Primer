objdir := obj
objects := $(addprefix $(objdir)/,$(patsubst %.cpp,%.exe,$(wildcard *.cpp)))

all: $(objects)

$(objdir)/%.exe: %.cpp
	-g++ -std=c++11 -Wall -o $@ $< # add `-' before a command to ignore errors

$(objects): | $(objdir)

$(objdir):
	mkdir $(objdir)

clean:
	rm $(objdir)/*
