
#include "rendering/vbo.hpp"


// Constructor

VBO::VBO(
    std::vector< float >* vertexDataPtr,
    unsigned int id = 0
): 
    m_vertexDataPtr( vertexDataPtr ),
    m_ID( id )
{

}
VBO::VBO(
    std::vector< float > vertexData,
    unsigned int id = 0
): 
    m_vertexDataPtr( new std::vector<float>{vertexData} ),
    m_ID( id )
{

}


VBO::~VBO(){

    delete( m_vertexDataPtr );
    m_vertexDataPtr = nullptr;
}


// Getters

unsigned int& VBO::getId(){ 

    return m_ID;  
}

std::vector< float >*& VBO::getVertexData(){

    return m_vertexDataPtr;
};

// Setters

void VBO::setId( unsigned int id ){ 
    
    m_ID = id; 
}

void VBO::setVertexData( std::vector<float>* vertexDataPtr ){

    m_vertexDataPtr = vertexDataPtr;
};

void VBO::setVertexData( std::vector<float> vertexData ){

    m_vertexDataPtr = new std::vector< float >{ vertexData };
};