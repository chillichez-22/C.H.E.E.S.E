#pragma once

#include <cmath>

#include "maths/matrix.hpp"
#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

float findCFromEOL( float m, float x, float y );

float findXFromEOL( float y, float c, float m );
int findXFromEOL( int y, float c, float m );