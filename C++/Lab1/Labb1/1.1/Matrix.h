#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include "JVector.cpp"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>



//using namespace std;

class Matrix
{
 public:
    typedef unsigned int index;
    
    class matrix_row : private JVector< int >
    {
    public:
        matrix_row( std::size_t s = 0) : JVector< int >( s ) {}
        using JVector<int>::operator [];
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    Matrix();
    Matrix( std::size_t, std::size_t );
    Matrix( const Matrix& );
    Matrix(unsigned int size);
    ~Matrix( );
    
    Matrix& operator= ( const Matrix& );
    Matrix operator+ ( const Matrix& ) const;
    Matrix operator* ( const Matrix& ) const;
    Matrix operator* (int ) const;
    Matrix operator-( const Matrix& ) const;
    Matrix operator-( ) const; //Negation
    
    Matrix const transpose( ) const;
    Matrix const identity( ) const;
    
    matrix_row& operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    const std::size_t  rows() const;
    const std::size_t  cols() const;
    
 protected:
 private:
    JVector< matrix_row >        m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
 //   void add_row( );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );
};

std::istream& operator>> ( std::istream&, Matrix& );
std::ostream& operator<< ( std::ostream&, Matrix& );
Matrix operator* ( int a, const Matrix& b);

#endif // MATRIX_H

