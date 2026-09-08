#include "tri_rasteriser.hpp"

#include <stdexcept>

void RasteriseTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourI& solidColour ){

    /*std::cerr << "| Running tri rasteriser" << "\n";*/
    
    Vector2& zero = tri.points[0]; /**< Zero index of the tri's points */
    Vector2& one = tri.points[1];  /**< One index of the tri's points */
    Vector2& two = tri.points[2];  /**< Two index of the tri's points */
    
    /*
    std::cerr << "Zero: [" << zero.x << ", " << zero.y << "] \n";
    std::cerr <<  "One: [" << one.x << ", " << one.y << "] \n";
    std::cerr <<  "Two: [" << two.x << ", " << two.y << "] \n\n";
    */

    // Step 1

    // Since two of the points have the same y value. The tri has either a flat top, or flat bottom.
    // Therefore doesnt need to be split, and can skips steps: 3, 4
    if ( zero.y == one.y || one.y == two.y ){

        // Step 4B
        scanTri( renderer, tri, solidColour );

    }

    else{

        // Step 2 & 3

        std::array< Tri2D, 2 > splitTris;
        SplitTri( splitTris, zero, one, two ); 

        // Step 4A
        for ( Tri2D* newTri = splitTris.begin(); newTri != splitTris.end(); ++newTri ){

            std::cerr << "New Tri " << "\n";
            scanTri( renderer, *newTri, solidColour );
            
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
    Vector2 mid = one;
    Vector2 low = two;
    
    if ( top.y > low.y ){

        top = two;
        low = zero;
    }

    if ( top.y > mid.y ){

        top = one;
        mid = two;
    }

    if ( mid.y > low.y ){

        mid = zero;
        low = two;
    }

    orderedPoints[0] = top; 
    orderedPoints[1] = mid; 
    orderedPoints[2] = low;

}


void SplitTri( 
    std::array< Tri2D, 2 >& splitTris,
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
    
    Tri2D triTop;
    Tri2D triLow; 
    
    // Preserves the winding order
    if ( mid.x < splitPoint.x ){
        
        triTop = Tri2D( top, mid, splitPoint );
        triLow = Tri2D( splitPoint, mid, low );
    }
    else{

        triTop = Tri2D( top, splitPoint, mid );
        triLow = Tri2D( mid, splitPoint, low );
    }
    

    splitTris = { triTop, triLow };

}

void scanTri( 
    SDL_Renderer* renderer,
    Tri2D& tri, 
    ColourI& solidColour ){

    /*std::cerr << "|  Scanning tris" << "\n";*/

    SDL_SetRenderDrawColor( renderer, solidColour.r, solidColour.g, solidColour.b, solidColour.a );

    Vector2& zero = tri.points[0]; /**< Zero index of the tri's points */
    Vector2& one = tri.points[1];  /**< One index of the tri's points */
    Vector2& two = tri.points[2];  /**< Two index of the tri's points */
    
    // Creates lines
    Line2D lineLeft;
    Line2D lineRight;
    
    float mLeft;
    float mRight;

    float cLeft;
    float cRight;
    
    /**
     * Zero is always the highest point.
     * Two is always the lowest point.
     * 
     * On top-flat tris: 
     * - Zero or One is the top point. 
     * - Two is the low point.
     *  
     *      1---------[0]^
     *       \       /
     *        \     /
     *         \   /
     *          \ /
     *          [2]v
     * 
     * 
     * On bottom-flat tris:
     * - Zero is the top point
     * - Two or One is the low point.
     * 
     *           [0]^
     *           / \
     *          /   \
     *         /     \
     *        /       \
     *       1--------[2]v
     * 
     */

    // Top-Flat tri
    if ( zero.y == one.y ){

        lineLeft = Line2D( one, two );
        lineRight = Line2D( two, zero );

    }
    // Bottom-Flat tri
    else{

        lineLeft = Line2D( zero, one );
        lineRight = Line2D( two, zero );
    }
    

    mLeft = lineLeft.lineVector().gradient();
    mRight = lineRight.lineVector().gradient();

    cLeft = findCFromEOL( mLeft, lineLeft.startPoint.x, lineLeft.startPoint.y );
    cRight = findCFromEOL( mRight, lineRight.startPoint.x, lineRight.startPoint.y );


    int startX;
    int endX;

    /*std::cerr << "|    Axis:" << "\n";*/

    for ( int y = zero.y; y <= two.y; y++ ){
        
        
        /*std::cerr << "|    Y: [" << y << "]" << "\n";*/
        
        startX = findXFromEOL( y, cLeft, mLeft );
        endX = findXFromEOL( y, cRight, mRight );


        scanLine(
            renderer,
            startX,
            endX,
            y
        );

    }

}

void scanLine( 
    SDL_Renderer* renderer,
    int startX,
    int endX,
    int y ){
    
    int difference = endX - startX;

    /*
    std::cerr << "|    | End: [" << endX << "]" << "\n";
    std::cerr << "|    | Start: [" << startX << "]" << "\n";
    std::cerr << "|    | Diff: [" << difference << "]" << "\n";
    */

    std::vector< SDL_FPoint > points( difference );

    for ( int x = startX; x <= endX; x++ ){
        
        /*std::cerr << "[" << x << "], ";*/

        points.push_back( SDL_FPoint( x, y ) );
    }


    bool worked;
    worked = SDL_RenderPoints( renderer, points.data(), points.size() );

    if ( !worked ){
        std::cerr << "Failed to render the tri! " << "\n";
        SDL_GetError();

        throw std::logic_error("Failed to render a tri using `SDL_RenderPoints!");
        
    }

}