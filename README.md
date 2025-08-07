Simple String Manipulation Class in C++
This project provides a custom string class, Str, in C++ that demonstrates dynamic memory management and operator overloading for intuitive string manipulation. It's a useful exercise for understanding the underlying mechanics of string objects in C++.
About The Project
The Str class is a custom implementation of a string data type. It encapsulates a dynamically allocated character array and manages its memory. The class overloads several operators to allow for natural and readable string operations, such as concatenation, comparison, and stream input/output.
This implementation was built to showcase:
Dynamic memory allocation with new and delete[].
The Rule of Three (destructor, copy constructor, and copy assignment operator - although a direct copy assignment is not present, the copy constructor handles similar logic).
Operator overloading for arithmetic, comparison, and stream operators.
Basic string manipulation methods like push_back, push_front, append, resize, and replace.
Features
Constructors: Default, from const char*, and copy constructor.
Dynamic Memory: Automatically handles memory allocation and deallocation.
Concatenation: Overloaded + operator to combine Str objects with other Str objects or const char*.
Comparison: Overloaded comparison operators (==, >, <, >=, <=) to compare the content of strings.
Stream I/O: Overloaded << and >> operators for easy printing to and reading from streams like std::cin and std::cout.
Manipulation Methods:
push_back(): Appends a character or a C-style string.
push_front(): Prepends a character.
append(): Inserts a character at a specified position.
replace(): Replaces a range of characters with a given character.
resize(): Changes the size of the string.
clear(): Clears the string's content.
