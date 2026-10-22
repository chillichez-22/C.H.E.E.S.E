
// External
#include <string>
#include <iostream>
#include <cstdint>
#include <SDL3/SDL.h>


// Outside Scope

#include "colour.hpp"

// Maths
#include "math.hpp"

// Math Data-Types
#include "buffer.hpp"
#include "vector_2.hpp"
#include "vector_3.hpp"
#include "matrix.hpp"

// Shapes
#include "shape_2d.hpp"
#include "tri_2d.hpp"

#include "shape_3d.hpp"
#include "tri_3d.hpp"

// Inputs & UI
#include "mouse.hpp"
#include "ui.hpp"

// Loading
#include "loading.hpp"

// Rendering
#include "rendering.hpp"
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


	// Displays, and Window Selection
	/*
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
	uint64_t elapsedFrames = 0;

	uint64_t startTime = 0;
	uint64_t endTime = 0;
	uint64_t deltaTime = 0;
	uint64_t previousTime = 0;


	// SDL Window Setup

	unsigned int width = 500;
	unsigned int height = 300;

	SDL_Window* window;
	SDL_Renderer* renderer; 
	
	window = SDL_CreateWindow(
		"C.H.E.E.S.E - SDL3", 
		width, 
		height, 
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


	// Rendering Setup

	Buffer< ObjectVertex > vertexBuffer = Buffer<ObjectVertex>(); /**< Buffer object for raw vertex data loaded in from 3D objects and models */
	Buffer< uint32_t > indexBuffer = Buffer<uint32_t>();      /**< Buffer object for indexes ( that point to the `vertexBuffer` ) to make objects */

	const unsigned int topologyVertexCount = 3;   /**< Vertex count, to make up the primitives in a vertex buffer */

	Matrix4x4< float > objectMatrix; 		/**< Base object matrix for each object.  */
	Matrix4x4< float > screenMatrix;		/**< Screen matrix for the camera translation. */
	Matrix4x4< float > projectionMatrix;	/**< Projection matrix for the screen space translation. */

	Vector4 cameraPos{ 0.f, 0.f, 0.f, 0.f };	/**< Centre of the camera.*/
	Vector3 cameraDir{ 0.f, 0.f, -1.f }; 		/**< Direction the camera is facing */


	// Testing

	Entity testEntity;

	Vector3 pointOne = Vector3( width * 0.5f, height * 0.4f, 1 );
	Vector3 pointTwo = Vector3( width * 0.3f, height * 0.7f, 1 );
	Vector3 pointThree = Vector3( width * 0.7f, height * 0.9f, 1 );
	
	std::cout << "testTri" << "\n";
	Tri3D testTri = Tri3D( pointOne, pointTwo, pointThree );
	
	ColourI red = ColourI( 255, 0, 0 ); 
	ColourI green = ColourI( 0, 255, 0 );
	ColourI blue = ColourI( 255, 0, 255 );
	
	Vector2 emptyUV = Vector2( 0, 0 );
	
	/** Loads vertex data */
	
	std::cout << "vertexOne" << "\n";
	ObjectVertex vertexOne =   ObjectVertex( testTri.points[0], emptyUV, red );
	std::cout << "vertexTwo" << "\n";
	ObjectVertex vertexTwo =   ObjectVertex( testTri.points[1], emptyUV, green );
	std::cout << "vertexThree" << "\n";
	ObjectVertex vertexThree = ObjectVertex( testTri.points[2], emptyUV, blue );


	bool doesVertexEqual = vertexOne == vertexTwo;
	std::cout << "VertexEqual ( should be false or 0 ) : " << doesVertexEqual << "\n";

	bool doesVectorEqual = pointOne == pointTwo;
	std::cout << "VectorEqual ( should be false or 0 ) : " << doesVectorEqual << "\n";

	bool doesColourEqual = red == green;
	std::cout << "ColourEqual ( should be false or 0 ) : " << doesColourEqual << "\n";
	


	std::array< ObjectVertex, 3 > vertexList{ vertexOne, vertexTwo, vertexThree };

	std::cout << vertexList[0] << vertexList[1] << vertexList[2] << "\n";

	testEntity = loadVertexData( testEntity, vertexList, vertexBuffer, indexBuffer );

	std::cout << "\n" << vertexBuffer.size() << " | " << vertexBuffer << "\n";
	std::cout << "\n" << indexBuffer.size() << " | " << indexBuffer  << "\n";


	/*
	// Adds vertex data to both index and vertex Buffers

	indexBuffer.push_back( vertexBuffer.push_back( vertexOne ) );
	indexBuffer.push_back( vertexBuffer.push_back( vertexTwo ) );
	indexBuffer.push_back( vertexBuffer.push_back( vertexThree ) );
	*/


	// Main Loop

	bool running = true;

	bool shouldDeactivate = false;
	uint64_t deactivationStopwatch = 0;
	uint64_t deactivationTime = 5000;

	while ( running ){

		// FPS Management
		elapsedFrames += 1;
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
	
					running = false;
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

		//running = true;

	}

	SDL_DestroyWindow( window );
	SDL_Quit();


	std::getchar(); 

	return 0;
}