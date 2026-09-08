#include "math.hpp"

float findCFromEOL( float m, float x, float y ){

    return y - ( m * x );
}

float findXFromEOL( float y, float c, float m ){

    return ( y - c ) / m;
}

int findXFromEOL( int y, float c, float m ){

    return int( ( y - c ) / m );
}