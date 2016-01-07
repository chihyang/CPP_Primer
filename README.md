# C++ Primer Solutions

My solutions to C++ Primer(5th edition) exercises, including problems that perplex me. ```Makefile``` for visual studio compiler and ```gcc``` will be added later.

## Contents
- [Chapter 1. Getting Started](chap01)
- Part I: The Basics
  - [Chapter 2. Variables and Basic Types](chap02)
  - [Chapter 3. Strings, Vectors, and Arrays](chap03)
  - [Chapter 4. Expressions](chap04)
  - [Chapter 5. Statements](chap05)
  - [Chapter 6. Functions](chap06)
  - [Chapter 7. Classes](chap07)
- Part II: The C++ Library
  - [Chapter 8. The IO Library](chap08)
  - [Chapter 9. Sequential Containers](chap09)
  - [Chapter 10. Generic Algorithms](chap10)
  - [Chapter 11. Associative Containers](chap11)
  - [Chapter 12. Dynamic Memory](chap12)
- Part III: Tools for Class Authors
  - [Chapter 13. Copy Control](chap13)
  - [Chapter 14. Overloaded Operations and Conversions](chap14)
  - [Chapter 15. Object-Oriented Programming](chap15)
  - [Chapter 16. Templates and Generic Programming](chap16)
- Part IV:  Advanced Topics
  - [Chapter 17. Specialized Library Facilities](chap17)
  - [Chapter 18. Tools for Large Programs](chap18)
  - [Chapter 19. Specialized Tools and Techniques](chap19)
- Tools To Improve Your Efficiency
  - [Tools](tools)

## Compiler version

* ```gcc```: (tdm64-1) 5.1.0
* ```clang```: 3.7.0 (tags/RELEASE_370/final)
* ```cl```: Visual Studio 2013, version 18.00.40629

## File Format

### Solutions to exercises

* Header files

> Exer07_26_Sales_data.h

Where ```Exer07_26``` corresponds to ```exercise 7.26```, ```_Sales_data``` corresponds to the (primary) class defined in the header.

* Source files

> Exer01_13_1.cpp

Where ```Exer01_13``` corresponds to ```exercise 1.13```, ```_1``` corresponds to the first question in the exercise. Whether ```_1``` (```_2```, ```_3``` and so on) appears depends on the number of questions of the exercise.

### Illustrations or verifications of key points

> Page046_underline.cpp

Where ```Page046``` corresponds to the page number of the key point, and ```underline``` is the key point to be illustrated or verified.

## Comments

### Warning

Not every file could compile. Some programs are intended for repeating an error so that I can know definitely what is correct and what is not. Every program that cannot be compiled successfully begins with a ```WARNING``` comment as below:

```cpp
// Warning: This is for verification. It CANNOT be compiled successfully by both compiler.
// The problem lies in line XX.
```

Generally, compile info will be added to the end of such files.

Before or after ```line XX```, there are comments for concrete explanation of the error. 

### Notes

