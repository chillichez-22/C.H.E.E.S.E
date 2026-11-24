#pragma once

#include <cmath>


#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

float findCFromEOL( float m, float x, float y );

float findXFromEOL( float y, float c, float m );
int findXFromEOL( int y, float c, float m );