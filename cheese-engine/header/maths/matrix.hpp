#pragma once

#include <cstdint>
#include <array>

#include "vector_3.hpp"
#include "vector_4.hpp"


template< typename valueType, uint8_t rowCount, uint8_t colCount >
class Matrix{

private:

    std::array< valueType, rowCount * colCount > data{};

public:

    uint8_t rows;
    uint8_t cols;

    
    /**
     * @brief Retrieves the integer value at matrix pos `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `valueType` Value at `indexRow`, `indexCol`
     */
    valueType get( uint8_t indexRow, uint8_t indexCol ){

        return data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ]
    };

        /**
     * @brief Retrieves the integer value at array index `index`.
     * 
     * @param indexRow Raw array index
     * 
     * @return `valueType` Value at `index`
     */
    valueType getRaw( uint8_t index ){

        return data[ index ]
    };
    
    /**
     * @brief Sets the value of the matrix pos `indexRow`, `indexCol` to `value`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * @param value New value to set
     */
    void set( uint8_t indexRow, uint8_t indexCol, valueType value ){

        data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ] = value;
    };

        /**
     * @brief Sets the value of the array index `index` to `value`.
     * 
     * @param indexRow Raw array index
     * 
     * @param value New value to set
     */
    void setRaw( uint8_t indexRow, valueType value ){

        data[ index ] = value;
    };


     
    // Multiply

    /**
     * @brief Returns a matrix multiplication for this and the other matrix.
     * 
     * @details
     * 
     * This = A <- ( R, C )
     * 
     * Other = B <- ( C, K )
     * 
     * Return: A x B <- ( R, K )
     *  
     * @attention A's rows must be equal to B's columns.
     * 
     * @param otherMatrix B matrix to multiply to this one.
     * 
     * @returns `Matrix<valueType, rowCount, otherColCount>` new matrix of: `This` x `otherMatrix`
     */
    template< typename otherType, uint8_t otherColCount >
    Matrix< valueType, rowCount, otherColCount > multiply( Matrix< otherType, colCount, otherColCount > otherMatrix ){    
        
        // Checks if the matrices are compatible
        if ( cols != otherMatrix.rows ){

            //throw new Error(`Cannot multiply matrices have differing sizes: thisRow: ${this.rows}, otherCols: ${otherMatrix.cols}`);
            std::cerr << "\n";
        }

        // Since: ( R, C ) x ( C, K ) = ( R, K )
        Matrix< valueType, rows, otherMatrix.cols > resultMatrix{};

        valueType sum = 0;

        // Repeats for each row in A
        for ( uint8_t aRowIndex = 0; aRowIndex < rows; aRowIndex++ ){

            // Repeats for each column in B
            for ( uint8_t bColIndex = 0; bColIndex < otherMatrix.cols; bColIndex++ ){

                sum  = 0;

                // Goes down B's rows, and across A's Columns
                for ( uint8_t bRowIndex = 0; bRowIndex < otherMatrix.rows; bRowIndex++){

                    sum += get( aRowIndex, bRowIndex ) * otherMatrix.get( bRowIndex, bColIndex );
                }

                resultMatrix.set( aRowIndex, bColIndex, sum ); 
            }
        }

        return resultMatrix;
    };

};


// Specified sized Matrices

/**
 * @brief A matrix of 3 X 3 size. 
 * 
 */
template< typename valueType >
class Matrix3x3 : Matrix{

private:

    uint8_t rows = 3;
    uint8_t cols = 3;

    /** Stores the matrix data in a 1D float array.  */
    std::array< valueType, 9 > data = { 
        1.0, 0.0, 0.0, 
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };

public:

    Matrix3x3< valueType >(){};
    

    // Multiplication

    /**
     * @brief Returns a 3x3 matrix and vector3 multiplication. ( NewMatrix = This X Vector3 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Matrix3x3< valueType >` New 3x3 matrix.
     */
    Matrix3x3< valueType > multiplyVector( Vector3 vector );

