#include "vector_test.hpp"

#include <iostream>
#include <SDL3/SDL.h>


bool areVectorsEqual( Vector2 vectorOne, Vector2 vectorTwo ){

    if ( vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y ) return true;

    else return false;
}
