# Algorithm design & analysis (COM-103 @ UPGDL)

Repository with sample code for the COM-103 class. This is the sequence of COM-019, thus
the projects start from the next topic after the last of 019.

## 8. Standard Template Library

This chapter discusses the use of the standard template library, mainly the containers such as vectors, queue and map.

## 9. Advanced topics on functions

This chapter talks about concepts such as function overloading, recursion and user-defined templates

## 10. User-defined types

This chapter talks about how users can define their own data types beyond the default types. We discuss the creation and use of Structs and Enumerations; we also discuss the renaming of these elements as an independent type with the **"typedef"** keyword. Finally we also discuss operator overloading.

## 11. Error handling

This chapter talks about the error handling mechanisms. We show how to use the **try-catch** clauses, the definition of exceptions and how we can propagate errors higher in the hierarchy; also the **assert** function.

## 12. Code Reusability

This chapter discusses how we organize our code with the use of header files, namespaces and libraries. We also introduce the use of Pre-Processor directives.

## 13. Program Optimization

This chapter deals with the concepts of memory management such as the creation and use of pointers to multiple types of variables; from simple variables to arrays, structs, etc. The same way we show how to use pointers to pass variables by reference instead of by value. We also introduce **lambda** functions

## 14. Object Oriented Programming (OOP)

This chapter deals with the concepts of Object Oriented Programming. From the declaration and definition of an object, to definition of interfaces, encapsulation, constructors, inheritance and abstract classes.

## 15. Templates

This chapter further discusses the use of templates, in this case we introduce also template classes.

## 16. Compilation

This final chapter discuss on how to use **Makefiles** to automate the compilation process.

## Configuration to execute C/C++ in VS Code

- Install a c/c++ compiler via mingw or others
- Add MINGW_HOME to system and then to PATH
- Terminal > Run build task - (Select g++ | Make sure it is the one under mingw folder)
- A .exe file will appear in the folder
- Run it from console as ./<file>.exe or just with the play button above the code.
- To debug remember to place the breakpoints where you want to use them as such.

More info [here](https://code.visualstudio.com/docs/languages/cpp)
