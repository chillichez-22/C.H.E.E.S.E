#include "math.hpp"
#include "shape.hpp"

// External
#include <iostream>
#include <SDL3/SDL.h>


int main() {

	std::cout << "Testing Scene Loaded.";
	std::cout << "Testing Scene Ended.";


	int x = 10;

    // ref is a reference to x.
    int& ref = x;

    // printing value using ref
    std::cout << ref << "\n";
    
    // Changing the value and printing again
    ref = 22;

    std::cout << ref << "\n";
    std::cout << x;

	std::getchar(); 

    return 0;
}
	