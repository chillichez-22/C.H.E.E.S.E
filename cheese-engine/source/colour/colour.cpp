#include "colour.hpp"


// ColourF

ColourF::ColourF(){};

ColourF::ColourF( float red, float green, float blue, float alpha ){

    r = red;
    g = green;
    b = blue;
    a = alpha;
}


bool ColourF::operator==( ColourF colour ){

    if ( r != colour.r ){
        return false;
    }

    if ( g != colour.g ){
        return false;
    }

    if ( b != colour.b ){
        return false;
    }

    if ( a != colour.a ){
        return false;
    }

    return true;
}

bool ColourF::operator!=( ColourF colour ){

    if ( r == colour.r ){
        return false;
    }

    if ( g == colour.g ){
        return false;
    }

    if ( b == colour.b ){
        return false;
    }

    if ( a == colour.a ){
        return false;
    }

    return true;
}


// ColourI

ColourI::ColourI(){};

ColourI::ColourI( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha ){

    r = uint8_t(red);
    g = uint8_t(green);
    b = uint8_t(blue);
    a = uint8_t(alpha);
}

bool ColourI::operator==( ColourI colour ){

    if ( r != colour.r ){
        return false;
    }

    if ( g != colour.g ){
        return false;
    }

    if ( b != colour.b ){
        return false;
    }

    if ( a != colour.a ){
        return false;
    }

    return true;
}

bool ColourI::operator!=( ColourI colour ){

    if ( r == colour.r ){
        return false;
    }

    if ( g == colour.g ){
        return false;
    }

    if ( b == colour.b ){
        return false;
    }

    if ( a == colour.a ){
        return false;
    }

    return true;
}