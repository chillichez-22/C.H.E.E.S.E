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

    r = red;
    g = green;
    b = blue;
    a = alpha;
}