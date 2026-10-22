#pragma once

#include <cstdint>
#include <vector>

template <typename bufferType>
struct Buffer{

private:
    
    std::vector< bufferType > data; /**< */

public:


    /**
     * @brief Adds to the buffer, and returns the index where it was placed.
     * 
     * @param item An item to add to the buffer.
     * 
     * @returns `uint32_t` Index at which the `item` was placed.
     */
    uint32_t push_back( bufferType item ){

        data.push_back( item );

        uint32_t end = size() - 1;

        return end;
    }

    /**
     * @brief Combines another buffer to this, and places it at the end.
     * 
     * @param buffer Buffer of the same type, to combine into this.
     * 
     * @returns `uint32_t` Index where the buffer was combined.
     */
    uint32_t push_back( Buffer< bufferType > buffer ){

        uint32_t startPoint = size();

        for ( uint32_t i = 0; i < buffer.size(); i++ ){

            data.push_back( buffer[i] );
        }

        return startPoint;
    }


    /**
     * @brief Returns the amount of items in the buffer.
     * 
     * @returns `uint32_t` Number of items in the buffer.
     */
    uint32_t size(){

        uint32_t size = uint32_t( data.size() );
        return size;
    }


    /**
     * @brief Returns an item from the buffer, at the `index`.
     * 
     * @param index A unsigned 32-bit integer, of the index to return.
     * 
     * @returns `bufferType` Item at the `index`.
     */
    bufferType& operator[]( uint32_t index ){
        
        return data[ index ];
    }



};