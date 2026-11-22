#pragma once

// External
#include <cmath>

#include "maths/matrix.hpp"
#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"


float findCFromEOL( float m, float x, float y );

float findXFromEOL( float y, float c, float m );
int findXFromEOL( int y, float c, float m );