OBJDIR = obj

CHAP3OBJS = $(OBJDIR)\Exer03_01_1.obj \
			$(OBJDIR)\Exer03_01_2.obj \
			$(OBJDIR)\Exer03_01_3.obj \
            $(OBJDIR)\Exer03_02_1.obj \
			$(OBJDIR)\Exer03_02_2.obj \
            $(OBJDIR)\Exer03_04.obj \
            $(OBJDIR)\Exer03_05.obj \
            $(OBJDIR)\Exer03_06.obj \
            $(OBJDIR)\Exer03_07.obj \
			$(OBJDIR)\Exer03_08.obj \
            $(OBJDIR)\Exer03_10.obj \
            $(OBJDIR)\Exer03_11.obj \
            $(OBJDIR)\Exer03_12.obj \
			$(OBJDIR)\Exer03_13.obj \
            $(OBJDIR)\Exer03_16.obj \
			$(OBJDIR)\Exer03_17.obj \
            $(OBJDIR)\Exer03_20.obj \
            $(OBJDIR)\Exer03_21_1.obj \
            $(OBJDIR)\Exer03_21_2.obj \
            $(OBJDIR)\Exer03_22.obj \
            $(OBJDIR)\Exer03_23.obj \
            $(OBJDIR)\Exer03_24.obj \
			$(OBJDIR)\Exer03_25.obj \
			$(OBJDIR)\Exer03_27.obj \
			$(OBJDIR)\Exer03_31.obj \
			$(OBJDIR)\Exer03_32_1.obj \
			$(OBJDIR)\Exer03_32_2.obj \
			$(OBJDIR)\Exer03_35.obj \
			$(OBJDIR)\Exer03_36_1.obj \
			$(OBJDIR)\Exer03_36_2.obj \
			$(OBJDIR)\Exer03_39.obj \
			$(OBJDIR)\Exer03_40.obj \
			$(OBJDIR)\Exer03_41.obj \
			$(OBJDIR)\Exer03_42.obj \
			$(OBJDIR)\Exer03_43.obj \
			$(OBJDIR)\Exer03_44.obj \
            $(OBJDIR)\Page095_subscript.obj \
            $(OBJDIR)\Page112_iterator.obj \
            $(OBJDIR)\Page128_array.obj \
            $(OBJDIR)\Page130_typealias.obj \

CHAP3EXESS = $(OBJDIR)\Exer03_01_1.exe \
			$(OBJDIR)\Exer03_01_2.exe \
			$(OBJDIR)\Exer03_01_3.exe \
            $(OBJDIR)\Exer03_02_1.exe \
			$(OBJDIR)\Exer03_02_2.exe \
            $(OBJDIR)\Exer03_04.exe \
            $(OBJDIR)\Exer03_05.exe \
            $(OBJDIR)\Exer03_06.exe \
            $(OBJDIR)\Exer03_07.exe \
			$(OBJDIR)\Exer03_08.exe \
            $(OBJDIR)\Exer03_10.exe \
            $(OBJDIR)\Exer03_11.exe \
            $(OBJDIR)\Exer03_12.exe \
			$(OBJDIR)\Exer03_13.exe \
            $(OBJDIR)\Exer03_16.exe \
			$(OBJDIR)\Exer03_17.exe \
            $(OBJDIR)\Exer03_20.exe \
            $(OBJDIR)\Exer03_21_1.exe \
            $(OBJDIR)\Exer03_21_2.exe \
            $(OBJDIR)\Exer03_22.exe \
            $(OBJDIR)\Exer03_23.exe \
            $(OBJDIR)\Exer03_24.exe \
			$(OBJDIR)\Exer03_25.exe \
			$(OBJDIR)\Exer03_27.exe \
			$(OBJDIR)\Exer03_31.exe \
			$(OBJDIR)\Exer03_32_1.exe \
			$(OBJDIR)\Exer03_32_2.exe \
			$(OBJDIR)\Exer03_35.exe \
			$(OBJDIR)\Exer03_36_1.exe \
			$(OBJDIR)\Exer03_36_2.exe \
			$(OBJDIR)\Exer03_39.exe \
			$(OBJDIR)\Exer03_40.exe \
			$(OBJDIR)\Exer03_41.exe \
			$(OBJDIR)\Exer03_42.exe \
			$(OBJDIR)\Exer03_43.exe \
			$(OBJDIR)\Exer03_44.exe \
            $(OBJDIR)\Page095_subscript.exe \
            $(OBJDIR)\Page112_iterator.exe \
            $(OBJDIR)\Page128_array.exe \
            $(OBJDIR)\Page130_typealias.exe \

# Generate executable files for every source file
# -Fe: cl.exe, specify path and/or name of executable file
$(CHAP3EXES): $(CHAP3OBJS)
	@$(CC) -Fe$(OBJDIR)/$(@B).exe $(OBJDIR)/$(@B).obj

# Generate object files for each source file
# -Fo: cl.exe, specify path and/or name of object file
$(CHAP3OBJS): $(@B).cpp
	@$(CC) -EHsc -c -Fo$(OBJDIR)/$(@B).obj $(@B).cpp

clean:
	rm -f obj/*
	