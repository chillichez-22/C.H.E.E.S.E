#include "rasteriser.hpp"


Buffer< Vector2 > ra_rasteriseTri( 

    Primitive< ScreenVertex >& screenTri
){

    Buffer< Vector2 > fragmentStream;
    
    // Orders points based on height

    std::array< ScreenVertex, 3 > orderedPoints;

    ra_orderPointsTri( orderedPoints, screenTri.vertices[0], screenTri.vertices[1], screenTri.vertices[2] );

    ScreenVertex top = orderedPoints[0];
    ScreenVertex mid =  orderedPoints[1];
    ScreenVertex low =  orderedPoints[2];


    // Splitting of tris is skipped, if two of the points have the same y value. Since tri has either a flat-top, or flat-bottom.
    if ( top.pos.y == mid.pos.y || mid.pos.y == low.pos.y ){

        Tri2D tri = Tri2D( screenTri.vertices[0].pos, screenTri.vertices[1].pos, screenTri.vertices[2].pos );

        ra_scanTri( fragmentStream, tri );

    }

    else{

        // Splits tri into a two: a flat-top and flat-bottom.

        std::array< Tri2D, 2 > splitTris;
        ra_splitTri( splitTris, top.pos, mid.pos, low.pos ); 


        // Top Tri
        ra_scanTri( fragmentStream, splitTris[0] );

        // Bottom Tri
        ra_scanTri( fragmentStream, splitTris[1] );

    }

    return fragmentStream;

};


void ra_orderPointsTri(

    std::array< ScreenVertex, 3 >& orderedPoints,
    ScreenVertex& zero,
    ScreenVertex& one,
    ScreenVertex& two 
){

    ScreenVertex top = zero;
    ScreenVertex mid = one;
    ScreenVertex low = two;
    
    if ( top.pos.y > low.pos.y ){

        top = two;
        low = zero;
    }

    if ( top.pos.y > mid.pos.y ){

        top = one;
        mid = two;
    }

    if ( mid.pos.y > low.pos.y ){

        mid = zero;
        low = two;
    }

    orderedPoints[0] = top; 
    orderedPoints[1] = mid; 
    orderedPoints[2] = low;

};


void ra_splitTri( 

    std::array< Tri2D, 2 >& splitTris,
    Vector2& top,
    Vector2& mid,
    Vector2& low 
){

    // Calculates the split point

    Line2D line = Line2D( low, top );

    float y = top.y;
    float m = line.lineVector().gradient();
    float x = top.x;
    float c ;

    c = findCFromEOL( m, x, y );

    float splitX;
    splitX = findXFromEOL( mid.y, c, m );

    Vector2 splitPoint = Vector2( splitX, mid.y );


    // Creates the tris
    
    Tri2D triTop;
    Tri2D triLow; 
    
    // Preserves the winding order for the new tris
    if ( mid.x < splitPoint.x ){
        
        triTop = { top, mid, splitPoint };
        triLow = { splitPoint, mid, low };
    }
    else{

        triTop = { top, splitPoint, mid };
        triLow = { mid, splitPoint, low };
    }
    

    splitTris = { triTop, triLow };

};


void ra_scanTri(

    Buffer< Vector2 >& fragmentStream,
    Tri2D& tri
){

    Vector2& top = tri.points[0]; /**< Zero index of the tri's points */
    Vector2& mid = tri.points[1];  /**< One index of the tri's points */
    Vector2& low = tri.points[2];  /**< Two index of the tri's points */
    
    // Creates lines
    Line2D lineLeft;
    Line2D lineRight;
    
    float mLeft;
    float mRight;

    float cLeft;
    float cRight;
    

    // Top-Flat tri
    if ( top.y == mid.y ){

        lineLeft = Line2D( mid, low );
        lineRight = Line2D( low, top );

    }
    // Bottom-Flat tri
    else{

        lineLeft = Line2D( top, mid );
        lineRight = Line2D( low, top );
    }
    

    mLeft = lineLeft.lineVector().gradient();
    mRight = lineRight.lineVector().gradient();

    cLeft = findCFromEOL( mLeft, lineLeft.startPoint.x, lineLeft.startPoint.y );
    cRight = findCFromEOL( mRight, lineRight.startPoint.x, lineRight.startPoint.y );


    int startX;
    int endX;

    // Scans downwards
    for ( int y = top.y; y <= low.y; y++ ){
                
        startX = findXFromEOL( y, cLeft, mLeft );
        endX = findXFromEOL( y, cRight, mRight );

        ra_scanLine(
            fragmentStream,
            startX,
            endX,
            y
        );

    }

};


void ra_scanLine(

    Buffer< Vector2 >& fragmentStream,
    int startX,
    int endX,
    int y 
){

    for ( int x = startX; x <= endX; x++ ){
        
        fragmentStream.push_back( Vector2( x, y ) );
    }

    
};