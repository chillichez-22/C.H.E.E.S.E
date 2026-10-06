#include "interpolation.hpp"


Vector3 calculateBarycentricCoords( Vector3 point, Tri3D tri ){

    Vector3 AB = tri.points[1] - tri.points[0];
    Vector3 AC = tri.points[2] - tri.points[0];
    
    Vector3 normal = cross( AB, AC ); /**< Tri's normal */

    float area = normal.magnitude() / 2; /**< Area of tri ABC */
    Vector3 parallelogram; /** */

    // BCP
    Vector3 BP = point - tri.points[1]; /** */
    Vector3 BC = tri.points[2] - tri.points[1];

    parallelogram = cross( BC, BP );
    float u = ( parallelogram.magnitude() / 2 ) / area;

    if ( dot( normal, parallelogram ) < 0 ){
        return Vector3();
    }
    
    // CAP
    Vector3 CP = point - tri.points[2]; /** */
    Vector3 CA = tri.points[0] - tri.points[2];

    parallelogram = cross( CA, CP );
    float v = ( parallelogram.magnitude() / 2 ) / area;
    
    if ( dot( normal, parallelogram ) < 0 ){
        return Vector3();
    }

    // ABP
    Vector3 AP = point - tri.points[0]; /** */
    // AB Vector has already been defined.

    parallelogram = cross( AB, AP );
    float w = 1 - u - v; // This is done here to make it faster and more efficient.

    if ( dot( normal, parallelogram ) < 0 ){
        return Vector3();
    }
    
    return Vector3( u, v, w );

}