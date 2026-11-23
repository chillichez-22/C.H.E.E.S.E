
#include "components/material.hpp"


// Protected
void Material::updateAllMaterialUniforms(){

    m_shader->use();

    m_shader->setVec3(  "albedoColour", Vector3(m_albedoColour) );
    
    m_shader->setVec3(  "diffuseColour", m_diffuseColour );

    m_shader->setVec3(  "specularColour", m_specularColour );
    m_shader->setFloat( "specularPower", m_specularPower );
    m_shader->setFloat( "specularIntensity", m_specularIntensity );

    m_shader->setVec3(  "fresnelColour", m_fresnelColour );
    m_shader->setFloat( "fresnelPower", m_fresnelPower );
    m_shader->setFloat( "fresnelIntensity", m_fresnelIntensity );

    m_shader->setBool( "diffuseTexture.isUsing", m_diffuseTexture.isUsing );
    m_shader->setBool( "specularTexture.isUsing", m_specularTexture.isUsing );   
    m_shader->setBool( "normalTexture.isUsing", m_normalTexture.isUsing );
    
}



// Public

Material::Material(
    Vector4 albedoColour,
    const char* vertexShaderPath,
    const char* fragmentShaderPath,
    std::string name
): 
    m_albedoColour( albedoColour),
    m_name( name )
{
    m_shader = new Shader( vertexShaderPath, fragmentShaderPath );
    updateAllMaterialUniforms();
}

Material::Material(
    Vector4 albedoColour,
    const char* vertexShaderPath,
    const char* fragmentShaderPath,
    float specularPower,
    float specularIntensity,
    Vector3 fresnelColour,
    float fresnelPower,
    float fresnelIntensity,
    std::string name
): 
    m_albedoColour( albedoColour),
    m_specularPower( specularPower ),
    m_specularIntensity( specularIntensity ),
    m_fresnelColour( fresnelColour ),
    m_fresnelPower( fresnelPower ),
    m_fresnelIntensity( fresnelIntensity ),
    m_name( name )
{
    m_shader = new Shader( vertexShaderPath, fragmentShaderPath );
    updateAllMaterialUniforms();
}


Material::~Material(){

    delete(  m_shader );

    // Removes hanging pointers
    m_shader = nullptr;
}


void Material::updateShapeUniforms(
    Matrix4x4<float> modelMatrix, 
    Matrix4x4<float> viewMatrix, 
    Matrix4x4<float> projectionMatrix
){

    // Sets basic matrix only
    m_shader->use();
    m_shader->setMat4( "modelMat", modelMatrix );
	m_shader->setMat4( "viewMat", viewMatrix );
	m_shader->setMat4( "projectionMat", projectionMatrix );

    // Sets textures ( if we need them )
    
    if ( m_diffuseTexture.isUsing ){
        
        glBindTextureUnit( m_diffuseTexture.texUnit, m_diffuseTexture.texID );
    }
    
    if ( m_specularTexture.isUsing ){
        
        glBindTextureUnit( m_specularTexture.texUnit, m_specularTexture.texID );
    }

    if ( m_normalTexture.isUsing ){
    
        glBindTextureUnit( m_normalTexture.texUnit, m_normalTexture.texID );
    }
}


// Setter

void Material::setAlbedo( Vector4 colour ){ 
    
    m_albedoColour = colour;

    m_shader->use();
    m_shader->setVec4( "albedoColour", m_albedoColour );
}

void Material::setDiffuse( Vector3 colour ){ 
    
    m_diffuseColour = colour;

    m_shader->use();
    m_shader->setVec3( "diffuseColour", m_diffuseColour );
}

void Material::setSpecular( Vector3 colour ){ 
    
    m_specularColour = colour;

    m_shader->use();
    m_shader->setVec3( "specularColour", m_specularColour );
}

void Material::setSpecularPower( float power ){ 
    
    m_specularPower = power;

    m_shader->use();

    m_shader->setFloat( "specularPower", m_specularPower );
}

void Material::setSpecularIntensity( float intensity ){ 
    
    m_specularIntensity = intensity;

    m_shader->use();

    m_shader->setFloat( "specularIntensity", m_specularIntensity );
}

void Material::setFresnel( Vector3 colour ){ 
    
    m_fresnelColour = colour;

    m_shader->use();
    m_shader->setVec3( "fresnelColour", m_fresnelColour );
}

void Material::setFresnelPower( float power ){ 
    
    m_fresnelPower = power;

    m_shader->use();

    m_shader->setFloat( "fresnelPower", m_fresnelPower );
}

void Material::setFresnelIntensity( float intensity ){ 
    
    m_fresnelIntensity = intensity;

    m_shader->use();

    m_shader->setFloat( "fresnelIntensity", m_fresnelIntensity );
}


// Textures

void Material::setDiffuseMap( 
    unsigned int textureID, 
    unsigned int textureUnit 
){
    
    m_diffuseTexture.texID = textureID;
    m_diffuseTexture.texUnit = textureUnit;
    m_diffuseTexture.isUsing = true;
    
    m_shader->use();
    m_shader->setBool( "diffuseTexture.isUsing", true );
    m_shader->setInt( "diffuseTexture.map", m_diffuseTexture.texUnit );
}

void Material::setSpecularMap( 
    unsigned int textureID, 
    unsigned int textureUnit 
){
    
    m_specularTexture.texID = textureID;
    m_specularTexture.texUnit = textureUnit;
    m_specularTexture.isUsing = true;
    
    m_shader->use();
    m_shader->setBool( "specularTexture.isUsing", true );
    m_shader->setInt( "specularTexture.map", m_specularTexture.texUnit );
}

void Material::setNormalMap( 
    unsigned int textureID, 
    unsigned int textureUnit 
){

    m_normalTexture.texID = textureID;
    m_normalTexture.texUnit = textureUnit;
    m_normalTexture.isUsing = true;

    m_shader->use();
    m_shader->setBool( "normalTexture.isUsing", true );
    m_shader->setInt( "normalTexture.map", m_normalTexture.texUnit );
}



void Material::clearNormalMap(){

    m_normalTexture.texID = -1;
    m_normalTexture.texUnit = -1;
    m_normalTexture.isUsing = false;

    m_shader->use();
    m_shader->setBool( "normalTexture.isUsing", false );
    m_shader->setInt( "normalTexture.map", -1 );
}

void Material::clearDiffuseMap(){

    m_diffuseTexture.texID = -1;
    m_diffuseTexture.texUnit = -1;
    m_diffuseTexture.isUsing = false;

    m_shader->use();
    m_shader->setBool( "diffuseTexture.isUsing", false );
    m_shader->setInt( "diffuseTexture.map", -1 );
}

void Material::clearSpecularMap(){

    m_specularTexture.texID = -1;
    m_specularTexture.texUnit = -1;
    m_specularTexture.isUsing = false;

    m_shader->use();
    m_shader->setBool( "specularTexture.isUsing", false );
    m_shader->setInt( "specularTexture.map", -1 );
}


// Shader

void Material::setShader( Shader* shader ){ 
    
    m_shader = shader;

    updateAllMaterialUniforms();

}

