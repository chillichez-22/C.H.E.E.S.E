#include "loading.hpp"

int32_t checkIfVertexInList( 
    Buffer< ObjectVertex > vertexVec, 
    Buffer< uint32_t > indexVec, 
    ObjectVertex checkVertex 
){

    for( uint32_t i = 0; i < vertexVec.size(); i++ ){

        if ( vertexVec[i] == checkVertex ){
            
            // Returns the `indexVec[i]` because we cannot assume that `i` starts at 0
            // e.g: If using a cache of 4 consecutive points, the indexes may be 4,5,6,7;
            // however the `vertexVec` index will always start at 0 and be 0,1,2,3. 
            return indexVec[i];
        }

    }

    return -1;
}
