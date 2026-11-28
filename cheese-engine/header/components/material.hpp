#pragma once

#include <vector>
#include <string>


#include "components/component.hpp"

#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"

#include "components/shader.hpp"
#include "components/texture.hpp"

#include "files/texture_manager.hpp"


constexpr unsigned int DIFFUSE_TEXTURE = 0;   /*< Diffuse texture index. */
constexpr unsigned int SPECULAR_TEXTURE = 1;  /*< Specular texture index. */
constexpr unsigned int NORMAL_TEXTURE = 2;    /*< Normal texture index. */



/** 
 * @class Abstract material class.
 */
class Material : public Component{

private:

    std::string m_name = "newMaterial";   /**< Material Name. */ 
    unsigned int m_ID;  /*< ID of the material. */


    Vector4 m_albedoColour{ 0.f };   /*< Base albedo colour. */

    Vector3 m_diffuseColour{ 0.f };   /*< Base diffuse colour, typically set to black {0.f, 0.f, 0.f}.*/

    Vector3 m_specularColour{ 1.f };  /*< Base specular colour, typically set to white {1.0, 1.0, 1.0}.*/  
    float m_specularPower = 16;         /*< Power of the specular contribution. */
    float m_specularIntensity = 0.8f;   /*< Intensity of the specular. */

    Vector3 m_fresnelColour{ 1.f }; /*< Base fresnel colour. */ 
    float m_fresnelPower = 4.f;             /*< Power of the fresnel. */
    float m_fresnelIntensity = 4.f;     /*< Intensity of the fresnel. */
    

    /*< List of textures units, for this material. 0 = Diffuse Unit | 1 = Specular Unit | 2 = Normal Unit. */
    std::vector<int> m_textures{ -1, -1, -1 };  

    Shader* m_shader = nullptr; /*< Pointer to the shader for this material. */



public:

    /**
     * @brief Default constructor for the material.
     */
    Material() = default;

    /**
     * @brief Constructor for a new material.
     
     * @param vertexShaderPath Path to a vertex shader.
     * @param fragmentShaderPath Path to a fragment shader.
     * 
     * @param diffuseTexturePath Path to a diffuse texture.
     * @param specularTexturePath Path to a specular texture.
     * @param normalTexturePath Path to a normal texture.
     * 
     * @param name Name of the material.
     */
    Material(
        
        std::string vertexShaderPath,
        std::string fragmentShaderPath,
        
        TextureManager& textureManager,
        std::string diffuseTexturePath,
        std::string specularTexturePath,
        std::string normalTexturePath,

        std::string name = "myNewMaterial"
    );


    /**
     * @brief Constructor for a new material.
     * 
     * @param vertexShaderPath Path to the vertex shader.
     * @param fragmentShaderPath Path to the fragment shader.
     * 
     * @param albedoColour Base material colour, if shone in flat white lighting.
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

        std::string vertexShaderPath,
        std::string fragmentShaderPath,

        Vector4 albedoColour,
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
    ~Material();


    // Uniforms

    /**
     * @brief Updates every material-uniform in this material's shader.
     * 
     * Should only be used when changing the shader when using `setShader`.
     */
    void updateAllMaterialUniforms();


    /**
     * @brief Updates the shape-uniforms set by the shape that this is attached onto. 
     * 
     * Should be called when rendering a shape, since the material can/will be assigned to multiple shapes.
     * Adhering to a Entity Component Model (ECM).  
     */
    void updateUniforms(
        Matrix4x4<float> modelMatrix, 
        Matrix4x4<float> viewMatrix, 
        Matrix4x4<float> projectionMatrix,
        TextureManager& textureManager
    );



    // Getter 

    /**
     * @brief Getter for the material's name.
     * 
     * @returns `string&` - Reference to a string, of the name of the material.
     */
    std::string& getName();

    /**
     * @brief Getter for the material's id.
     * 
     * @returns `uint&` - Reference to an unsigned int, of the id of the material.
     */
    unsigned int& getID();


    /**
     * @brief Getter for the albedo colour.
     * 
     * @returns `vec4&` - Reference to a vec4, containing the RGBA colour value.
     */
    Vector4& getAlbedo();

    
    /**
     * @brief Getter for the diffuse colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getDiffuse();


    /**
     * @brief Getter for the specular colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getSpecular();

    /**
     * @brief Getter for the specular's power.
     * 
     * @returns `float&` Reference to a float, of the power of the specular.
     */
    float& getSpecularPower();

    /**
     * @brief Getter for the specular's intensity.
     * 
     * @returns `float&` Reference to a float, of the intensity of the specular.
     */
    float& getSpecularIntensity();


    /**
     * @brief Getter for the fresnel colour.
     * 
     * @returns `vec3&` - Reference to a vec3, containing the RGB colour value.
     */
    Vector3& getFresnel();

    /**
     * @brief Getter for the fresnel's power.
     * 
     * @returns `float&` Reference to a float, of the power of the fresnel.
     */
    float& getFresnelPower();

    /**
     * @brief Getter for the fresnel's intensity.
     * 
     * @returns `float&` Reference to a float, of the intensity of the fresnel.
     */
    float& getFresnelIntensity();
    
    
    /**
     * @brief Getter for the void Diffuse texture's id.
     * 
     * @returns `MaterialTexture&` - Reference for the MaterialTexture of the Diffuse Map.
     */
    int& getTexture( int textureIndex );
    

    /**
     * @brief Getter for the material's shader.
     * 
     * @returns `shader* &` Reference of a pointer to a shader on the heap.
     */
    Shader* & getShader();


    // Setter

    /**
     * @brief Getter for the material's name.
     * 
     * @param name String to set the name of the material.
     */
    void setName( std::string name );

    /**
     * @brief Getter for the material's ID.
     * 
     * @param id String to set the id of the material.
     */
    void setID( unsigned int id );
    

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

    
    /**
     * @brief Setter for the Diffuse Map.
     * 
     * @param textureIndex Index of the of the material's texture. 
     * @param textureUnit OpenGL textureUnit, id of the texture. 
     *
     */
    void setTexture(

        int textureIndex, 
        unsigned int textureUnit 
    );
    
    /**
     * @brief Toggles a texture's state in the shader.
     * 
     * @param textureIndex Index of the of the material's texture.  
     * @param state State to set the texture to.
     */
    void toggleTexture(
        int textureIndex,
        bool state
    );

    /**
     * @brief Clears the Diffuse Map, and tells the shader not to use it anymore. 
     */
    void clearTexture( int textureIndex );
    
    
};