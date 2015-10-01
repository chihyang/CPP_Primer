OBJDIR = obj

CHAP1OBJS = $(OBJDIR)\Exer1_1.obj \
            $(OBJDIR)\Exer1_2.obj \
            $(OBJDIR)\Exer1_3.obj \
            $(OBJDIR)\Exer1_4.obj \
            $(OBJDIR)\Exer1_5.obj \
			$(OBJDIR)\Exer1_8.obj \
            $(OBJDIR)\Exer1_10.obj \
            $(OBJDIR)\Exer1_11.obj \
            $(OBJDIR)\Exer1_15.obj \
            $(OBJDIR)\Exer1_16.obj \
			$(OBJDIR)\Exer1_17.obj \
            $(OBJDIR)\Exer1_17_1.obj \
            $(OBJDIR)\Exer1_18.obj \
            $(OBJDIR)\Exer1_19.obj \
            $(OBJDIR)\Exer1_20.obj \
            $(OBJDIR)\Exer1_21.obj \
            $(OBJDIR)\Exer1_22.obj \
            $(OBJDIR)\Exer1_23.obj \
            $(OBJDIR)\Exer1_24.obj \
			$(OBJDIR)\Exer1_25.obj \
            $(OBJDIR)\avg_price.obj

CHAP1EXES = $(OBJDIR)\Exer1_1.exe \
            $(OBJDIR)\Exer1_2.exe \
            $(OBJDIR)\Exer1_3.exe \
            $(OBJDIR)\Exer1_4.exe \
            $(OBJDIR)\Exer1_5.exe \
			$(OBJDIR)\Exer1_8.exe \
            $(OBJDIR)\Exer1_10.exe \
            $(OBJDIR)\Exer1_11.exe \
            $(OBJDIR)\Exer1_15.exe \
            $(OBJDIR)\Exer1_16.exe \
			$(OBJDIR)\Exer1_17.exe \
            $(OBJDIR)\Exer1_17_1.exe \
            $(OBJDIR)\Exer1_18.exe \
            $(OBJDIR)\Exer1_19.exe \
            $(OBJDIR)\Exer1_20.exe \
            $(OBJDIR)\Exer1_21.exe \
            $(OBJDIR)\Exer1_22.exe \
            $(OBJDIR)\Exer1_23.exe \
            $(OBJDIR)\Exer1_24.exe \
            $(OBJDIR)\avg_price.exe

# Generate executable files for every source file
# -Fe: cl.exe, specify path and/or name of executable file
$(CHAP1EXES): $(CHAP1OBJS)
	@$(CC) -Fe$(OBJDIR)/$(@B).exe $(OBJDIR)/$(@B).obj

# Generate object files for each source file
# -Fo: cl.exe, specify path and/or name of object file
$(CHAP1OBJS): $(@B).cpp
	@$(CC) -EHsc -c -Fo$(OBJDIR)/$(@B).obj $(@B).cpp

clean:
	rm -f obj/*
	