#include "vertex.hpp"

// Vertex2D

Vertex2D::Vertex2D(){};

Vertex2D::Vertex2D( Vector2 posCoord, Vector2 uvCoord, ColourI colourValue ){

    pos = posCoord;
    uv = uvCoord;
    colour = colourValue;

};
 

// Vertex3D

Vertex3D::Vertex3D(){};

Vertex3D::Vertex3D( Vector3 posCoord, Vector3 normalVec, Vector2 uvCoord, ColourI colourValue ){

    pos = posCoord;
    normal = normalVec;
    uv = uvCoord;
    colour = colourValue;

};


// VertexBuffer

int vertexBuffer2D::count(){

    return buffer.size();
};

int vertexBuffer3D::count(){

    return buffer.size();
};