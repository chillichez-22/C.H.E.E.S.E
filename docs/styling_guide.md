Styling Guide.

## Naming Conventions

#### Files

All files will be lowercase with _ to separate new words.
Absolutely no spaces are to be used in naming of any file.

main.cpp
new_file.hpp
text_for_something.txt
new_file_2.md

Excluding files needed for the documentation: EDD ( Engine Design Document ), TDD(s) ( Technical Design Document(s) ), generated doxygen api. And other files that must have specific names, such as: "CMakeList.txt", "README.md", "LICENSE.txt".

#### Classes & Structs

All classes are structs will be PascalCase where each new word is a capital letter with no word delimiter.

class Vector
struct MyNewStruct
class LevelDataChunk

#### Methods & Variables & Everything else

Everything else will be camelCase where the first word has no capital letter at the start, but every following word has a capital start, with no word delimiter.

int add();
float subtractAllVectors();
bool isCollidingWithSomething();

int myInt;
float widthOfLine;
Vector2 screenSpaceCoord;


## Writing Documentation

Doxygen will be used primarily for code ==documentation== of function, classes with "/\*\*" ending with "*/" and variables with "/**<"  "*/>".
Code ==comments== will use default c++ comments structure.

### Code comments
```

// Code comment general descriptions

// Multi line comments 
// for longer description

```

Comments should not be written on every line of code. 

Comments explaining *what* is done should *preferably* not be written on any selection statement or loop ( if, case, while, do.... ). 
If this is the case then code structure would need to change to make it more obvious, as to, what is happening. 

Code should not be intentionally vague, or devoid of comments, but should be read first and explain itself within its own structure. Only afterwards comments are to be added, where clarity is *lacking*.

### Code Documentation
```

// Class, Struct, Function....  documentation

/**
* @brief For brief one line descriptions
* 
* @details For longer multi line 
* descriptions of the code
* 
* @param [Parameter] To describe the inputted parameter
* 
* @returns To describe the return case ( not needed if void )
* 
* @examples To give multi-line code snippets giving brief examples of
* how to use the code including parameters and returns
*/ 


// Variable documentation is used with the same style of doxygen comments with an arrow afterwards

int var; /**< Single line descriptions */

int var; //!< Detailed description of the member
         //!< using more than one line

```

