
// External
#include <string>
#include <iostream>
#include <SDL3/SDL.h>

// Outside Scope
#include "math.hpp"

#include "shape_2d.hpp"
#include "tri_2d.hpp"
#include "shape_3d.hpp"

#include "mouse.hpp"
#include "ui.hpp"

#include "colour.hpp"

#include "tri_rasteriser.hpp"


int main() {

	// Initialise SDL
	// Seg-faults can occur when not first

	if( !SDL_Init( SDL_INIT_VIDEO ) ){

		SDL_Log("Failed to Initialise SDL");
		return -1;
	}

	std::cout << "CPP version: " << __cplusplus << "\n";
	std::cout << "SDL3 version: " << SDL_GetVersion() << "\n";

	/*
	// Displays, and Window Selection

	SDL_DisplayID* displays;
	int displayCount;
	int targetDisplay = 2;

	displays = SDL_GetDisplays( &displayCount );

	std::cout << "Display count: " << displayCount << "\n";
	std::cout << "First Display: " << displays[0] << "\n";
	*/

	// FPS & Performance

	uint8_t fps = 60;
	uint64_t ticksPerFrame = 1000 / fps; 
	uint64_t elapsedFrame = 0;

	uint64_t startTime = 0;
	uint64_t endTime = 0;
	uint64_t deltaTime = 0;
	uint64_t previousTime = 0;


	// SDL Window Setup

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	window = SDL_CreateWindow(
		"C.H.E.E.S.E - SDL3", 
		500, 
		300, 
		SDL_WINDOW_RESIZABLE
	);
	renderer = SDL_CreateRenderer( 
		window, 
		NULL 
	);

	SDL_SetWindowMinimumSize( window, 160, 100 );
	SDL_SetWindowMaximumSize( window, 1920, 1200 );
	
	SDL_SetRenderVSync( renderer, 0 );


	// UI
	UI mainUI;


	// Mouse 
	enum MouseButtonEvent leftMouseButton;
	enum MouseButtonEvent middleMouseButton;
	enum MouseButtonEvent rightMouseButton;


	// Testing

	int width;
	int height;

	SDL_GetWindowSize( window, &width, &height );

	Vector2 pointOne =   Vector2( width * 0.5f, height * 0.4f );
	Vector2 pointTwo =   Vector2( width * 0.3f, height * 0.7f );
	Vector2 pointThree = Vector2( width * 0.7f, height * 0.7f );

	Tri2D testTri = Tri2D( pointOne, pointTwo, pointThree );
	ColourF testColour = ColourF( 255, 0, 0, 255 );

	std::cerr << "Width: " << width << "\n";
	std::cerr << "Height: " << height << "\n";

	// Main Loop
	bool running = true;

	bool shouldDeactivate = true;
	uint64_t deactivationStopwatch = 0;
	uint64_t deactivationTime = 5000;

	while ( running ){

		// FPS Management
		elapsedFrame += 1;
		startTime = SDL_GetTicks();

		deltaTime = startTime - previousTime;
		previousTime = startTime;

		// Poll events
		SDL_Event event;

		leftMouseButton = MouseButtonEvent::INACTIVE;
		middleMouseButton = MouseButtonEvent::INACTIVE;
		rightMouseButton = MouseButtonEvent::INACTIVE;

		while ( SDL_PollEvent( &event ) ){
			
			switch (event.type){
				
				case SDL_EVENT_QUIT:{
	
					running = true;
					break;
				}

				case SDL_EVENT_MOUSE_BUTTON_DOWN:{

					SDL_MouseButtonEvent mouseButton = event.button; 
					std::cout << "Button: " << std::to_string(mouseButton.button) << " was pressed.\n";
					
					switch (mouseButton.button){

						case 1:{

							leftMouseButton = MouseButtonEvent::PRESSED;
							break;
						}
						case 2:{

							middleMouseButton = MouseButtonEvent::PRESSED;
							break;
						}
						case 3:{

							rightMouseButton = MouseButtonEvent::PRESSED;
							break;
						}
					}

					break;
				}

				case SDL_EVENT_MOUSE_BUTTON_UP:{

					SDL_MouseButtonEvent mouseButton = event.button; 
					std::cout << "Button: " << std::to_string(mouseButton.button) << " was released.\n";

					switch (mouseButton.button){

						case 1:{

							leftMouseButton = MouseButtonEvent::RELEASED;
							break;
						}
						case 2:{

							middleMouseButton = MouseButtonEvent::RELEASED;
							break;
						}
						case 3:{

							rightMouseButton = MouseButtonEvent::RELEASED;
							break;
						}
					}

					break;
				}
				
			}

			Vector2 mousePos = Vector2( 0.f, 0.f );
			SDL_GetMouseState( &mousePos.x, &mousePos.y );

			//mainUI.setStatesOnInteractables( mousePos, leftMouseButton );

		}
		
 
		// Auto-Closer
		if ( shouldDeactivate ){
			
			deactivationStopwatch += deltaTime;

			if ( deactivationStopwatch >= deactivationTime ){
				running = false;
			}

		}	
		

		// Clears screen with white

		SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
		SDL_RenderClear( renderer );


		/** Start Rendering Pipeline Here*/

		// Draws bg
		SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );

		//mainUI.drawAll();

		RasteriseTri( renderer, testTri, testColour );

		


		/** End Rendering Pipeline Here */


		// Renders display
		SDL_RenderPresent( renderer );
		

		// FPS Management

		endTime = SDL_GetTicks();
		deltaTime = endTime - startTime;

		// Cap FPS
		if ( deltaTime < ticksPerFrame ){

			uint64_t delayTime = ticksPerFrame - deltaTime;
			SDL_Delay( delayTime );
		}

		//running = false;

	}

	SDL_DestroyWindow( window );
	SDL_Quit();


	std::getchar(); 

	return 0;
}