#include "ray_3d_collisions.hpp"


RayHit3D collisionRay3DTri3D( Ray3D ray, Tri3D tri ){

    Vector3 AB = tri.points[1] - tri.points[0];
    Vector3 AC = tri.points[2] - tri.points[0];
    
    Vector3 normal = cross( AB, AC ); /**< Tri's normal */

    float normalRayAlignment = dot( normal, ray.direction );

    // Parallel check for the plane and ray
    if ( fabs( normalRayAlignment ) < 1 * powf(10, -8) ){
        return RayHit3D();
    }

    // Back face culling 
    if ( normalRayAlignment > 0 ){
        return RayHit3D();
    }

    float planeConstant = dot( normal, tri.points[0] );
    float t = ( planeConstant - dot( normal, ray.origin ) ) / normalRayAlignment;

    if ( t < 0 ){
        return RayHit3D(); // Tri is behind ray
    }

    Vector3 scaledDirection = ray.direction.scale( t ); 
    Vector3 point = ray.origin.add( scaledDirection ); /**< Intersection point */

    float area = normal.magnitude() / 2; /**< Area of tri ABC */
    Vector3 parallelogram; /** */


    // BCP
    Vector3 BP = point - tri.points[1]; /** */
    Vector3 BC = tri.points[2] - tri.points[1];

    parallelogram = cross( BC, BP );
    float u = ( parallelogram.magnitude() / 2 ) / area;

    if ( dot( normal, parallelogram ) < 0 ){
        return RayHit3D();
    }

    // CAP
    Vector3 CP = point - tri.points[2]; /** */
    Vector3 CA = tri.points[0] - tri.points[2];

    parallelogram = cross( CA, CP );
    float v = ( parallelogram.magnitude() / 2 ) / area;

    if ( dot( normal, parallelogram ) < 0 ){
        return RayHit3D();
    }
    
    // ABP
    Vector3 AP = point - tri.points[0]; /** */
    // AB Vector has alr been done

    parallelogram = cross( AB, AP );
    // Since: w = 1 - u - v; we only need u and v. So w is not calculated now.

    if ( dot( normal, parallelogram ) < 0 ){
        return RayHit3D();
    }

    return RayHit3D(
        point,
        Vector2( u, v ),
        t
    );

}