    /**
     * @brief Returns a 3x3 matrix and 3x3 matrix multiplication. ( NewMatrix = This X other3x3Matrix )
     * 
     * @param matrix 3x3 Matrix to multiply to this.
     * 
     * @returns `Matrix3x3< valueType >` New 3x3 matrix.
     */
    template< typename otherType >
    Matrix3x3< valueType > multiply( Matrix3x3< otherType > matrix ){

        Matrix3x3< valueType > resultantMatrix{};

        /*
        0 = 0*0 + 1*3 + 2*6	
        1 = 0*1 + 1*4 + 2*7	
        2 = 0*2 + 1*5 + 2*8

        3 = 3*0 + 4*3 + 5*6	
        4 = 3*1 + 4*4 + 5*7	
        5 = 3*2 + 4*5 + 5*8

        6 = 6*0 + 7*3 + 8*6	
        7 = 6*1 + 7*4 + 8*7	
        8 = 6*2 + 7*5 + 8*8
        */

        resultantMatrix.setRaw( 0, (getRaw( 0 ) * matrix.getRaw( 0 )) + (getRaw( 1 ) * matrix.getRaw( 3 )) + (getRaw( 2 ) * matrix.getRaw( 6 )) )
        resultantMatrix.setRaw( 1, (getRaw( 0 ) * matrix.getRaw( 1 )) + (getRaw( 1 ) * matrix.getRaw( 4 )) + (getRaw( 2 ) * matrix.getRaw( 7 )) )
        resultantMatrix.setRaw( 2, (getRaw( 0 ) * matrix.getRaw( 2 )) + (getRaw( 1 ) * matrix.getRaw( 5 )) + (getRaw( 2 ) * matrix.getRaw( 8 )) )

        resultantMatrix.setRaw( 3, (getRaw( 3 ) * matrix.getRaw( 0 )) + (getRaw( 4 ) * matrix.getRaw( 3 )) + (getRaw( 5 ) * matrix.getRaw( 6 )) )
        resultantMatrix.setRaw( 4, (getRaw( 3 ) * matrix.getRaw( 1 )) + (getRaw( 4 ) * matrix.getRaw( 4 )) + (getRaw( 5 ) * matrix.getRaw( 7 )) )
        resultantMatrix.setRaw( 5, (getRaw( 3 ) * matrix.getRaw( 2 )) + (getRaw( 4 ) * matrix.getRaw( 5 )) + (getRaw( 5 ) * matrix.getRaw( 8 )) )

        resultantMatrix.setRaw( 6, (getRaw( 6 ) * matrix.getRaw( 0 )) + (getRaw( 7 ) * matrix.getRaw( 3 )) + (getRaw( 8 ) * matrix.getRaw( 6 )) )
        resultantMatrix.setRaw( 7, (getRaw( 6 ) * matrix.getRaw( 1 )) + (getRaw( 7 ) * matrix.getRaw( 4 )) + (getRaw( 8 ) * matrix.getRaw( 7 )) )
        resultantMatrix.setRaw( 8, (getRaw( 6 ) * matrix.getRaw( 2 )) + (getRaw( 7 ) * matrix.getRaw( 5 )) + (getRaw( 8 ) * matrix.getRaw( 8 )) )

        return resultantMatrix;
    };

};

/**
 * @brief A float matrix of 4 X 4 size. 
 * 
 */
template< typename valueType >
class Matrix4x4 : Matrix{

private:

    uint8_t rows = 4;
    uint8_t cols = 4;

    /** Stores the matrix data in a 1D float array.  */
    std::array< valueType, 16 > data = { 
        1.0, 0.0, 0.0, 0.0, 
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };


public:

    Matrix4x4<valueType>(){};
    

    // Multiplication

    /**
     * @brief Returns a 4x4 matrix and vector4 multiplication. ( NewMatrix = This X Vector4 )
     * 
     * @param vector Vector to multiply to this. ( Vector to translate )
     * 
     * @returns `Vector4` New vector translated by this matrix.
     */
    Vector4 multiplyVector( Vector4 vector );

