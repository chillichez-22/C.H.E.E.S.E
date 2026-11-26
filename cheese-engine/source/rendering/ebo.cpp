#include "rendering/ebo.hpp"

// Constructors

EBO::EBO(

    std::vector< unsigned int > indexData,
    unsigned int indexOffset,
    unsigned int vertexOffset
):
    m_indexDataPtr( new std::vector<unsigned int>{ indexData } ),
    m_indexOffset( indexOffset ),
    m_vertexOffset( vertexOffset )
{

}


EBO::EBO(

    std::vector< unsigned int >* indexDataPtr,
    unsigned int indexOffset,
    unsigned int vertexOffset
):
    m_indexDataPtr( indexDataPtr ),
    m_indexOffset( indexOffset ),
    m_vertexOffset( vertexOffset )
{

}

EBO::~EBO(){

    delete( m_indexDataPtr );
    m_indexDataPtr = nullptr;

};

// Getters

unsigned int& EBO::getId(){ 

    return m_ID;  
}

std::vector< unsigned int >*& EBO::getIndexData(){ 
    
    return m_indexDataPtr;  
}

unsigned int& EBO::getIndexOffset(){ 
    
    return m_indexOffset;  
}

unsigned int& EBO::getVertexOffset(){ 
    
    return m_vertexOffset;  
}


// Setters

void EBO::setId( unsigned int id ){ 
    
    m_ID = id; 
}

void EBO::setIndexData( std::vector< unsigned int >* indexDataPtr ){

    m_indexDataPtr = indexDataPtr; 
};


void EBO::setIndexData( std::vector< unsigned int > indexData ){ 
    
    m_indexDataPtr = new std::vector< unsigned int >{ indexData }; 
}



void EBO::setIndexOffset( unsigned int offset ){ 
    
    m_indexOffset = offset; 
}

void EBO::setVertexOffset( unsigned int offset ){ 
    
    m_vertexOffset = offset; 
}
