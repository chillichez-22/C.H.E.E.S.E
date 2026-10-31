#pragma once

#include <iostream>
#include <cstdint>
#include <array>
#include <cmath> 

#include "vector_3.hpp"
#include "vector_4.hpp"

/**
 * @brief 
 * A matrix class used to hold data in a fixed size.
 * 
 * Can be any size upto: `255` rows by `255` columns.
 * 
 * Initialises a zero'ed matrix; initially filling with 0s.
 * 
 * @attention 
 * For 3 by 3 matrices use `Matrix3x3< valueType >` instead.
 * 
 * For 4 by 4 matrices use `Matrix4x4< valueType >` instead.
 * 
 * As these are both more efficient and faster when doing vector, and matrix multiplying.
 * 
 * 
 * @tparam valueType Type of the values in the matrix e.g( float, int ).
 * @tparam rowCount Number of rows for the matrix.
 * @tparam colCount Number of columns for the matrix.
 * 
 */
template< typename valueType, uint8_t rowCount, uint8_t colCount >
class Matrix{

private:

    uint8_t rows = rowCount;
    uint8_t cols = colCount;

    std::array< valueType, rowCount * colCount > data{};

public:
    
    /**
     * @brief Default constructor
     */
    Matrix(){};

    ~Matrix() = default;


    // Getters

    /**
     * @brief Returns the number of rows in the matrix.
     * 
     * @returns `uint8_t` Number of rows.
     */
    uint8_t getRows(){
        
        return rows;
    };

