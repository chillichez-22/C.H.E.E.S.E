#include "projection.hpp"


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

    // Diagonal Scalar
    projectionMatrix.set( 0, 0, ( 2 / ( viewVol.r() - viewVol.l() ) ) );
    projectionMatrix.set( 1, 1, ( 2 / ( viewVol.t() - viewVol.b() ) ) );
    projectionMatrix.set( 2, 3, ( 2 / ( viewVol.f() - viewVol.n() ) ) );

    // W axis offsets
    projectionMatrix.set( 0, 3, -( ( viewVol.r() + viewVol.l() ) / ( viewVol.r() - viewVol.l() ) ) );
    projectionMatrix.set( 1, 3, -( ( viewVol.t() + viewVol.b() ) / ( viewVol.t() - viewVol.b() ) ) );
    projectionMatrix.set( 2, 3, -( ( viewVol.f() + viewVol.n() ) / ( viewVol.f() - viewVol.n() ) ) );

    return projectionMatrix;
};


Matrix4x4<float> calculatePerspectiveProjection(

    Frustum& viewVol
){

    /*
               |                                          |
               | 2n/(r-l),  0,         -(r+l)/(r-l),  0   |
               | 0,         2n/(t-b),  -(t+b)/(t-b),  0   |
    P(pers) =  | 0,         0,         1,             -2n |
               | 0,         0,         1,             0   |
               | 
    */

    Matrix4x4<float> projectionMatrix;

    // Diagonal Scalar
    projectionMatrix.set( 0, 0, ( 2 * viewVol.n() ) / ( viewVol.r() - viewVol.l() ) );
    projectionMatrix.set( 1, 1, ( 2 * viewVol.n() ) / ( viewVol.t() - viewVol.b() ) );
    
    // Z axis offsets
    projectionMatrix.set( 0, 2, -( ( viewVol.r() + viewVol.l() ) / ( viewVol.r() - viewVol.l() ) ) );
    projectionMatrix.set( 1, 2, -( ( viewVol.t() + viewVol.b() ) / ( viewVol.t() - viewVol.b() ) ) );
    projectionMatrix.set( 3, 2, (1.f) );

    // W axis 
    projectionMatrix.set( 2, 3, -( 2 * viewVol.n() ) );
    projectionMatrix.set( 3, 3, (0.f) );

    return projectionMatrix;
};