#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>


#include "maths/vector_2.hpp"
#include "maths/vector_3.hpp"
#include "maths/vector_4.hpp"
#include "maths/matrix.hpp"


/**
 * @brief 
 * Compiles and links shader code form files, passes file locations as constructor parameters,
 * and a bunch of setters for uniforms.
 * 
 */
class Shader{

private:

	unsigned int m_id; /*< Unique identifier for the shader. */
    std::string m_name; /*< Name of the shader*/

private:

	/**
	 * @brief Checks for any errors when creating a new shader
	 * 
	 * @param shader ID for the shader.
	 * @param type Type of shader.
	 */
	void checkCompileErrors( 
		GLuint shader, 
		std::string type 
	);



public:

	// Constructors

	/**
	 * @brief default constructor for a shader.
	 */
	Shader(){};

	/**
	 * @brief Constructor for a new shader.
	 * 
	 * @param vertexPath Pointer to the path for the vertex shader.
	 * @param fragmentPath Pointer to the path for the fragment shader.
	 */
	Shader(
		const char* vertexPath, 
		const char* fragmentPath
	);

	/**
	 * @brief Constructor for a new shader.
	 * 
	 * @param vertexPath Pointer to the path for the vertex shader.
	 * @param fragmentPath Pointer to the path for the fragment shader.
	 */
	Shader(
		std::string vertexPath, 
		std::string fragmentPath
	);


	/**
	 * @brief Uses the shader.
	 */
	void use();


	// Getter

	/**
	 * @brief Getter for the Shader's ID
	 * 
	 * @return `uint` ID for the shader.
	 */
	inline unsigned int getID() const { return m_id; }


	// Utility uniform functions

	/**
	 * @brief Sets a bool.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setBool(
		const std::string& name, 
		bool value
	) const;

	/**
	 * @brief Sets an int.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setInt(
		const std::string& name, 
		int value
	) const;

	/**
	 * @brief Sets a float.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setFloat(
		const std::string& name, 
		float value
	) const;


    // Vectors

	/**
	 * @brief Sets a vector 2.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setVec2(
		const std::string& name, 
		const Vector2& value
	) const;

	/**
	 * @brief Sets a vector 2.
	 * 
	 * @param name Variable identifier.
	 * @param x X component.
	 * @param y Y component.
	 */
	void setVec2(
		const std::string& name, 
		float x, 
		float y
	) const;


	/**
	 * @brief Sets a vector 3.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setVec3(
		const std::string& name, 
		const Vector3& value
	) const;
	
	/**
	 * @brief Sets a vector 3.
	 * 
	 * @param name Variable identifier.
	 * @param x X component.
	 * @param y Y component.
	 * @param z Z component.
	 */
	void setVec3(
		const std::string& name, 
		float x, 
		float y, 
		float z
	) const;


	/**
	 * @brief Sets a vector 4.
	 * 
	 * @param name Variable identifier.
	 * @param value Variable value.
	 */
	void setVec4(
		const std::string& name, 
		const Vector4& value
	) const;

	/**
	 * @brief Sets a vector 4.
	 * 
	 * @param name Variable identifier.
	 * @param x X component.
	 * @param y Y component.
	 * @param z Z component.
	 * @param w W component.
	 */
	void setVec4(
		const std::string& name, 
		float x, 
		float y, 
		float z, 
		float w
	);


    // Matrix

	/**
	 * @brief Sets a matrix 2x2.
	 * 
	 * @param name Variable identifier.
	 * @param mat Matrix value.
	 */
	void setMat2(
		const std::string& name, 
		const Matrix<float, 2, 2>& mat
	) const;

	/**
	 * @brief Sets a matrix 3x3.
	 * 
	 * @param name Variable identifier.
	 * @param mat Matrix value.
	 */
	void setMat3(
		const std::string& name, 
		const Matrix3x3<float>& mat
	) const;

	/**
	 * @brief Sets a matrix 4x4.
	 * 
	 * @param name Variable identifier.
	 * @param mat Matrix value. 
	 */
	void setMat4(
		const std::string& name, 
		const Matrix4x4<float>& mat
	) const;


	/**
	 * @brief Sets a uniform block.
	 * 
	 * @param name Variable identifier.
	 * @param uniformBlock Uniform block value.
	 */
	void setUniformBlock(
		const std::string& name, 
		unsigned int uniformBlock
	) const;


};
#endif

