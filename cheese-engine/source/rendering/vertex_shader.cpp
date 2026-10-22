# include "vertex_shader.hpp"

WorldVertex vs_calculateWorldVertex( 

    const ObjectVertex& vertex, 
    Matrix4x4< float >& modelMatrix, 
    Matrix4x4< float >& viewMatrix
){
    WorldVertex worldVertex;

    worldVertex.normal = vertex.normal;
    worldVertex.uv = vertex.uv;
    worldVertex.colour = vertex.colour;

    worldVertex.pos = viewMatrix.multiplyVector( modelMatrix.multiplyVector( Vector4( vertex.pos ) ) );

    return worldVertex;

};

ScreenVertex vs_calculateScreenVertex( 

    const WorldVertex& vertex, 
    Matrix4x4< float >& projectionMatrix

){
    ScreenVertex screenVertex;
    screenVertex.uv = vertex.uv;

    Vector4 pos = projectionMatrix.multiplyVector( vertex.pos );
    screenVertex.pos = Vector2( pos.x, pos.y );

    return screenVertex;
};