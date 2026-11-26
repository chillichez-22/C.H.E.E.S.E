
#include "components/mesh.hpp"


// Constructor

Mesh::~Mesh(){


    delete(m_vboPtr);
    m_vboPtr = nullptr;

    delete(m_vaoPtr);
    m_vaoPtr = nullptr;

    delete(m_eboPtr);
    m_eboPtr = nullptr;
}


// Initialiser

void Mesh::bind(){
				
    m_vaoPtr->calculateStrides();


    glCreateBuffers(

        1,		
        &(m_vboPtr->getId())
    );

    glCreateBuffers(

        1,	
        &( m_eboPtr->getId() )
    );

    // Creates and initialises the buffer objects data
    glNamedBufferStorage(

        m_vboPtr->getId(),									 
        sizeof( float ) * m_vboPtr->getVertexData()->size(),    
        m_vboPtr->getVertexData()->data(),                  
        GL_DYNAMIC_STORAGE_BIT  // Makes the buffer mutable
    );
    glNamedBufferStorage(

        m_eboPtr->getId(),
        sizeof( unsigned int ) * m_eboPtr->getIndexData()->size(),
        m_eboPtr->getIndexData()->data(),
        GL_DYNAMIC_STORAGE_BIT  // Makes the buffer mutable
    );


    glCreateVertexArrays(

        1,		
        &(m_vaoPtr->getId())
    );

    // Binds the buffers to the VAO
    glVertexArrayVertexBuffer(

        (m_vaoPtr->getId()),
        0,		                    // Index of the binding point
        m_vboPtr->getId(),	
        0,		                    // Offset to first index
        m_vaoPtr->getStride()
    );
    glVertexArrayElementBuffer(

        m_vaoPtr->getId(),
        m_eboPtr->getId()
    );


    for (int i = 0;  i < m_vaoPtr->getAttrCount(); i++) {

        // Enables atrributes
        glEnableVertexArrayAttrib(

            m_vaoPtr->getId(),
            i
        );


        // Formats atrributes
        glVertexArrayAttribFormat(

            m_vaoPtr->getId(),
            i,
            m_vaoPtr->getAttrValueCounts()[i],
            m_vaoPtr->getAttrTypes()[i],
            GL_FALSE,	// Should the data be normalised to fixed point when they are accessed
            m_vaoPtr->getCumulativeAttrStrides()[i]	// Relative offset to the start of the vertexes ( There for we do i-1 )
        );

        // Binds Attributes
        glVertexArrayAttribBinding(

            m_vaoPtr->getId(),
            i,
            0	// Binding index
        );
    }

} 


// Getter

VBO*& Mesh::getVbo(){

    return m_vboPtr;
}

VAO*& Mesh::getVao(){

    return m_vaoPtr;
}

EBO*& Mesh::getEbo(){

    return m_eboPtr;
}

GLenum& Mesh::getRenderMode(){

    return m_renderMode;
}


// Setter

void Mesh::setRenderMode( GLenum mode ){

    m_renderMode = mode;
};

