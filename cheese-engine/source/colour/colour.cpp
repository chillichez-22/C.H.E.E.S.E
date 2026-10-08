#include "colour.hpp"


// ColourF

ColourF::ColourF(){};

ColourF::ColourF( float red, float green, float blue, float alpha ){

    r = red;
    g = green;
    b = blue;
    a = alpha;
}


// ColourI

ColourI::ColourI(){};

ColourI::ColourI( int red, int green, int blue, int alpha ){

    r = uint8_t(red);
    g = uint8_t(green);
    b = uint8_t(blue);
    a = uint8_t(alpha);
}