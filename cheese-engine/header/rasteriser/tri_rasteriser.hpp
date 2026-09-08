#pragma once

// External
#include <string>
#include <iostream>
#include <vector>
#include <cstddef>
#include <SDL3/SDL.h>

// Outside Scope
#include "tri_2d.hpp"
#include "colour.hpp"
#include "line_2d.hpp"
#include "math.hpp"



void RasteriseTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourF& solidColour );

void orderPoints(
    std::array< Vector2, 3 >& orderedPoints,
    Vector2& zero,
    Vector2& one,
    Vector2& two );

void SplitTri( 
    std::array< Tri2D, 2 >& splitTris,
    Tri2D& tri, 
    Vector2& top,
    Vector2& mid,
    Vector2& low );

void scanTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourF& solidColour );

void scanLine( 
    SDL_Renderer* renderer,
    int startX,
    int endX,
    int y,
    ColourF& solidColour );