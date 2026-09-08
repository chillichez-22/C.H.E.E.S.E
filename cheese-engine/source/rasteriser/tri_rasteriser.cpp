#include "tri_rasteriser.hpp"


void RasteriseTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourF& solidColour ){

    std::cerr << "| Running tri rasteriser" << "\n";
    
    Vector2& zero = tri.points[0]; /**< Zero index of the tri's points */
    Vector2& one = tri.points[1];  /**< One index of the tri's points */
    Vector2& two = tri.points[2];  /**< Two index of the tri's points */

    std::cerr << "|  Zero: [" << zero.x << ", " << zero.y << "]"<< "\n";
    std::cerr <<  "|  One: [" << one.x << ", " << one.y << "]"<< "\n";
    std::cerr <<  "|  Two: [" << two.x << ", " << two.y << "]"<< "\n";
    
    // Step 1 
    
    std::array< Vector2, 3 > orderedPoints;
    orderPoints( orderedPoints, zero, one, two );
    
    Vector2& top = orderedPoints[0];
    Vector2& mid = orderedPoints[1];
    Vector2& low = orderedPoints[2];
    
    std::cerr << "|  | Ordered " << "\n";
    std::cerr << "|  Top: [" << top.x << ", " << top.y << "]"<< "\n";
    std::cerr << "|  Mid: [" << mid.x << ", " << mid.y << "]"<< "\n";
    std::cerr << "|  Low: [" << low.x << ", " << low.y << "]"<< "\n";

    // Step 2
    // Since two of the points have the same y value. The tri has either a flat top, or flat bottom.
    // Therefore doesnt need to be split, and can skips steps: 3, 4
    if ( zero.y == one.y || one.y == two.y ){

         std::cerr << "|  | Skipping Split" << "\n";

        // Step 5B
        scanTri( renderer, tri, solidColour );
        std::cerr << "------Ended------------" << "\n";
    }

    // Initially assumes we can skip: Step 3, 4
    // This helps with code flow as we are not going back and forth between the steps.
    else{

        std::cerr << "|  | Splitting Tris" << "\n";

        // Step 3 & 4

        std::array< Tri2D, 2 > splitTris;
        SplitTri( splitTris, tri, top, mid, low ); /** < Check this actually returns a value, and not none. */

        // Step 5A
        for ( Tri2D* newTri = splitTris.begin(); newTri != splitTris.end(); ++newTri ){

            scanTri( renderer, *newTri, solidColour );
            std::cerr << "------Ended------------" << "\n";
        }

    }

};

void orderPoints(
    std::array< Vector2, 3 >& orderedPoints,
    Vector2& zero,
    Vector2& one,
    Vector2& two ){

    // Step 1 

    Vector2 top = zero;
    Vector2 mid = zero;
    Vector2 low = zero;
    
    // Writing the if statement twice saves on storing the two points in memory, 
    // and for looping over said list, like previously written to do. 
    // However the compiler probably makes this faster anyway...

    if ( one.y < top.y ){

        top = one;
    }
    else if ( one.y > low.y ){

        low = one;
    }
    else{

        mid = one;
    }
    
    if ( two.y < top.y ){

        top = two;
    }
    else if ( two.y > low.y ){

        low = two;
    }
    else{

        mid = two;
    }

    orderedPoints[0] = top; 
    orderedPoints[1] = mid; 
    orderedPoints[2] = low;

}


void SplitTri( 
    std::array< Tri2D, 2 >& splitTris,
    Tri2D& tri, 
    Vector2& top,
    Vector2& mid,
    Vector2& low ){
    
    // Step 3

    Line2D line = Line2D( low, top );

    float y = top.y;
    float m = line.lineVector().gradient();
    float x = top.x;
    float c ;

    c = findCFromEOL( m, x, y );

    float splitX;
    splitX = findXFromEOL( mid.y, c, m );

    Vector2 splitPoint = Vector2( splitX, mid.y );

    // Step 4

    Tri2D triTop = Tri2D( top, mid, splitPoint );
    Tri2D triLow = Tri2D( mid, low, splitPoint );

    splitTris = { triTop, triLow };

}

void scanTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourF& solidColour ){

    std::cerr << "|  Scanning tris" << "\n";

    // Orders
    std::array< Vector2, 3 > orderedPoints;

    orderPoints( orderedPoints, tri.points[0], tri.points[1], tri.points[2] );

    Vector2& top = orderedPoints[0];
    Vector2& mid = orderedPoints[1];
    Vector2& low = orderedPoints[2];    

    std::cerr << "|  Top: [" << top.x << ", " << top.y << "]"<< "\n";
    std::cerr << "|  Mid: [" << mid.x << ", " << mid.y << "]"<< "\n";
    std::cerr << "|  Low: [" << low.x << ", " << low.y << "]"<< "\n";
    
    // Creates lines
    Line2D lineLeft;
    Line2D lineRight;
    
    float mLeft;
    float mRight;

    float cLeft;
    float cRight;
    
    // Top-Flat tri
    if ( top.y == mid.y ){

        lineLeft = Line2D( top, low );
        lineRight = Line2D( low, mid );

    }
    // Bottom-Flat tri
    else{

        /** NOTE: Swapped these two around */
        lineLeft = Line2D( low, top ); 
        lineRight = Line2D( top, mid );
    }

    mLeft = lineLeft.lineVector().gradient();
    mRight = lineRight.lineVector().gradient();

    cLeft = findCFromEOL( mLeft, lineLeft.startPoint.x, lineLeft.startPoint.y );
    cRight = findCFromEOL( mRight, lineRight.startPoint.x, lineRight.startPoint.y );


    int startX;
    int endX;

    std::cerr << "|    Axis:" << "\n";

    for ( int y = top.y; y <= low.y; y++ ){
        
        
        std::cerr << "|    Y: [" << y << "]" << "\n";
        
        startX = findXFromEOL( y, cLeft, mLeft );
        endX = findXFromEOL( y, cRight, mRight );


        scanLine(
            renderer,
            startX,
            endX,
            y,
            solidColour
        );

    }

}

void scanLine( 
    SDL_Renderer* renderer,
    int startX,
    int endX,
    int y,
    ColourF& solidColour ){
    
    int difference = endX - startX;
    std::cerr << "|    | End: [" << endX << "]" << "\n";
    std::cerr << "|    | Start: [" << startX << "]" << "\n";
    std::cerr << "|    | Diff: [" << difference << "]" << "\n";

    std::vector< SDL_FPoint > points( difference );
    
    //std::cerr << "|    | StartX: [" << startX << "]"<< "\n";

    for ( int x = startX; x <= endX; x++ ){
        
        //std::cerr << "|    | X: [" << x << "]"<< "\n";

        points.push_back( SDL_FPoint( x, y ) );
    }

    //std::cerr << "|    EndX: [" << endX << "]"<< "\n";

    SDL_RenderPoints( renderer, points.data(), difference );


}