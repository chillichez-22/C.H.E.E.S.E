#include "buffer.hpp"

#include <cstdint>

template <typename bufferType>
uint32_t& buffer<bufferType>::push_back( bufferType item ){

    data.push_back( item );

    return &uint32_t( data.end() );
}

template <typename bufferType>
uint32_t& buffer<bufferType>::size(){

    return &uint32_t( data.size() );
}

template <typename bufferType>
bufferType& buffer<bufferType>::operator[]( uint32_t index ){
    
    return &( data[ index ] );
}

