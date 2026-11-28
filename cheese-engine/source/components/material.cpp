
#include "components/material.hpp"
#include "files/texture_manager.hpp"


// Constructor

Material::Material(

    std::string vertexShaderPath,
    std::string fragmentShaderPath,
    
    TextureManager& textureManger,
    std::string diffuseTexturePath,
    std::string specularTexturePath,
    std::string normalTexturePath,

    std::string name
):
    m_name( name )
{
    m_shader = new Shader( vertexShaderPath, fragmentShaderPath );


    m_textures[ DIFFUSE_TEXTURE ] = textureManger.addTexture( diffuseTexturePath.c_str() )->unit;
    m_textures[ SPECULAR_TEXTURE ] = textureManger.addTexture( specularTexturePath.c_str() )->unit;
    m_textures[ NORMAL_TEXTURE ] = textureManger.addTexture( normalTexturePath.c_str() )->unit;


    updateAllMaterialUniforms();
}


Material::Material(

    std::string vertexShaderPath,
    std::string fragmentShaderPath,

    Vector4 albedoColour,
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



// Initialisers


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

    for( int t = 0; t < m_textures.size(); t++ ){

        m_shader->setBool( ("textures[" + std::to_string(t) + "].isUsing"), (m_textures[ t ] != -1) );
        m_shader->setBool( ("textures[" + std::to_string(t) + "].map"), m_textures[ t ] );
    }
    
}


void Material::updateUniforms(
    Matrix4x4<float> modelMatrix, 
    Matrix4x4<float> viewMatrix, 
    Matrix4x4<float> projectionMatrix,
    TextureManager& textureManager
){

    m_shader->use();

    // Sets basic matrix 
    m_shader->setMat4( "modelMat", modelMatrix );
	m_shader->setMat4( "viewMat", viewMatrix );
	m_shader->setMat4( "projectionMat", projectionMatrix );


    // Sets textures ( if we need them )
    for ( int t = 0; t < m_textures.size(); t++ ){

        if ( (m_textures[ t ] != -1) ){
            
            Texture* tempTexture = textureManager.getTexture( m_textures[ t ] );

            glBindTextureUnit( tempTexture->unit, tempTexture->id );

        }
    }
    
}


// Getters

std::string& Material::getName(){ 
    
    return m_name; 
}

unsigned int& Material::getID(){ 
    
    return m_ID; 
}


Vector4& Material::getAlbedo(){ 
    
    return m_albedoColour; 
}


Vector3& Material::getDiffuse(){ 
    
    return m_diffuseColour; 
}


Vector3& Material::getSpecular(){ 
    
    return m_specularColour; 
}

float& Material::getSpecularPower(){ 
    
    return m_specularPower; 
}

float& Material::getSpecularIntensity(){ 
    
    return m_specularIntensity; 
}


Vector3& Material::getFresnel(){ 
    
    return m_fresnelColour; 
}

float& Material::getFresnelPower(){ 
    
    return m_fresnelPower; 
}

float& Material::getFresnelIntensity(){ 
    
    return m_fresnelIntensity; 
}


int& Material::getTexture( int textureIndex ){

    return m_textures[textureIndex]; 
}


Shader*& Material::getShader(){ 
    
    return m_shader; 
}



// Setters

void Material::setName( std::string name ){ 
    
    m_name = name; 
}

void Material::setID( unsigned int id ){ 
    
    m_ID = id; 
}

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

void Material::setTexture( 

    int textureIndex, 
    unsigned int textureUnit
){
    
    m_textures[ textureIndex ] = textureUnit;

    
    m_shader->use();
    m_shader->setBool( ("textures[" + std::to_string( textureIndex ) + "].isUsing"), true );
    m_shader->setBool( ("textures[" + std::to_string( textureIndex ) + "].map"), textureUnit );
    
}

void Material::toggleTexture(

    int textureIndex,
    bool state
){
    m_shader->use();
    m_shader->setBool( ("textures[" + std::to_string( textureIndex ) + "].isUsing"), state );
}

void Material::clearTexture(
    
    int textureIndex
){

    m_textures[ textureIndex ] = -1;

    
    m_shader->use();
    m_shader->setBool( ("textures[" + std::to_string( textureIndex ) + "].isUsing"), false );
    m_shader->setBool( ("textures[" + std::to_string( textureIndex ) + "].map"), -1 );
    
}


// Shader

void Material::setShader( Shader* shader ){ 
    
    m_shader = shader;

    updateAllMaterialUniforms();

}

