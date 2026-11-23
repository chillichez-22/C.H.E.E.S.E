#pragma once

#include <vector>
#include <string>


#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"

#include "components/shader.hpp"

// Forward declaration of directional light
class DirectionalLight;


/**
 * @brief Data about a texture, bound to a material.
 */
struct MaterialTexture{

    int texID = -1;     /*< Id of the texture when loading. */
    int texUnit = -1;   /*< Hook it is stored on. */
    bool isUsing = false;   
};


/** 
 * @class Abstract material class.
 */
class Material{

protected:

    std::string m_name = "newMaterial";   /**< Material Name. */ 
    unsigned int m_ID;  /*< ID of the material. */

    Vector4 m_albedoColour{};   /*< Base albedo colour. */

    Vector3 m_diffuseColour{ 0.f, 0.f, 0.f };   /*< Base diffuse colour, typically set to black {0.f, 0.f, 0.f}.*/

    Vector3 m_specularColour{ 1.f, 1.f, 1.f };  /*< Base specular colour, typically set to white {1.0, 1.0, 1.0}.*/  
    float m_specularPower = 16;   /*< Power of the specular contribution. */
    float m_specularIntensity = 0.8f;   /*< Intensity of the specular. */

    Vector3 m_fresnelColour = Vector3(1.f); /*< Base fresnel colour. */ 
    float m_fresnelPower = 4.f;  /*< Power of the fresnel. */
    float m_fresnelIntensity = 4.f;   /*< Intensity of the fresnel. */

    
    // Textures 

    MaterialTexture m_diffuseTexture;    /**< Texture for the diffuse. */
    MaterialTexture m_specularTexture;   /**< Texture for the specular. */
    MaterialTexture m_normalTexture; /**< Texture for the normal. */

    Shader* m_shader; /*< Pointer to the shader for this material. */

    
    // Functions

    /**
     * @brief Updates every material-uniform in this material's shader.
     * 
     * Should only be used when changing the shader when using `setShader`.
     */
    virtual void updateAllMaterialUniforms();


public:

    /**
     * @brief Default constructor for the material.
     */
    Material() = default;

    /**
     * @brief Constructor for a new material.
     * 
     * @param albedoColour Base material colour, if shone in flat white lighting.
     * @param vertexShaderPath Path to the vertex shader.
     * @param fragmentShaderPath Path to the fragment shader.
     * @param name Name of the material.
     */
    Material(
        Vector4 albedoColour,
        const char* vertexShaderPath,
        const char* fragmentShaderPath,
        std::string name = "myNewMaterial"
    );


    /**
     * @brief Constructor for a new phong material.
     * 
     * @param albedoColour Base material colour, if shone in flat white lighting.
     * 
     * @param vertexShaderPath Path to the vertex shader.
     * @param fragmentShaderPath Path to the fragment shader.
     * 
     * @param specularPower Power of the specular, lower = brighter & smaller.
     * @param specularIntensity Brightness factor for the specular component.
     * 
     * @param fresnelColour Colour for the fresnel lighting.
     * @param fresnelPower Power of the fresnel.
     * @param fresnelIntensity Brightness factor for the fresnel component.
     * 
     * @param name Name of the material.
     * 
     */
    Material(
        Vector4 albedoColour,
        const char* vertexShaderPath,
        const char* fragmentShaderPath,
        float specularPower,
        float specularIntensity = 1.f,
        Vector3 fresnelColour = Vector3(1.f),
        float fresnelPower = 1.f,
        float fresnelIntensity = 1.f,
        std::string name = "myNewMaterial"
    );

    /**
     * @brief Destructor for the material.
     */
    virtual ~Material();


    /**
     * @brief Updates the shape-uniforms set by the shape that this is attached onto. 
     * 
     * Should be called when rendering a shape, since the material can/will be assigned to multiple shapes.
     * Adhering to a Entity Component Model (ECM).  
     */
    virtual void updateShapeUniforms(
        Matrix4x4<float> modelMatrix, 
        Matrix4x4<float> viewMatrix, 
	    Matrix4x4<float> projectionMatrix
    ) = 0;



    // Getter 

    /**
     * @brief Getter for the material's name.
     * 
     * @returns `string&` - Reference to a string, of the name of the material.
     */
    std::string& getName(){ return m_name; }

    /**
     * @brief Getter for the material's id.
     * 
     * @returns `uint&` - Reference to an unsigned int, of the id of the material.
     */
    unsigned int& getID(){ return m_ID; }


    /**
     * @brief Getter for the albedo colour.
     * 
     * @returns `vec4&` - Reference to a vec4, containing the RGBA colour value.
     */
    Vector4& getAlbedo(){ return m_albedoColour; }

    
    /**
     * @brief Getter for the diffuse colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getDiffuse(){ return m_diffuseColour; }


    /**
     * @brief Getter for the specular colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getSpecular(){ return m_specularColour; }


    /**
     * @brief Getter for the specular's power.
     * 
     * @returns `float&` Reference to a float, of the power of the specular.
     */
    float& getSpecularPower(){ return m_specularPower; }

