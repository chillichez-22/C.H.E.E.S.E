#include "math.hpp"
#include "shape.hpp"

#include <iostream>
#include <SDL3/SDL.h>

int main() {

	std::cout << "hello world" << "\n";

	if ( !SDL_Init( SDL_INIT_VIDEO ) ){
		std::cout << "SDL failed to link" << "\n";
	}
	else{
		std::cout << "SDL linked succesfully" << "\n";
	}

	std::getchar();
	return 0;
}