#include "vector_test.hpp"

#include <iostream>
#include <SDL3/SDL.h>


bool areVectorsEqual( Vector2 vectorOne, Vector2 vectorTwo ){

    if ( vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y ) return true;

    else return false;
}

bool areVectorsEqual( Vector3 vectorOne, Vector3 vectorTwo ){

    if ( vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y && vectorOne.z == vectorTwo.z ) return true;

    else return false;
}

bool areVectorsEqual( Vector4 vectorOne, Vector4 vectorTwo ){

    if ( vectorOne.x == vectorTwo.x && vectorOne.y == vectorTwo.y && vectorOne.z == vectorTwo.z && vectorOne.w == vectorTwo.w ) return true;

    else return false;
}
