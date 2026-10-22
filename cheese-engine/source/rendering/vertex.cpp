#include "vertex.hpp"

// Object

bool ObjectVertex::operator==( ObjectVertex vertex ){

    if ( pos != vertex.pos ){
        return false;
    }

    if ( normal != vertex.normal){
        return false;
    }
    
    if ( uv != vertex.uv ){
        return false;
    }
    
    if ( colour != vertex.colour ){
        return false;
    }

    return true;
}

bool ObjectVertex::operator!=( ObjectVertex vertex ){

    if ( pos == vertex.pos ){
        return false;
    }

    if ( normal == vertex.normal){
        return false;
    }
    
    if ( uv == vertex.uv ){
        return false;
    }
    
    if ( colour == vertex.colour ){
        return false;
    }

    return true;
}

