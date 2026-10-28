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


ColourF ColourF::operator+( ColourF colour ){

    return ColourF{ (r + colour.r)/2.f, (g + colour.g)/2.f, (b + colour.b)/2.f, (a + colour.a)/2.f };
}

ColourF ColourF::operator*( float scale ){
    
    return ColourF{ r * scale, g * scale, b * scale, a * scale };
};


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

ColourI ColourI::operator+( ColourI colour ){

    return ColourI{ uint8_t( (r + colour.r)/2 ), uint8_t( (g + colour.g)/2 ), uint8_t( (b + colour.b)/2 ), uint8_t( (a + colour.a)/2 ) };
}

ColourI ColourI::operator*( float scale ){
    
    return ColourI{ uint8_t(r * scale), uint8_t(g * scale), uint8_t(b * scale), uint8_t(a * scale) };
};
