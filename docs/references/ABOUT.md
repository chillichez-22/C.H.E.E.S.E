Reference About Page

### About

References - What does the code do.
Reference API - What code is there.

It describes information about the code, what is does, where its used.
It answers " what does this code do ?" and " what parameters does the code need ?".

It ==IS== a general detailed description of ==what== the code does.
It is ==NOT== a detailed description of ==how== it works.

A Reference API ==IS== a list of all functions, methods, classes; and its information.
It is ==NOT== a description of how the code fits together.


Good references explain what the code does clearly and completely.
It should be simple and to the point.
It should not explain how the code functions or any concept.
It assumes you don't need to know how the code works.

It should provide information about the code. ( How it behaves, basic facts )
It should explain what parameters the code takes.
It should explain what returns the code gives.

It should provide potential problems that may arise, if applicable.

It should give examples of how to use the code.

### Writing

References should be broken into sections using categories ( Maths, Shapes, Collisions ).
Each new overarching category get there own markdown script.

The name of the overall category is the " # " header level 1.
Each concept has its own " ## " header level 2.
Then in a higher level than the previous goes the: variables, functions, methods, constructors, structs, classes.

Default order: Variables, Functions, Classes / Structs.
Class's order: Constructor, Members (Variables), Methods.

If a file contains only one class or struct, have the class / struct be the " ## " header level 2. Otherwise use a " ### " header level 3 for the class / struct, and use the " ## " header level 2 as the general concept. [See matrix for an example]

Example ( not reflective of current api ):

````
# Maths  <- Category

## struct Vector2  <- Struct ( Only this type is in the file )

### Functions
- add()  
- sub()

## struct Vector3

### Functions
- divide()
- multiply()

## Matrix  <- General Idea

### Variables      <- Public variables
- projectionMatrix  
- identity4x4 

### class Matrix   <- Class ( Not only this type is in the file )

#### Constructors
- Matrix()  

#### Variables
- identity  

#### Methods
- add()     
- multiply()

````