        /**
     * @brief Getter for the specular's intensity.
     * 
     * @returns `float&` Reference to a float, of the intensity of the specular.
     */
    float& getSpecularIntensity(){ return m_specularIntensity; }


    /**
     * @brief Getter for the fresnel colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getFresnel(){ return m_fresnelColour; }


    /**
     * @brief Getter for the fresnel's power.
     * 
     * @returns `float&` Reference to a float, of the power of the fresnel.
     */
    float& getFresnelPower(){ return m_fresnelPower; }

    /**
     * @brief Getter for the fresnel's intensity.
     * 
     * @returns `float&` Reference to a float, of the intensity of the fresnel.
     */
    float& getFresnelIntensity(){ return m_fresnelIntensity; }
    
    /**
     * @brief Getter for the material's shader.
     * 
     * @returns `shader* &` Reference of a pointer to a shader on the heap.
     */
    Shader* & getShader(){ return m_shader; }


    // TEXTURES

    /**
     * @brief Getter for the void Diffuse texture's id.
     * 
     * @returns `MaterialTexture&` - Reference for the MaterialTexture of the Diffuse Map.
     */
    MaterialTexture& getDiffuseMap(){ return m_diffuseTexture; };
    
    /**
     * @brief Getter for the void Specular texture's id.
     * 
     * @returns `MaterialTexture&` - Reference for the MaterialTexture of the Specular Map.
     */
    MaterialTexture& getSpecularMap(){ return m_specularTexture; };
    
    /**
     * @brief Getter for the void Normal texture's id.
     * 
     * @returns `MaterialTexture&` - Reference for the MaterialTexture of the Normal Map.
     */
    MaterialTexture& getNormalMap(){ return m_normalTexture; };


    // Setter


    /**
     * @brief Getter for the material's name.
     * 
     * @param name String to set the name of the material.
     */
    void setName( std::string name ){ m_name = name; }

    /**
     * @brief Getter for the material's ID.
     * 
     * @param id String to set the id of the material.
     */
    void setID( unsigned int id ){ m_ID = id; }
    

    /**
     * @brief Setter for the albedo colour.
     * 
     * @param colour RGBA Colour to set. 
     * */    
    void setAlbedo( Vector4 colour );


    /**
     * @brief Setter for the diffuse colour.
     * 
     * @param colour RGB Colour to set.
     */
    void setDiffuse( Vector3 colour );


    /**
     * @brief Setter for the specular colour.
     * 
     * @param colour RGB Colour to set.
     */
    void setSpecular( Vector3 colour );

    /**
     * @brief Setter for the specular power.
     * 
     * @param contribution Contribution to set for the specular. */    
    void setSpecularPower( float power );

    /**
     * @brief Setter for the specular intensity.
     * 
     * @param intensity Intensity to set for the specular. */    
    void setSpecularIntensity( float intensity );

    
    /**
     * @brief Setter for the fresnel colour.
     * 
     * @param colour RGB Colour to set.
     */
    void setFresnel( Vector3 colour );

    /**
     * @brief Setter for the fresnel power.
     * 
     * @param contribution Contribution to set for the fresnel. */    
    void setFresnelPower( float power );
    
    /**
     * @brief Setter for the fresnel intensity.
     * 
     * @param intensity Intensity to set for the fresnel. */    
    void setFresnelIntensity( float intensity );



    /**
     * @brief Setter for the material's shader.
     * 
     * @param shader Shader to set.
     */
    void setShader( Shader* shader );
    

    // TEXTURES

    
    /**
     * @brief Setter for the Diffuse Map.
     * 
     * @param textureID OpenGL texture id for the Diffuse texture. 
     * @param textureUnit OpenGL textureUnit, id where the texture is placed. 
     *
     */
    void setDiffuseMap( unsigned int textureID, unsigned int textureUnit );
    
    /**
     * @brief Setter for the Specular Map.
     * 
     * @param textureID OpenGL texture id for the Specular texture. 
     * @param textureUnit OpenGL textureUnit, id where the texture is placed. 
     * 
     */
    void setSpecularMap( unsigned int textureID, unsigned int textureUnit );
    
    /**
     * @brief Setter for the Normal Map.
     * 
     * @param textureID OpenGL texture id for the Normal texture. 
     * @param textureUnit OpenGL textureUnit, id where the texture is placed. 
     * 
     */
    void setNormalMap( unsigned int textureID, unsigned int textureUnit );
        


    
    /**
     * @brief Clears the Diffuse Map, and tells the shader not to use it anymore. 
     */
    void clearDiffuseMap();
    
    /**
     * @brief Clears the Specular Map, and tells the shader not to use it anymore. 
     */
    void clearSpecularMap();
    
    /**
     * @brief Clears the Normal Map, and tells the shader not to use it anymore. 
     */
    void clearNormalMap();
    


    
};