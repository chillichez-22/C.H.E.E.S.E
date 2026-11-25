#include "rendering/projection.hpp"


Matrix4x4<float> calculateOrthoProjection(

    Frustum& viewVol
){

    /*
               |                                            |
               | 2/(r-l),  0,        0,        -(r+l)/(r-l) |
               | 0,        2/(t-b),  0,        -(t+b)/(t-b) |
    P(ortho) = | 0,        0,        2/(f-n),  -(f+n)/(f-n) |
               | 0,        0,        0,        1            |
               | 
    */

    Matrix4x4<float> projectionMatrix;

    float l = viewVol.l();
    float r = viewVol.r();
    float t = viewVol.t();
    float b = viewVol.b();
    float n = viewVol.n();
    float f = viewVol.f();

    // Diagonal Scalar
    projectionMatrix.set( 0, 0, ( 2 / ( r - l ) ) );
    projectionMatrix.set( 1, 1, ( 2 / ( t - b ) ) );
    projectionMatrix.set( 2, 3, ( 2 / ( f - n ) ) );

    // W axis offsets
    projectionMatrix.set( 0, 3, -( ( r + l ) / ( r - l ) ) );
    projectionMatrix.set( 1, 3, -( ( t + b ) / ( t - b ) ) );
    projectionMatrix.set( 2, 3, -( ( f + n ) / ( f - n ) ) );

    return projectionMatrix;
};


Matrix4x4<float> calculatePerspectiveProjection(

    Frustum& viewVol
){

    /*
               |                                                    |
               | c/a,      0,        0,              0              |
               | 0,        c,        0,              -(2*f*n)/(f-n) |
    P(persp) = | 0,        0,        -(f+n)/(f-n),   1              |
               | 0,        0,        -1,             0              |
               | 
    */

    Matrix4x4<float> projectionMatrix;


    float c = 1.0 / tan( viewVol.getFov() / 2 );
    float a = viewVol.getAspectRatio();
    float f = viewVol.f();
    float n = viewVol.n();

    // Diagonal Scalar
    projectionMatrix.set( 0, 0, c / a );
    projectionMatrix.set( 1, 1, c );
    
    // Z axis offsets
    projectionMatrix.set( 1, 3, -((2.f * f * n ) / ( f - n )) );
    projectionMatrix.set( 2, 2, -(( f + n ) / ( f - n )) );
    projectionMatrix.set( 2, 3, 1.f );

    // W axis 
    projectionMatrix.set( 3, 2, -1.f );
    projectionMatrix.set( 3, 3, 0.f );

    return projectionMatrix;
};