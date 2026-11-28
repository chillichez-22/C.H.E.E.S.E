
#include "components/mesh.hpp"


// Constructor

Mesh::Mesh(
    std::vector<float> vertexData,
    std::vector<int> indexData,

    int attributeCount,
    std::vector<int> countsOfAttributes,
    std::vector<GLenum> typesOfAttributes,

    int indexOffset,
    int vertexOffset
){

    bind(    
        vertexData,
        indexData,
        attributeCount,
        countsOfAttributes,
        typesOfAttributes
    );

}


Mesh::~Mesh(){}


// Initialiser


std::vector< int > Mesh::calculateStrides(

    int attributeCount,
    std::vector<int> attributeValueCounts
){

    int stride = 0;
    std::vector<int> cumulativeStride = {};

    cumulativeStride.resize( attributeCount + 1, 0.0f );
    cumulativeStride[0] = 0;

    // Calculates stride
    for( int i = 0;  i < attributeCount; i++ ) {

        // Every value in the vertex data is a float
        stride += sizeof( float ) * attributeValueCounts[i];

        cumulativeStride[i+1] = stride;
    }

    return cumulativeStride;
}




void Mesh::bind(

    std::vector<float> vertexData,
    std::vector<int> indexData,

    int attributeCount,
    std::vector<int> countsOfAttributes,
    std::vector<GLenum> typesOfAttributes,

    int indexOffset,
    int vertexOffset
){
				
    std::vector<int> offsetStrides = calculateStrides( 
        attributeCount, 
        countsOfAttributes 
    );
    int stride = offsetStrides.back();


    glCreateBuffers(

        1,      // Number of buffers to create
        &m_vbo
    );

    glCreateBuffers(

        1,	
        &m_ebo 
    );

    glCreateVertexArrays(   // If something breaks move this below

        1,		
        &m_vao
    );

    // Creates and initialises the buffer objects data
    glNamedBufferStorage(

        m_vbo,									 
        sizeof( float ) * vertexData.size(),    
        vertexData.data(),                  
        GL_DYNAMIC_STORAGE_BIT  // Makes the buffer mutable
    );
    glNamedBufferStorage(

        m_ebo,
        sizeof( unsigned int ) * indexData.size(),
        indexData.data(),
        GL_DYNAMIC_STORAGE_BIT  // Makes the buffer mutable
    );



    // Binds the buffers to the VAO
    glVertexArrayVertexBuffer(

        m_vao,
        0,      // Index of the binding point
        m_vbo,
        0,		// Offset to first index
        stride
    );
    glVertexArrayElementBuffer(

        m_vao,
        m_ebo
    );

    // Atrributes
    for (int i = 0;  i < attributeCount; i++) {

        glEnableVertexArrayAttrib(

            m_vao,
            i
        );

        // Formats
        glVertexArrayAttribFormat(

            m_vao,
            i,
            countsOfAttributes[i],
            typesOfAttributes[i],
            GL_FALSE,	        // Should the data be normalised to a fixed point when they are accessed
            offsetStrides[i]	    // Relative offset to the start of the vertexes ( There for we do i-1 )
        );

        // Binds
        glVertexArrayAttribBinding(

            m_vao,
            i,  
            0	// Binding index
        );
    }


} 


// Getter


GLenum& Mesh::getRenderMode(){

    return m_renderMode;
}


// Setter

void Mesh::setRenderMode( GLenum mode ){

    m_renderMode = mode;
};