    /**
     * @brief Returns the number of columns in the matrix.
     * 
     * @returns `uint8_t` Number of columns.
     */
    uint8_t getCols(){

        return cols;
    };
    
    
    /**
     * @brief Retrieves the integer value at matrix pos `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `valueType` Value at `indexRow`, `indexCol`
     */
    valueType get( uint8_t indexRow, uint8_t indexCol ){

        return data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ];
    };

    /**
     * @brief Retrieves the integer value at array index `index`.
     * 
     * @param indexRow Raw array index
     * 
     * @return `valueType` Value at `index`
     */
    valueType getRaw( uint8_t index ){

        return data[ index ];
    };
    

    // Setters

    /**
     * @brief Sets the value of the matrix pos `indexRow`, `indexCol` to `value`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * @param value New value to set
     * 
     */
    void set( uint8_t indexRow, uint8_t indexCol, valueType value ){

        data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ] = value;
    };

    /**
     * @brief Sets the value of the array index `index` to `value`.
     * 
     * @param indexRow Array index
     * @param value New value to set
     * 
     */
    void setRaw( uint8_t index, valueType value ){

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
        if ( cols != otherMatrix.getRows() ){

            //throw new Error(`Cannot multiply matrices have differing sizes: thisRow: ${this.rows}, otherCols: ${otherMatrix.cols}`);
            std::cerr << "\n";
        }

        // Since: ( R, C ) x ( C, K ) = ( R, K )
        Matrix< valueType, rows, otherColCount > resultMatrix{};

        valueType sum = 0;

        // Repeats for each row in A
        for ( uint8_t aRowIndex = 0; aRowIndex < rows; aRowIndex++ ){

            // Repeats for each column in B
            for ( uint8_t bColIndex = 0; bColIndex < otherColCount; bColIndex++ ){

                sum  = 0;

                // Goes down B's rows, and across A's Columns
                // `cols` is used as the bRows = ACols
                for ( uint8_t bRowIndex = 0; bRowIndex < cols; bRowIndex++){

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
 * @brief 
 * A matrix of 3 X 3 size.
 * 
 * Initialises as an identity matrix, with 1 along the left -> right diagonal.
 *
 * @details 
 * Values are set to float 1.0 originally, if the `valueType` can't support that type conversion, the matrix will crash.
 * 
 * @tparam valueType Type of the values in the matrix e.g( float, int )
 */
template< typename valueType >
class Matrix3x3 : public Matrix< valueType, 3, 3 >{

private:

    uint8_t rows = 3;
    uint8_t cols = 3;

    /** Stores the matrix data in a 1D `valueType` array.  */
    std::array< valueType, 9 > data = { 
        1.0, 0.0, 0.0, 
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };

public:

    // Keeps original `multiply`, so this class can use both.
    using Matrix<valueType, 3, 3>::multiply;


    /** 
     * @brief Default constructor
     */
    Matrix3x3(){};

    ~Matrix3x3() = default;


    // Multiplication

    /**
     * @brief Returns a 3x3 matrix and vector3 multiplication. ( NewMatrix = This X Vector3 )
     * 
     * @param vector Vector to multiply to this 
     * 
     * @returns `Vector3` New vector3 translated by this matrix.
     */
    Vector3 multiplyVector( Vector3 vector ){

        Vector3 resultVector = Vector3( 0.f, 0.f, 0.f );

        resultVector.x = ( this->getRaw(0) * vector.x + this->getRaw(1) * vector.y + this->getRaw(2) * vector.z );
        resultVector.y = ( this->getRaw(3) * vector.x + this->getRaw(4) * vector.y + this->getRaw(5) * vector.z );
        resultVector.z = ( this->getRaw(6) * vector.x + this->getRaw(7) * vector.y + this->getRaw(8) * vector.z );

        return resultVector;
    };


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

        resultantMatrix.setRaw( 0, (this->getRaw( 0 ) * matrix.getRaw( 0 )) + (this->getRaw( 1 ) * matrix.getRaw( 3 )) + (this->getRaw( 2 ) * matrix.getRaw( 6 )) );
        resultantMatrix.setRaw( 1, (this->getRaw( 0 ) * matrix.getRaw( 1 )) + (this->getRaw( 1 ) * matrix.getRaw( 4 )) + (this->getRaw( 2 ) * matrix.getRaw( 7 )) );
        resultantMatrix.setRaw( 2, (this->getRaw( 0 ) * matrix.getRaw( 2 )) + (this->getRaw( 1 ) * matrix.getRaw( 5 )) + (this->getRaw( 2 ) * matrix.getRaw( 8 )) );

        resultantMatrix.setRaw( 3, (this->getRaw( 3 ) * matrix.getRaw( 0 )) + (this->getRaw( 4 ) * matrix.getRaw( 3 )) + (this->getRaw( 5 ) * matrix.getRaw( 6 )) );
        resultantMatrix.setRaw( 4, (this->getRaw( 3 ) * matrix.getRaw( 1 )) + (this->getRaw( 4 ) * matrix.getRaw( 4 )) + (this->getRaw( 5 ) * matrix.getRaw( 7 )) );
        resultantMatrix.setRaw( 5, (this->getRaw( 3 ) * matrix.getRaw( 2 )) + (this->getRaw( 4 ) * matrix.getRaw( 5 )) + (this->getRaw( 5 ) * matrix.getRaw( 8 )) );

        resultantMatrix.setRaw( 6, (this->getRaw( 6 ) * matrix.getRaw( 0 )) + (this->getRaw( 7 ) * matrix.getRaw( 3 )) + (this->getRaw( 8 ) * matrix.getRaw( 6 )) );
        resultantMatrix.setRaw( 7, (this->getRaw( 6 ) * matrix.getRaw( 1 )) + (this->getRaw( 7 ) * matrix.getRaw( 4 )) + (this->getRaw( 8 ) * matrix.getRaw( 7 )) );
        resultantMatrix.setRaw( 8, (this->getRaw( 6 ) * matrix.getRaw( 2 )) + (this->getRaw( 7 ) * matrix.getRaw( 5 )) + (this->getRaw( 8 ) * matrix.getRaw( 8 )) );

        return resultantMatrix;
    };


};


/**
 * @brief 
 * A matrix of 4 X 4 size.
 * 
 * Initialises as an identity matrix, with 1 along the left -> right diagonal.
 *
 * @details 
 * Values are set to float 1.0 originally, if the `valueType` can't support that type conversion, the matrix will crash.
 * 
 * @tparam valueType Type of the values in the matrix e.g( float, int )
 */
template< typename valueType >
class Matrix4x4 : public Matrix< valueType, 4, 4 >{

private:

    uint8_t rows = 4;
    uint8_t cols = 4;

    /** Stores the matrix data in a 1D `valueType` array.  */
    std::array< valueType, 16 > data = { 
        1.0, 0.0, 0.0, 0.0, 
        0.0, 1.0, 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };


public:

    // Keeps original `multiply`, so this class can use both. 
    using Matrix<valueType, 4, 4>::multiply;

    /**
     * @brief Default constructor
     */
    Matrix4x4(){};


    ~Matrix4x4() = default;
    
    /**
     * @brief Allows the use of `<iostream>` to print this object.
     * 
     * @param os Output stream object.
     * @param obj Object to output into stream.
     * 
     * @returns `ostream` Output stream object. 
     */
    friend std::ostream& operator<<( std::ostream& os, const Matrix4x4<valueType> obj ){

        os << "Matrix4x4: \n";
        os << "|" << obj.getRaw(0)  << "," << obj.getRaw(1)  << "," << obj.getRaw(2)  << "," << obj.getRaw(3)  << "|" << "\n";
        os << "|" << obj.getRaw(4)  << "," << obj.getRaw(5)  << "," << obj.getRaw(6)  << "," << obj.getRaw(7)  << "|" << "\n";
        os << "|" << obj.getRaw(8)  << "," << obj.getRaw(9)  << "," << obj.getRaw(10) << "," << obj.getRaw(11) << "|" << "\n";
        os << "|" << obj.getRaw(12) << "," << obj.getRaw(13) << "," << obj.getRaw(14) << "," << obj.getRaw(15) << "|";
        
        return os;
    }

    // Getters

    /**
     * @brief Returns the number of rows in the matrix.
     * 
     * @returns `uint8_t` Number of rows.
     */
    uint8_t getRows(){
        
        return rows;
    };

    /**
     * @brief Returns the const number of rows in the matrix.
     * 
     * @returns `const uint8_t` Number of rows.
     */
    const uint8_t getRows() const{
        
        return rows;
    };


    /**
     * @brief Returns the number of columns in the matrix.
     * 
     * @returns `uint8_t` Number of columns.
     */
    uint8_t getCols(){

        return cols;
    };

    /**
     * @brief Returns the const number of columns in the matrix.
     * 
     * @returns `const uint8_t` Number of columns.
     */
    const uint8_t getCols() const{

        return cols;
    };



    /**
     * @brief Retrieves the integer value at matrix pos `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `valueType` Value at `indexRow`, `indexCol`
     */
    valueType get( uint8_t indexRow, uint8_t indexCol ){

        return data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ];
    };

    /**
     * @brief Retrieves the const integer value at matrix pos `indexRow`, `indexCol`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * 
     * @return `const valueType` Value at `indexRow`, `indexCol`
     */
    const valueType get( uint8_t indexRow, uint8_t indexCol ) const{

        return data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ];
    };

    /**
     * @brief Retrieves the integer value at array index `index`.
     * 
     * @param indexRow Raw array index
     * 
     * @return `valueType` Value at `index`
     */
    valueType getRaw( uint8_t index ){

        return data[ index ];
    };

    /**
     * @brief Retrieves the const integer value at array index `index`.
     * 
     * @param indexRow Raw array index
     * 
     * @return `const valueType` Value at `index`
     */
    const valueType getRaw( uint8_t index ) const{
 
        return data[ index ];
    };


    // Setters

    /**
     * @brief Sets the value of the matrix pos `indexRow`, `indexCol` to `value`.
     * 
     * @param indexRow Row index
     * @param indexCol Column index
     * @param value New value to set
     * 
     */
    void set( uint8_t indexRow, uint8_t indexCol, valueType value ){

        data[ indexRow * ( rows - 1 ) + ( cols - 1 ) ] = value;
    };

    /**
     * @brief Sets the value of the array index `index` to `value`.
     * 
     * @param index Array index
     * @param value New value to set
     * 
     */
    void setRaw( uint8_t index, valueType value ){

        data[ index ] = value;
    };


    // Multiplication

    /**
     * @brief Returns a 4x4 matrix and vector4 multiplication. ( NewMatrix = This X Vector4 )
     * 
     * @param vector Vector to multiply to this. ( Vector to translate )
     * 
     * @returns `Vector4` New vector translated by this matrix.
     */
    Vector4 multiplyVector( Vector4 vector ){

        Vector4 resultVector = Vector4( 0.f, 0.f, 0.f, 0.f );

        resultVector.x = ( getRaw(0)  * vector.x + getRaw(1)  * vector.y + getRaw(2)  * vector.z + getRaw(3)  * vector.w );
        resultVector.y = ( getRaw(4)  * vector.x + getRaw(5)  * vector.y + getRaw(6)  * vector.z + getRaw(7)  * vector.w );
        resultVector.z = ( getRaw(8)  * vector.x + getRaw(9)  * vector.y + getRaw(10) * vector.z + getRaw(11) * vector.w );
        resultVector.w = ( getRaw(12) * vector.x + getRaw(13) * vector.y + getRaw(14) * vector.z + getRaw(15) * vector.w );

        return resultVector;
    };


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

        resultantMatrix.setRaw( 0,  (this->getRaw( 0 ) * matrix.getRaw( 0 )) + (this->getRaw( 1 ) * matrix.getRaw( 4 )) + (this->getRaw( 2 ) * matrix.getRaw( 8 ))  + (this->getRaw( 3 ) * matrix.getRaw( 12 )) );
        resultantMatrix.setRaw( 1,  (this->getRaw( 0 ) * matrix.getRaw( 1 )) + (this->getRaw( 1 ) * matrix.getRaw( 5 )) + (this->getRaw( 2 ) * matrix.getRaw( 9 ))  + (this->getRaw( 3 ) * matrix.getRaw( 13 )) );
        resultantMatrix.setRaw( 2,  (this->getRaw( 0 ) * matrix.getRaw( 2 )) + (this->getRaw( 1 ) * matrix.getRaw( 6 )) + (this->getRaw( 2 ) * matrix.getRaw( 10 )) + (this->getRaw( 3 ) * matrix.getRaw( 14 )) );
        resultantMatrix.setRaw( 3,  (this->getRaw( 0 ) * matrix.getRaw( 3 )) + (this->getRaw( 1 ) * matrix.getRaw( 7 )) + (this->getRaw( 2 ) * matrix.getRaw( 11 )) + (this->getRaw( 3 ) * matrix.getRaw( 15 )) );

        resultantMatrix.setRaw( 4,  (this->getRaw( 4 ) * matrix.getRaw( 0 )) + (this->getRaw( 5 ) * matrix.getRaw( 4 )) + (this->getRaw( 6 ) * matrix.getRaw( 8 ))  + (this->getRaw( 7 ) * matrix.getRaw( 12 )) );
        resultantMatrix.setRaw( 5,  (this->getRaw( 4 ) * matrix.getRaw( 1 )) + (this->getRaw( 5 ) * matrix.getRaw( 5 )) + (this->getRaw( 6 ) * matrix.getRaw( 9 ))  + (this->getRaw( 7 ) * matrix.getRaw( 13 )) );
        resultantMatrix.setRaw( 6,  (this->getRaw( 4 ) * matrix.getRaw( 2 )) + (this->getRaw( 5 ) * matrix.getRaw( 6 )) + (this->getRaw( 6 ) * matrix.getRaw( 10 )) + (this->getRaw( 7 ) * matrix.getRaw( 14 )) );
        resultantMatrix.setRaw( 7,  (this->getRaw( 4 ) * matrix.getRaw( 3 )) + (this->getRaw( 5 ) * matrix.getRaw( 7 )) + (this->getRaw( 6 ) * matrix.getRaw( 11 )) + (this->getRaw( 7 ) * matrix.getRaw( 15 )) );

        resultantMatrix.setRaw( 8,  (this->getRaw( 8 ) * matrix.getRaw( 0 )) + (this->getRaw( 9 ) * matrix.getRaw( 4 )) + (this->getRaw( 10 ) * matrix.getRaw( 8 )) + (this->getRaw( 11 ) * matrix.getRaw( 12 )) );
        resultantMatrix.setRaw( 9,  (this->getRaw( 8 ) * matrix.getRaw( 1 )) + (this->getRaw( 9 ) * matrix.getRaw( 5 )) + (this->getRaw( 10 ) * matrix.getRaw( 9 )) + (this->getRaw( 11 ) * matrix.getRaw( 13 )) );
        resultantMatrix.setRaw( 10, (this->getRaw( 8 ) * matrix.getRaw( 2 )) + (this->getRaw( 9 ) * matrix.getRaw( 6 )) + (this->getRaw( 10 ) * matrix.getRaw( 10 )) + (this->getRaw( 11 ) * matrix.getRaw( 14 )) );
        resultantMatrix.setRaw( 11, (this->getRaw( 8 ) * matrix.getRaw( 3 )) + (this->getRaw( 9 ) * matrix.getRaw( 7 )) + (this->getRaw( 10 ) * matrix.getRaw( 11 )) + (this->getRaw( 11 ) * matrix.getRaw( 15 )) );

        resultantMatrix.setRaw( 12, (this->getRaw( 12 ) * matrix.getRaw( 0 )) + (this->getRaw( 13 ) * matrix.getRaw( 4 )) + (this->getRaw( 14 ) * matrix.getRaw( 8 ))  + (this->getRaw( 15 ) * matrix.getRaw( 12 )) );
        resultantMatrix.setRaw( 13, (this->getRaw( 12 ) * matrix.getRaw( 1 )) + (this->getRaw( 13 ) * matrix.getRaw( 5 )) + (this->getRaw( 14 ) * matrix.getRaw( 9 ))  + (this->getRaw( 15 ) * matrix.getRaw( 13 )) );
        resultantMatrix.setRaw( 14, (this->getRaw( 12 ) * matrix.getRaw( 2 )) + (this->getRaw( 13 ) * matrix.getRaw( 6 )) + (this->getRaw( 14 ) * matrix.getRaw( 10 )) + (this->getRaw( 15 ) * matrix.getRaw( 14 )) );
        resultantMatrix.setRaw( 15, (this->getRaw( 12 ) * matrix.getRaw( 3 )) + (this->getRaw( 13 ) * matrix.getRaw( 7 )) + (this->getRaw( 14 ) * matrix.getRaw( 11 )) + (this->getRaw( 15 ) * matrix.getRaw( 15 )) );

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
    void scale( valueType x, valueType y, valueType z ){

        setRaw( 0, getRaw(0) * x );
        setRaw( 5, getRaw(5) * y );
        setRaw( 10, getRaw(10) * z );
    };
    

    /**
     * @brief Translates this matrix by the `x`, `y`, `z` values
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
    void translate( valueType x, valueType y, valueType z ){
 
        setRaw( 3, getRaw(3) + x );
        setRaw( 7, getRaw(7) + y );
        setRaw( 11, getRaw(11) + z );
    };


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
     * @param radians Rotation angle around x, in radians
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateX( float radians ){

        setRaw( 5, ( getRaw(5) * cos( radians ) ) );
        setRaw( 6, ( getRaw(6) * -1 * sin( radians ) ) );

        setRaw( 9, ( getRaw(9) * sin( radians ) ) );
        setRaw( 10, ( getRaw(10) * cos( radians ) ) );

        return *this;

    };

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
     * @param radians Rotation angle around y, in radians
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateY( float radians ){

        setRaw( 0, ( getRaw(0) * cos( radians ) ) );
        setRaw( 2, ( getRaw(2) * sin( radians ) ) );

        setRaw( 8, ( getRaw(8) * -1 * sin( radians ) ) );
        setRaw( 10, ( getRaw(10) * cos( radians ) ) );

        return *this;

    };

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
     * @param radians Rotation angle around z, in radians
     * 
     * @returns `Matrix4x4<valueType>` New matrix rotated.
     */
    Matrix4x4<valueType> rotateZ( float radians ){

        setRaw( 0, ( getRaw(0) * cos( radians ) ) );
        setRaw( 1, ( getRaw(1) * -1 * sin( radians ) ) );

        setRaw( 4, ( getRaw(4) * sin( radians ) ) );
        setRaw( 5, ( getRaw(5) * cos( radians ) ) );

        return *this;
    };


};

