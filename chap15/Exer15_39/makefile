# This is a bad makefile for its complexity. Modification will be made soon.
OBJDIR = obj
OBJECTS = $(OBJDIR)/Exer15_39_TextQuery.o \
          $(OBJDIR)/Exer15_39_NotQuery.o \
		  $(OBJDIR)/Exer15_39_AndQuery.o \
          $(OBJDIR)/Exer15_39_OrQuery.o \
		  $(OBJDIR)/Exer15_39_Query.o \
		  $(OBJDIR)/Exer15_39.o
cc = g++ 
CCFLAGS = -std=c++11
all: $(OBJECTS)
	$(cc) $(CCFLAGS) -o $(OBJDIR)/Exer15_39_gcc.exe $(OBJECTS)
$(OBJDIR)/Exer15_39.o: Exer15_39.cpp Exer15_39_TextQuery.h Exer15_39_Query.h Exer15_39_AndQuery.h \
	Exer15_39_OrQuery.h Exer15_39_NotQuery.h
	$(cc) $(CCFLAGS) -c Exer15_39.cpp -o $(OBJDIR)/Exer15_39.o
$(OBJDIR)/Exer15_39_Query.o: Exer15_39_Query.cpp Exer15_39_Query.cpp
	$(cc) $(CCFLAGS) -c Exer15_39_Query.cpp -o $(OBJDIR)/Exer15_39_Query.o
$(OBJDIR)/Exer15_39_OrQuery.o: Exer15_39_OrQuery.cpp Exer15_39_TextQuery.h Exer15_39_Query.cpp Exer15_39_OrQuery.h
	$(cc) $(CCFLAGS) -c Exer15_39_OrQuery.cpp -o $(OBJDIR)/Exer15_39_OrQuery.o
$(OBJDIR)/Exer15_39_AndQuery.o: Exer15_39_AndQuery.cpp Exer15_39_TextQuery.h Exer15_39_Query.h Exer15_39_AndQuery.h 
	$(cc) $(CCFLAGS) -c Exer15_39_AndQuery.cpp -o $(OBJDIR)/Exer15_39_AndQuery.o
$(OBJDIR)/Exer15_39_NotQuery.o: Exer15_39_NotQuery.cpp Exer15_39_TextQuery.h Exer15_39_Query.h Exer15_39_NotQuery.h 
	$(cc) $(CCFLAGS) -c Exer15_39_NotQuery.cpp -o $(OBJDIR)/Exer15_39_NotQuery.o
$(OBJDIR)/Exer15_39_TextQuery.o: Exer15_39_TextQuery.cpp Exer15_39_TextQuery.h
	$(cc) $(CCFLAGS) -c Exer15_39_TextQuery.cpp -o $(OBJDIR)/Exer15_39_TextQuery.o

.PHONY : clean
clean :
	-rm $(OBJECTS)