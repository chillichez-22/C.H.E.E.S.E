#pragma once

#include <cstdint>

#include "vector_3.hpp"
#include "vector_4.hpp"

// Abstract Classes

/** 
 * @brief Abstract matrix parent class
 */
class Matrix{};

/** 
 * @brief Abstract float matrix parent class
 * 
 * @attention To make a float matrix use `MatrixF`, `Matrix3x3F`, `Matrix4x4F`
 */
class BaseMatrixF: Matrix{

private:
    std::array< float, 1 > data;

protected:

    // Getters

    /**
     * @brief Retrieves the float value at `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `float` Value at `indexRow`, `indexCol`
     */
    float get( uint8_t indexRow, uint8_t indexCol );
    
    /**
     * @brief Sets the value of the matrix at `indexRow`, `indexCol` to `value`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * @param value New value to set
     */
    void set( uint8_t indexRow, uint8_t indexCol, float value );


};

/** 
 * @brief Abstract int matrix parent class
 * 
 * @attention To make an int matrix use `MatrixI`, `Matrix3x3I`, `Matrix4x4I`
 */
class BaseMatrixI: Matrix{

private:
    std::array< int, 1 > data;

protected:

    /**
     * @brief Retrieves the integer value at `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `int` Value at `indexRow`, `indexCol`
     */
    int get( uint8_t indexRow, uint8_t indexCol );
    
    /**
     * @brief Sets the value of the matrix at `indexRow`, `indexCol` to `value`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * @param value New value to set
     */
    void set( uint8_t indexRow, uint8_t indexCol, int value );
};


// Unspecified sized Matrices

/**
 * @brief A float matrix of unspecified size. 
 * 
 * @attention Use `Matrix3x3F` or `Matrix4x4F` whenever possible, since they are faster for multiplications
 */
template <uint8_t row, uint8_t col>
class MatrixF : BaseMatrixF{

private:

    uint8_t rows = row;
    uint8_t cols = col;

    std::array< float, row * col > data;

public:

    MatrixF(){};

    /**
     * @brief Returns an array of a pointers, to values, at the row, of `index`.
     * 
     * @details This is not done in the `BaseMatrixF` because the `cols` is not a const, and `template( uint_8 col )` is not defined there.
     * 
     * @param index Index of the row to retrieve the values of.
     * 
     * @returns `array< float*, (columnCount) >`
     */
    std::array< float*, col > getRow( uint8_t index );

    std::array< float*, row > getCol( uint8_t index );
    
};


/**
 * @brief An integer matrix of unspecified size. 
 * 
 */
template <uint8_t row, uint8_t col>
class MatrixI: BaseMatrixI{

private:

    uint8_t rows = row;
    uint8_t cols = col;

    std::array< int, row * col > data;

public:

    MatrixI(){};
    

};


// Specified sized Matrices
// Float Matrices

/**
 * @brief A float matrix of 3 X 3 size. 
 * 
 */
class Matrix3x3F: BaseMatrixF{

private:

    uint8_t rows = 3;
    uint8_t cols = 3;

    /** Stores the matrix data in a 1D float array.  */
    std::array< float, 9 > data = { 
        1.0, 0.0, 0.0, 
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };

public:

    Matrix3x3F(){};
    

    // Multiplication

    /**
     * @brief Returns a 3x3 matrix and vector3 multiplication. ( NewMatrix = This X Vector3 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Matrix3x3F` New 3x3 matrix.
     */
    Matrix3x3F multiplyVector( Vector3 vector );

    /**
     * @brief Returns a 3x3 matrix and 3x3 matrix multiplication. ( NewMatrix = This X other3x3Matrix )
     * 
     * @param matrix 3x3 Matrix to multiply to this.
     * 
     * @returns `Matrix3x3F` New 3x3 matrix.
     */
    Matrix3x3F multiplyMatrix3x3( Matrix3x3F matrix );

    /**
     * @brief Returns a 3x3 matrix and matrix multiplication. ( NewMatrix = This X otherMatrix )
     * 
     * @attention Use `multiplyMatrix3x3` for 3X3 matrix multiplications
     * 
     * @param matrix Matrix to multiply to this.
     * 
     * @returns `Matrix3x3F` New 3x3 matrix.
     */
    Matrix3x3F multiplyMatrix( BaseMatrixF matrix );
};

/**
 * @brief A float matrix of 4 X 4 size. 
 * 
 */