    /**
     * @brief Returns a 4x4 matrix and 4x4 matrix multiplication. ( NewMatrix = This X other4x4Matrix )
     * 
     * @param matrix 4x4 Matrix to multiply to this.
     * 
     * @returns `Matrix4x4<valueType>` New 4x4 matrix.
     */
    template< typename otherType >
    Matrix4x4<valueType> multiply( Matrix4x4<otherType> matrix ){

        Matrix4x4< valueType > resultantMatrix{};

        /*
        { 00, 01, 02, 03 }
        { 04, 05, 06, 07 }
        { 08, 09, 10, 11 }
        { 12, 13, 14, 15 }

        00 = 0*0 + 1*4 + 2*8  + 3*12	    
        01 = 0*1 + 1*5 + 2*9  + 3*13	    
        02 = 0*2 + 1*6 + 2*10 + 3*14	    
        03 = 0*3 + 1*7 + 2*11 + 3*15
        
        04 = 4*0 + 5*4 + 6*8  + 7*12	    
        05 = 4*1 + 5*5 + 6*9  + 7*13	    
        06 = 4*2 + 5*6 + 6*10 + 7*14	    
        07 = 4*3 + 5*7 + 6*11 + 7*15
        
        08 = 8*0 + 9*4 + 10*8  + 11*12	    
        09 = 8*1 + 9*5 + 10*9  + 11*13	    
        10 = 8*2 + 9*6 + 10*10 + 11*14	    
        11 = 8*3 + 9*7 + 10*11 + 11*15
        
        12 = 12*0 + 13*4 + 14*8  + 15*12	
        13 = 12*1 + 13*5 + 14*9  + 15*13	
        14 = 12*2 + 13*6 + 14*10 + 15*14	
        15 = 12*3 + 13*7 + 14*11 + 15*15
        */

        resultantMatrix.setRaw( 0,  (getRaw( 0 ) * matrix.getRaw( 0 )) + (getRaw( 1 ) * matrix.getRaw( 4 )) + (getRaw( 2 ) * matrix.getRaw( 8 ))  + (getRaw( 3 ) * matrix.getRaw( 12 )) )
        resultantMatrix.setRaw( 1,  (getRaw( 0 ) * matrix.getRaw( 1 )) + (getRaw( 1 ) * matrix.getRaw( 5 )) + (getRaw( 2 ) * matrix.getRaw( 9 ))  + (getRaw( 3 ) * matrix.getRaw( 13 )) )
        resultantMatrix.setRaw( 2,  (getRaw( 0 ) * matrix.getRaw( 2 )) + (getRaw( 1 ) * matrix.getRaw( 6 )) + (getRaw( 2 ) * matrix.getRaw( 10 )) + (getRaw( 3 ) * matrix.getRaw( 14 )) )
        resultantMatrix.setRaw( 3,  (getRaw( 0 ) * matrix.getRaw( 3 )) + (getRaw( 1 ) * matrix.getRaw( 7 )) + (getRaw( 2 ) * matrix.getRaw( 11 )) + (getRaw( 3 ) * matrix.getRaw( 15 )) )

        resultantMatrix.setRaw( 4,  (getRaw( 4 ) * matrix.getRaw( 0 )) + (getRaw( 5 ) * matrix.getRaw( 4 )) + (getRaw( 6 ) * matrix.getRaw( 8 ))  + (getRaw( 7 ) * matrix.getRaw( 12 )) )
        resultantMatrix.setRaw( 5,  (getRaw( 4 ) * matrix.getRaw( 1 )) + (getRaw( 5 ) * matrix.getRaw( 5 )) + (getRaw( 6 ) * matrix.getRaw( 9 ))  + (getRaw( 7 ) * matrix.getRaw( 13 )) )
        resultantMatrix.setRaw( 6,  (getRaw( 4 ) * matrix.getRaw( 2 )) + (getRaw( 5 ) * matrix.getRaw( 6 )) + (getRaw( 6 ) * matrix.getRaw( 10 )) + (getRaw( 7 ) * matrix.getRaw( 14 )) )
        resultantMatrix.setRaw( 7,  (getRaw( 4 ) * matrix.getRaw( 3 )) + (getRaw( 5 ) * matrix.getRaw( 7 )) + (getRaw( 6 ) * matrix.getRaw( 11 )) + (getRaw( 7 ) * matrix.getRaw( 15 )) )

        resultantMatrix.setRaw( 8,  (getRaw( 8 ) * matrix.getRaw( 0 )) + (getRaw( 9 ) * matrix.getRaw( 4 )) + (getRaw( 10 ) * matrix.getRaw( 8 )) + (getRaw( 11 ) * matrix.getRaw( 12 )) )
        resultantMatrix.setRaw( 9,  (getRaw( 8 ) * matrix.getRaw( 1 )) + (getRaw( 9 ) * matrix.getRaw( 5 )) + (getRaw( 10 ) * matrix.getRaw( 9 )) + (getRaw( 11 ) * matrix.getRaw( 13 )) ) 
        resultantMatrix.setRaw( 10, (getRaw( 8 ) * matrix.getRaw( 2 )) + (getRaw( 9 ) * matrix.getRaw( 6 )) + (getRaw( 10 ) * matrix.getRaw( 10 )) + (getRaw( 11 ) * matrix.getRaw( 14 )) )
        resultantMatrix.setRaw( 11, (getRaw( 8 ) * matrix.getRaw( 3 )) + (getRaw( 9 ) * matrix.getRaw( 7 )) + (getRaw( 10 ) * matrix.getRaw( 11 )) + (getRaw( 11 ) * matrix.getRaw( 15 )) )

        resultantMatrix.setRaw( 12, (getRaw( 12 ) * matrix.getRaw( 0 )) + (getRaw( 13 ) * matrix.getRaw( 4 )) + (getRaw( 14 ) * matrix.getRaw( 8 ))  + (getRaw( 15 ) * matrix.getRaw( 12 )) )
        resultantMatrix.setRaw( 13, (getRaw( 12 ) * matrix.getRaw( 1 )) + (getRaw( 13 ) * matrix.getRaw( 5 )) + (getRaw( 14 ) * matrix.getRaw( 9 ))  + (getRaw( 15 ) * matrix.getRaw( 13 )) )
        resultantMatrix.setRaw( 14, (getRaw( 12 ) * matrix.getRaw( 2 )) + (getRaw( 13 ) * matrix.getRaw( 6 )) + (getRaw( 14 ) * matrix.getRaw( 10 )) + (getRaw( 15 ) * matrix.getRaw( 14 )) )
        resultantMatrix.setRaw( 15, (getRaw( 12 ) * matrix.getRaw( 3 )) + (getRaw( 13 ) * matrix.getRaw( 7 )) + (getRaw( 14 ) * matrix.getRaw( 11 )) + (getRaw( 15 ) * matrix.getRaw( 15 )) )

        return resultantMatrix;
    };


