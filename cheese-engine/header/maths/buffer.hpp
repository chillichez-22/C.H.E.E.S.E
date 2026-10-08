#pragma once

#include <cstdint>
#include <vector>

template <typename bufferType>
struct buffer{

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
    uint32_t& push_back( bufferType item );


    /**
     * @brief Returns the amount of items in the buffer.
     * 
     * @returns `uint32_t` Number of items in the buffer.
     */
    uint32_t& size( );

    /**
     * @brief Returns an item from the buffer, at the `index`.
     * 
     * @param index A unsigned 32-bit integer, of the index to return.
     * 
     * @returns `bufferType` Item at the `index`.
     */
    bufferType& operator[]( uint32_t index );

};