Many files contain notes about explanations on perplexing points. Here is the list of files that contain notes:
- [Exer04_29.cpp](chap04/Exer04_29.cpp)
- [Page157_sizeof.cpp](chap04/Page157_sizeof.cpp)
- [Exer06_25.cpp](chap06/Exer06_25.cpp)
- [Exer06_30.cpp](chap06/Exer06_30.cpp)
- [Exer06_47.cpp](chap06/Exer06_47.cpp)
- [Page213_constparameter.cpp](chap06/Page213_constparameter.cpp)
- [Page239_constexprfunc.cpp](chap06/Page239_constexprfunc.cpp)
- [Page239_inline.cpp](chap06/Page239_inline.cpp)
- [Page244_functionmatch.cpp](chap06/Page244_functionmatch.cpp)
- [Exer07_32.cpp](chap07/Exer07_32.cpp)
- [Exer07_43_1.cpp](chap07/Exer07_43_1.cpp)
- [Exer07_43_2.cpp](chap07/Exer07_43_2.cpp)
- [Exer07_49.cpp](chap07/Exer07_49.cpp)
- [Page264_default.cpp](chap07/Page264_default.cpp)
- [Page285_namelookup.cpp](chap07/Page285_namelookup.cpp)
- [Page304_static.cpp](chap07/Page304_static.cpp)
- [Exer08_13.cpp](chap08/Exer08_13.cpp)
- [Page317_fstream.cpp](chap08/Page317_fstream.cpp)
- [Exer09_22.cpp](chap09/Exer09_22.cpp)
- [Exer09_24.cpp](chap09/Exer09_24.cpp)
- [Exer09_32.cpp](chap09/Exer09_32.cpp)
- [Page36_conversion.cpp](chap09/Page36_conversion.cpp)
- [Exer10_05.cpp](chap10/Exer10_05.cpp)
- [Exer10_24.cpp](chap10/Exer10_24.cpp)
- [Exer10_32.cpp](chap10/Exer10_32.cpp)
- [Page410_iteratorcategory.cpp](chap10/Page410_iteratorcategory.cpp)
- [Exer11_33.cpp](chap11/Exer11_33.cpp)
- [Exer12_27.cpp](chap12/Exer12_27.cpp)
- [Exer13_31.cpp](chap13/Exer13_31.cpp)
- [Exer13_48.cpp](chap13/Exer13_48.cpp)
- [Exer13_50.cpp](chap13/Exer13_50.cpp)
- [Exer13_53_2.cpp](chap13/Exer13_53_2.cpp)
- [Exer13_53_overload.cpp](chap13/Exer13_53_overload.cpp)
- [Exer13_54.cpp](chap13/Exer13_54.cpp)
- [Page536_noexcept.cpp](chap13/Page536_noexcept.cpp)
- [Page545_rvaluereference.cpp](chap13/Page545_rvaluereference.cpp)
- [Exer14_10.cpp](chap14/Exer14_10.cpp)
- [Exer14_18.cpp](chap14/Exer14_18.cpp)
- [Exer14_40.cpp](chap14/Exer14_40.cpp)
- [Exer14_42.cpp](chap14/Exer14_42.cpp)
- [Exer14_44.cpp](chap14/Exer14_44.cpp)
- [Page576_callable_object.cpp](chap14/Page576_callable_object.cpp)
- [Page584_mutual_conversion.cpp](chap14/Page584_mutual_conversion.cpp)
- [Page585_multiple_conversion.cpp](chap14/Page585_multiple_conversion.cpp)
- [Exer15_11.cpp](chap15/Exer15_11.cpp)
- [Exer15_26.cpp](chap15/Exer15_26.cpp)
- [Exer15_30.cpp](chap15/Exer15_30.cpp)
- [Page621_override_overload.cpp](chap15/Page621_override_overload.cpp)
- [Page626_derived_constructor.cpp](chap15/Page626_derived_constructor.cpp)
- [Page628_virtual_call.cpp](chap15/Page628_virtual_call.cpp)
- [Page639_private_virtual.cpp](chap15/Page639_private_virtual.cpp)
- [Exer16_27.cpp](chap16/Exer16_27.cpp)
- [Exer16_55.cpp](chap16/Exer16_55.cpp)
- [Exer16_63_64.cpp](chap16/Exer16_63_64.cpp)
- [Page665_friends.cpp](chap16/Page665_friends.cpp)
- [Page690_std_move.cpp](chap16/Page690_std_move.cpp)
- [Page697_passing_pointer.cpp](chap16/Page697_passing_pointer.cpp)
- [Page711_partial_specialization.cpp](chap16/Page711_partial_specialization.cpp)
- [Exer17_04.cpp](chap17/Exer17_04.cpp)
- [Exer17_05.cpp](chap17/Exer17_05.cpp)
- [Exer17_06.cpp](chap17/Exer17_06.cpp)
- [Exer17_11_12_13.cpp](chap17/Exer17_11_12_13.cpp)
- [Exer17_18.cpp](chap17/Exer17_18.cpp)
- [Exer17_21.cpp](chap17/Exer17_21.cpp)
- [Exer17_24.cpp](chap17/Exer17_24.cpp)
- [Exer17_25.cpp](chap17/Exer17_25.cpp)
- [Exer17_26.cpp](chap17/Exer17_26.cpp)
- [Exer17_33.cpp](chap17/Exer17_33.cpp)
- [Exer17_37.cpp](chap17/Exer17_37.cpp)
- [Exer17_38.cpp](chap17/Exer17_38.cpp)
- [Page764_lowlevel_IO.cpp](chap17/Page764_lowlevel_IO.cpp)
- [Exer18_03_1.cpp](chap18/Exer18_03_1.cpp)
- [Exer18_03_2.cpp](chap18/Exer18_03_2.cpp)
- [Exer18_03_3.cpp](chap18/Exer18_03_3.cpp)
- [Exer18_29_1.cpp](chap18/Exer18_29_1.cpp)
- [Exer18_29_2.cpp](chap18/Exer18_29_2.cpp)
- [Exer19_18.cpp](chap19/Exer19_18.cpp)
- [Exer19_18_ADL.cpp](chap19/Exer19_18_ADL.cpp)
- [Exer19_20.cpp](chap19/Exer19_20.cpp)
- [Exer19_26.cpp](chap19/Exer19_26.cpp)
- [Page840_Screen.cpp](chap19/Page840_Screen.cpp)
- [Exer07_32_Screen.h](chap07/Exer07_32_Screen.h)
- [Exer07_40_Book.h](chap07/Exer07_40_Book.h)
- [Exer09_51.h](chap09/Exer09_51.h)
- [Exer13_22_HasPtr.h](chap13/Exer13_22_HasPtr.h)
- [Exer13_28_BinStrTree_value.h](chap13/Exer13_28_BinStrTree_value.h)
- [Exer13_28_TreeNode_value.h](chap13/Exer13_28_TreeNode_value.h)
- [Exer13_34_36_37_Folder.h](chap13/Exer13_34_36_37_Folder.h)
- [Exer13_40_43_StrVec.h](chap13/Exer13_40_43_StrVec.h)
- [Exer13_44_47_49_String.h](chap13/Exer13_44_47_49_String.h)
- [Exer13_49_String.h](chap13/Exer13_49_String.h)
- [Exer13_53_HasPtr.h](chap13/Exer13_53_HasPtr.h)
- [Exer13_53_HasPtr_copy_swap.h](chap13/Exer13_53_HasPtr_copy_swap.h)
- [Exer13_54_HasPtr.h](chap13/Exer13_54_HasPtr.h)
- [Exer13_55_StrVec.h](chap13/Exer13_55_StrVec.h)
- [Page511_540_HasPtr.h](chap13/Page511_540_HasPtr.h)
- [Page519_542_Message.h](chap13/Page519_542_Message.h)
- [Page524_536_StrVec.h](chap13/Page524_536_StrVec.h)
- [Exer14_21_Sales_data.h](chap14/Exer14_21_Sales_data.h)
- [Exer14_27_StrBlob.h](chap14/Exer14_27_StrBlob.h)
- [Exer14_28_StrBlob.h](chap14/Exer14_28_StrBlob.h)
- [Exer14_30_StrBlob.h](chap14/Exer14_30_StrBlob.h)
- [Exer14_45_Sales_data.h](chap14/Exer14_45_Sales_data.h)
- [StrBlob.h](chap14/StrBlob.h)
- [String.h](chap14/String.h)
- [StrVec.h](chap14/StrVec.h)
- [Exer16_12_Blob.h](chap16/Exer16_12_Blob.h)
- [Exer16_28_unique_ptr.h](chap16/Exer16_28_unique_ptr.h)
- [Exer16_29_Blob.h](chap16/Exer16_29_Blob.h)
- [Exer16_58_StrVec.h](chap16/Exer16_58_StrVec.h)
- [Exer16_61_shared_ptr.h](chap16/Exer16_61_shared_ptr.h)