class Matrix4x4F: BaseMatrixF{

private:

    uint8_t rows = 4;
    uint8_t cols = 4;

    /** Stores the matrix data in a 1D float array.  */
    std::array< float, 16 > data = { 
        1.0, 0.0, 0.0, 0.0, 
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };


public:

    Matrix4x4F(){};
    

    // Multiplication

    /**
     * @brief Returns a 4x4 matrix and vector4 multiplication. ( NewMatrix = This X Vector4 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Matrix4x4F` New 4x4 matrix.
     */
    Matrix4x4F multiplyVector( Vector4 vector );

    /**
     * @brief Returns a 4x4 matrix and 4x4 matrix multiplication. ( NewMatrix = This X other4x4Matrix )
     * 
     * @param matrix 4x4 Matrix to multiply to this.
     * 
     * @returns `Matrix4x4F` New 4x4 matrix.
     */
    Matrix4x4F multiplyMatrix4x4( Matrix4x4F matrix );

    /**
     * @brief Returns a 4x4 matrix and matrix multiplication. ( NewMatrix = This X otherMatrix )
     * 
     * @attention Use `multiplyMatrix4x4F` for 4X4 matrix multiplications
     * 
     * @param matrix Matrix to multiply to this.
     * 
     * @returns `Matrix4x4F` New 4x4 matrix.
     */
    Matrix4x4F multiplyMatrix( BaseMatrixF matrix );

};


// Int Matrices

/**
 * @brief A int matrix of 3 X 3 size. 
 * 
 */
class Matrix3x3I: BaseMatrixI{

private:

    uint8_t rows = 3;
    uint8_t cols = 3;

    /** Stores the matrix data in a 1D int array.  */
    std::array< int, 9 > data = { 
        1, 0, 0, 
        0, 1, 0,
        0, 0, 1
    };

public:

    Matrix3x3I(){};
    

    // Multiplication

    /**
     * @brief Returns a 3x3 matrix and vector3 multiplication. ( NewMatrix = This X Vector3 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Matrix3x3I` New 3x3 matrix.
     */
    Matrix3x3I multiplyVector( Vector3 vector );

    /**
     * @brief Returns a 3x3 matrix and 3x3 matrix multiplication. ( NewMatrix = This X other3x3Matrix )
     * 
     * @param matrix 3x3 Matrix to multiply to this.
     * 
     * @returns `Matrix3x3I` New 3x3 matrix.
     */
    Matrix3x3I multiplyMatrix3x3( Matrix3x3I matrix );

    /**
     * @brief Returns a 3x3 matrix and matrix multiplication. ( NewMatrix = This X otherMatrix )
     * 
     * @attention Use `multiplyMatrix3x3` for 3X3 matrix multiplications
     * 
     * @param matrix Matrix to multiply to this.
     * 
     * @returns `Matrix3x3I` New 3x3 matrix.
     */
    Matrix3x3I multiplyMatrix( BaseMatrixI matrix );

};

/**
 * @brief A int matrix of 4 X 4 size. 
 * 
 */
class Matrix4x4I: BaseMatrixI{

private:

    uint8_t rows = 4;
    uint8_t cols = 4;

    /** Stores the matrix data in a 1D int array.  */
    std::array< float, 16 > data = { 
        1.0, 0.0, 0.0, 0.0, 
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };


public:

    Matrix4x4I(){};
    

    // Multiplication

    /**
     * @brief Returns a 4x4 matrix and vector4 multiplication. ( NewMatrix = This X Vector4 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Matrix4x4I` New 4x4 matrix.
     */
    Matrix4x4I multiplyVector( Vector4 vector );

    /**
     * @brief Returns a 4x4 matrix and 4x4 matrix multiplication. ( NewMatrix = This X other4x4Matrix )
     * 
     * @param matrix 4x4 Matrix to multiply to this.
     * 
     * @returns `Matrix4x4I` New 4x4 matrix.
     */
    Matrix4x4I multiplyMatrix4x4( Matrix4x4I matrix );

    /**
     * @brief Returns a 4x4 matrix and matrix multiplication. ( NewMatrix = This X otherMatrix )
     * 
     * @attention Use `multiplyMatrix4x4I` for 4X4 matrix multiplications
     * 
     * @param matrix Matrix to multiply to this.
     * 
     * @returns `Matrix4x4I` New 4x4 matrix.
     */
    Matrix4x4I multiplyMatrix( BaseMatrixI matrix );

};
