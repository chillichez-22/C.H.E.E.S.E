#include "rendering/vao.hpp"


// Constructor

VAO::VAO( 
    int attrCount 

):
    m_attrCount( attrCount )
{

    m_cumulativeAttrStrides.resize( m_attrCount + 1, 0.0f );
}


VAO::VAO(  
    int attrCount,
    std::vector< int > attrValueCounts,
    std::vector< GLenum > attrValueTypes

):
    m_attrCount( attrCount ),
    m_attrValueCounts( attrValueCounts ),
    m_attrValueTypes( attrValueTypes )
{
    
    m_cumulativeAttrStrides.resize( m_attrCount + 1, 0.0f );
}


// Initialisation

void VAO::calculateStrides(){

    // Resets m_stride
    m_stride = 0;

    m_cumulativeAttrStrides.resize( m_attrCount + 1, 0.0f );
    m_cumulativeAttrStrides[0] = 0;


    // Calculates m_stride
    for( int i = 0;  i < m_attrCount; i++ ) {

        m_stride += sizeof( GLfloat ) * m_attrValueCounts[i];

        m_cumulativeAttrStrides[i+1] = m_stride;
    }

}


// Getter

unsigned int& VAO::getId(){ 

    return m_ID;  
}

int& VAO::getAttrCount(){ 
    
    return m_attrCount; 
}

std::vector< int > VAO::getAttrValueCounts(){ 
    
    return m_attrValueCounts; 
}

std::vector< GLenum > VAO::getAttrValueTypes(){ 
    
    return m_attrValueTypes; 
}

std::vector< GLsizei > VAO::getCumulativeAttrStrides(){ 
    
    return m_cumulativeAttrStrides; 
}

GLsizei& VAO::getStride(){ 
    
    return m_stride; 
}



// Setter

void VAO::setId( unsigned int id ){ 
    
    m_ID = id; 
}

void VAO::setAttrValueCounts( std::vector< int > attrValueCounts ){ 

    m_attrValueCounts = attrValueCounts;
}

void VAO::setAttrValueTypes( std::vector< GLenum > attrTypes ){ 

    m_attrValueTypes = attrTypes;
}
