Documentation Main About Page.

## About

Following Divio's Documentation guideline the documentation is broken up into four sections. 

Explanations
- How the code works

Guides
- How to use the code to solve a problem

References
- What the code does
- ( Reference API ) What code there is

Tutorials
- Teaching how to use aspects of the code

These help to create better documentation and tailor the specific amount of detail / clarity / or understanding the reader needs.

## Writing Docs

Doxygen will be used primarily for code ==documentation== of function, classes with "/\*\*" ending with "*/" and variables with "/**<"  "*/">.
Code ==comments== will use default c++ comments structure.


Code comments
```
// Code comment general descriptions

// Multi line comments 
// for longer description
```

Code Documentation
```
// Class, Struct, Function.... documentation

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
* @examples To give multi-Line code snippets giving brief examples of
* how to use the code including parameters and returns
*/ 

// Variable documentation is used with the same style of doxygen comments with an arrow afterwards

int var; /**< Single line descriptions */

int var; //!< Detailed description of the member
         //!< using more than one line
```

