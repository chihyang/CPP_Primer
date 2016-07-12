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
