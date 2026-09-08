#pragma once

// Own Scope
#include "matrix.hpp"
#include "vector_2.hpp"
#include "vector_3.hpp"
#include "vector_4.hpp"

// External
#include <cmath>

float findCFromEOL( float m, float x, float y );

float findXFromEOL( float y, float c, float m );
int findXFromEOL( int y, float c, float m );