    // Matrix Movement

    /**
     * @brief Scales the matrix by the `x`, `y`, `z` values
     * 
     * { X, 0, 0, 0 }
     * 
     * { 0, Y, 0, 0 }
     * 
     * { 0, 0, Z, 0 }
     * 
     * { 0, 0, 0, 1 }
     * 
     * @param x X scale 
     * @param y Y scale 
     * @param z Z scale 
     * 
     * @returns `Matrix4x4<valueType>` New matrix scaled.
     */
    Matrix4x4<valueType> scale( valueType x, valueType y, valueType z );
    

    /**
     * @brief Scales the matrix by the `x`, `y`, `z` values
     * 
     * { 0, 0, 0, X }
     * 
     * { 0, 0, 0, Y }
     * 
     * { 0, 0, 0, Z }
     * 
     * { 0, 0, 0, 1 }
     * 
     * @param x X translation 
     * @param y Y translation 
     * @param z Z translation 
     * 
     * @returns `Matrix4x4<valueType>` New matrix translated.
     */
    Matrix4x4<valueType> translate( valueType x, valueType y, valueType z );


    /**
     * @brief Rotates the matrix by the `radians` in the x direction.
     * 
     * { 1, 0, 0, 0 }
     * 
     * { 0, cos, -sin, 0 }
     * 
     * { 0, sin, cos, 0 }
     * 
     * { 0, 0, 0, 1 }
     * 
     * @param x X rotation 
     * @param y Y rotation 
     * @param z Z rotation 
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateX( float radians );

    /**
     * @brief Rotates the matrix by the `radians` in the y direction.
     * 
     * { cos, 0, sin, 0 }
     * 
     * { 0, 1, 0, 0 }
     * 
     * { -sin, 0, cos, 0 }
     * 
     * { 0, 0, 0, 1 }
     * 
     * @param x X rotation 
     * @param y Y rotation 
     * @param z Z rotation 
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateY( float radians );

    /**
     * @brief Rotates the matrix by the `radians` in the z direction.
     * 
     * { cos, -sin, 0, 0 }
     * 
     * { sin, cos, 0, 0 }
     * 
     * { 0, 0, 1, 0 }
     * 
     * { 0, 0, 0, 1 }
     * 
     * @param x X rotation 
     * @param y Y rotation 
     * @param z Z rotation 
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateZ( float radians );


};

