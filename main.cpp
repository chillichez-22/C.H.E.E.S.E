
// External
#include <string>
#include <iostream>
#include <cstdint>
#include <SDL3/SDL.h>


// Outside Scope

#include "entity.hpp"
#include "camera.hpp"



// Maths
#include "math.hpp"

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

#include "projection.hpp"
#include "rendering.hpp"

#include "view_volume.hpp"
#include "colour.hpp"
#include "vertex.hpp"


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

	uint8_t fps = 60;	/**< Frame rate of the game, how many frames to calculate per 1000 millisecs */
	uint64_t secondsPerFrame = 1000 / fps; /** < How many milliseconds 1 frame will take, at the current `fps` */
	uint64_t elapsedFrames = 0;	/**< Current number of frames passed */

	uint64_t previousTime = 0; 	/**< Start time of the last frame in milliseconds */
	uint64_t startTime = 0;		/**< Start time of the current frame in milliseconds */
	uint64_t endTime = 0;		/**< End time of the current frame in milliseconds */
	uint64_t deltaTime = 0;		/**< Time taken to complete a frame ( Including the delay induced by the frame cap of `fps` ) */
	uint16_t effectiveFps = 60;	/**< Current FPS of the game without delaying due to the frame cap of `fps` ( Hypothetically, its highest FPS we can run at ) */


	// SDL Window Setup

	unsigned int width = 500;
	unsigned int height = 300;

	SDL_Window* window;
	SDL_Renderer* renderer; 
	
	const char* title = "C.H.E.E.S.E - SDL3";
	SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE; // Use || (or) to add more flags. E.G: FLAG_1 || FLAG_2 || FLAG_3

	window = SDL_CreateWindow(
		title, 
		width, 
		height, 
		flags
	);
	renderer = SDL_CreateRenderer( 
		window, 
		NULL 
	);

	SDL_SetWindowMinimumSize( window, 160, 100 );
	SDL_SetWindowMaximumSize( window, 1920, 1080 );
	
	SDL_SetRenderVSync( renderer, 0 );


	// UI

	UI mainUI;


	// Mouse 
	
	enum MouseButtonEvent leftMouseButton;
	enum MouseButtonEvent middleMouseButton;
	enum MouseButtonEvent rightMouseButton;


	// Rendering

	Buffer< uint32_t > indexBuffer = Buffer<uint32_t>();			/**< Buffer object for indexes ( that point to the `vertexBuffer` ) */
	Buffer< ObjectVertex > vertexBuffer = Buffer<ObjectVertex>();	/**< Buffer object for vertex data loaded in from 3D objects and models */

	const uint8_t topologyVertexCount = 3; /**< Vertex count, to make up the primitives in a vertex buffer */

	RenderSettings renderingSettings;

	// Defined at the rendering step instead: 
	// Matrix4x4< float > objectMatrix;		/**< Base object matrix for each object.  */

	Matrix4x4< float > viewMatrix;			/**< View matrix for the camera translation. */
	Matrix4x4< float > projectionMatrix;	/**< Projection matrix for the screen space translation. */

	Camera mainCamera = Camera( Vector3( 0, 0, 0 ), ( width / height ), 120.f, 100.f );		/** Main camera for the scene */


	// Testing

	Entity testEntity;

	Vector3 pointOne = Vector3( width * 0.5f, height * 0.4f, 1 );
	Vector3 pointTwo = Vector3( width * 0.3f, height * 0.7f, 1 );
	Vector3 pointThree = Vector3( width * 0.7f, height * 0.9f, 1 );
	
	std::cout << "testTri" << "\n";
	Tri3D testTri = Tri3D( pointOne, pointTwo, pointThree );
	
	ColourI red = ColourI( 255, 0, 0 ); 
	ColourI green = ColourI( 0, 255, 0 );
	ColourI blue = ColourI( 0, 0, 255 );
	
	Vector2 emptyUV = Vector2( 0, 0 );
	Vector3 emptyNormal = Vector3( 0, 0, 0);
	

	/** Loads vertex data */
	
	//std::cout << "vertexOne" << "\n";
	ObjectVertex vertexOne =   ObjectVertex( testTri.points[0], emptyNormal, emptyUV, red );

	//std::cout << "vertexTwo" << "\n";
	ObjectVertex vertexTwo =   ObjectVertex( testTri.points[1], emptyNormal, emptyUV, green );

	//std::cout << "vertexThree" << "\n";
	ObjectVertex vertexThree = ObjectVertex( testTri.points[2], emptyNormal, emptyUV, blue );

	
	/* Testing parity between vertexes... 

	bool doesVertexEqual = vertexOne == vertexTwo;
	std::cout << "VertexEqual ( should be false or 0 ) : " << doesVertexEqual << "\n";

	bool doesVectorEqual = pointOne == pointTwo;
	std::cout << "VectorEqual ( should be false or 0 ) : " << doesVectorEqual << "\n";

	bool doesNormalEqual = emptyNormal == emptyNormal;
	std::cout << "NormalEqual ( should be true or 1 ) : " << doesNormalEqual << "\n";

	bool doesColourEqual = red == green;
	std::cout << "ColourEqual ( should be false or 0 ) : " << doesColourEqual << "\n";

	bool doesUVEqual = emptyUV == emptyUV;
	std::cout << "UVEqual ( should be true or 1 ) : " << doesUVEqual << "\n";
	*/


	std::array< ObjectVertex, 3 > vertexList{ vertexOne, vertexTwo, vertexThree };

	std::cout << "Vertexes: " << vertexList[0] << vertexList[1] << vertexList[2] << "\n";

	testEntity = loadVertexData( testEntity, vertexList, vertexBuffer, indexBuffer );

	//std::cout << "\n" << vertexBuffer.size() << " | " << vertexBuffer << "\n";
	//std::cout << "\n" << indexBuffer.size() << " | " << indexBuffer  << "\n\n";

	/* Testing Transform3D & Model Matrix*/

	//Vector3 movementVector = Vector3( 100, 100, 0 );
	Vector3 scaleVector = Vector3( 4, 1, 1 );

	//std::cout << "transform pre: " << testEntity.transform << "\n";

	//testEntity.transform.setPos( ( testEntity.transform.getPos() + movementVector) );
	testEntity.transform.setScale( ( scaleVector) );

	//std::cout << "transform post: " << testEntity.transform << "\n";
	

	// Debugging

	bool shouldLimitRuns = true;	/**< Should the game only run the loop once? */
	uint64_t totalRunLimit = 1;		/**< Number of runs */

	bool shouldDeactivate = false;		/**< Should the game set a timer to stop after a defined time has elapsed? */
	uint64_t deactivationStopwatch = 0;	/**< (Dont Change Manually!) Current stopwatch time passed */
	uint64_t deactivationTime = secondsPerFrame * 3;	/**< Time to stop the game afterwards in milliseconds. */


	// Main Loop

	bool running = true;

	while ( running ){

		/* FPS Management */
		elapsedFrames += 1;

		previousTime = startTime;
		startTime = SDL_GetTicks();

		deltaTime = startTime - previousTime; /** Time it took last frame to complete */

		std::cout << "FPS: " << (unsigned int)( 1000 / deltaTime ) << "\n";

		/* Poll events */

		SDL_Event event;

		leftMouseButton = MouseButtonEvent::INACTIVE;
		middleMouseButton = MouseButtonEvent::INACTIVE;
		rightMouseButton = MouseButtonEvent::INACTIVE;

		while ( SDL_PollEvent( &event ) ){
			
			switch (event.type){
				
				case SDL_EVENT_QUIT:{
	
					running = false;

					// Wont break immediately to prevent unintended side effects when closing the game
					//break;
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
		
		/* Rendering */

		/*
		viewMatrix = viewMatrix.scale( 
			float( mainCamera.transform.scale[0] ),
			float( mainCamera.transform.scale[1] ),
			float( mainCamera.transform.scale[2] )
		);
		
		viewMatrix = viewMatrix.translate(
			float( mainCamera.transform.position[0] ),
			float( mainCamera.transform.position[1] ),
			float( mainCamera.transform.position[2] )
		);
		*/

		projectionMatrix = calculatePerspectiveProjection( mainCamera.cameraViewVolume );

		// Clears screen with white
		SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
		SDL_RenderClear( renderer );

		// Draws bg
		SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );


		//std::cout << "Rendering Entities...." << "\n";
		renderEntity( 
			testEntity,
			viewMatrix,
			projectionMatrix,
			indexBuffer,
			vertexBuffer,
			renderer,
			renderingSettings
		);


		// Renders display
		SDL_RenderPresent( renderer );
		

		/* FPS Management */

		endTime = SDL_GetTicks();

		// Raw time it took this frame to finish its tasks, before delaying due to the frame cap of `fps`.
		deltaTime = endTime - startTime;

		effectiveFps = 1000 / deltaTime;
		std::cout << "Effective FPS: " << (unsigned int)(effectiveFps) << "\n";

		// Cap FPS
		if ( deltaTime < secondsPerFrame ){

			uint64_t delayTime = secondsPerFrame - deltaTime;
			SDL_Delay( delayTime );
		}	


		/* Auto-Closers */

		if ( shouldDeactivate ){
			
			deactivationStopwatch += deltaTime;

			if ( deactivationStopwatch >= deactivationTime ){
				running = false;
			}
		}
		if( shouldLimitRuns ){

			if ( elapsedFrames >= totalRunLimit ){
				running = false;
			}
		}
		
		// End of while( running ){
	}


	/* Debugging */

	// Prints debug info to the screen
	std::cout << "\n\n" << "---------------| End Data |---------------" << "\n";

	std::cout << "Total Frames: " << elapsedFrames << "\n";

	if (shouldLimitRuns){ std::cout << "Stopped after " << totalRunLimit << " frames, due to shouldLimitRuns" << "\n"; }
	if (shouldDeactivate){ std::cout << "Stopped after " << deactivationTime << "seconds, due to shouldDeactivate" << "\n"; }

	std::cout << "------------------------------------------" << "\n";

	// Closes SDL
	if ( shouldLimitRuns || shouldDeactivate ){
		std::cout << "Press Any Key To Quit SDL... ";
		std::getchar(); 
	}

	SDL_DestroyWindow( window );
	SDL_Quit();

	// Closes Terminal
	std::cout << "Press Any Key To Close The Terminal... ";
	std::getchar(); 

	return 0;
}