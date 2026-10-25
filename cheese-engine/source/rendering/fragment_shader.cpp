#include "fragment_shader.hpp"

ColourI fs_drawFragmentBase(

    Vector2& fragUV, 
    Primitive< WorldVertex >& worldPrimitive, 
    Primitive< ScreenVertex >& screenPrimitive 
){

    ColourI colour;

    float w = 1 - fragUV.x - fragUV.y;

    colour = ( worldPrimitive.vertices[0].colour * fragUV.x ) + ( worldPrimitive.vertices[1].colour * fragUV.y ) + ( worldPrimitive.vertices[2].colour * w );

    return colour;

};

Vector2 fs_findScreenCoord(
    Vector2& fragUV, 
    Primitive< ScreenVertex >& screenPrimitive 
){

    int x = int( ( fragUV.x * screenPrimitive.vertices[0].pos.x ) + ( fragUV.y * screenPrimitive.vertices[1].pos.x ) + ( (1 - fragUV.x - fragUV.y) * screenPrimitive.vertices[2].pos.x ) );
    int y = int( ( fragUV.x * screenPrimitive.vertices[0].pos.y ) + ( fragUV.y * screenPrimitive.vertices[1].pos.y ) + ( (1 - fragUV.x - fragUV.y) * screenPrimitive.vertices[2].pos.y ) );
    
    return Vector2( x, y );
}