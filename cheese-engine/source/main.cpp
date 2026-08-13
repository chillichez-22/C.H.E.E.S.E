#include "math.hpp"
#include "shape.hpp"

#include <iostream>
#include <SDL3/SDL.h>

int main() {

	// Initialise SDL
	// Seg-faults can occur when not first
	if( !SDL_Init( SDL_INIT_VIDEO ) ){

		SDL_Log("Failed to Initialise SDL");
		return -1;
	}

	std::cout << "CPP version: " << __cplusplus << std::endl;

	SDL_Window* window;
	SDL_Renderer* renderer;

	window = SDL_CreateWindow(
		"C.H.E.E.S.E - SDL3", 
		500, 
		300, 
		SDL_WINDOW_RESIZABLE |
		SDL_WINDOW_RESIZABLE
	);

	SDL_SetWindowMinimumSize( window, 160, 100 );
	SDL_SetWindowMaximumSize( window, 1920, 1200 );

	renderer = SDL_CreateRenderer( window, NULL );


	bool running = true;

	while (running){

		// Poll events
		SDL_Event event;

		while (SDL_PollEvent(&event)){
			
			// Quits
			switch (event.type){
			
				case SDL_EVENT_QUIT:
					running = true;
					break;
			}

		}

		// Clears screen with white
		SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
		SDL_RenderClear( renderer );

		// Draws bg
		SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
		SDL_RenderPoint( renderer, 500/2, 300/2 );
		
		// Renders display
		SDL_RenderPresent( renderer );
		SDL_Delay( 5000 );
		
		running = false;
	}

	SDL_DestroyWindow( window );
	SDL_Quit();
	return 0;
}