#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <stdexcept>

template <class T>
class Vector : public std::vector< T > {
public:
    explicit Vector <T> (std::size_t size  = 0, T data = T()) : std::vector<T>(size, data) {}
    const T& operator[](unsigned int i) const throw(std::out_of_range) { //Designfel med throws?
        return this->at( i );
    }
    T& operator[](unsigned int i) throw(std::out_of_range) { //Designfel med throws?
        return this->at( i );
    }    
};
//Designfel 1: Använder std::vector 
//Designfel 2: Matrisen är inte en template klass för t.ex. float, double (Antaget att man endast önskar för heltal)
//using namespace std;

class Matrix
{
 public:
    typedef unsigned int index;
    
    class matrix_row : private Vector< int >
    {
    public:
        matrix_row( std::size_t s = 0) : Vector< int >( s ) {}
        using Vector<int>::operator [];
    private:
        friend std::istream& operator>>( std::istream&, Matrix& );
    };
    
    Matrix( );
    Matrix( std::size_t, std::size_t );
    Matrix( const Matrix& );
    Matrix(int size); //Designfel 3: Använder inte unsigned int, tillåter negativa storlekar (ger inkorrekt beteende)
    ~Matrix( );
    
    Matrix& operator= ( const Matrix& );
    Matrix operator+ ( const Matrix& ) const;
    Matrix operator* ( const Matrix& ) const;
    Matrix operator* ( int ) const;
    Matrix operator-( const Matrix& ) const;
    Matrix operator-( ) const;
    
    Matrix& transpose( ); //Designfel 4: Bör inte modifera matrisen, utan returnera kopia, inte referens
    //Identitet metod saknas? 
    matrix_row& operator[]( index i );
    const matrix_row& operator[]( index i ) const;
    
    std::size_t rows() const;
    std::size_t cols() const;
    
 protected: //Designfel 5: Subklasser bör vara under protected, inte publika
 private:
    Vector< matrix_row >        m_vectors;
    std::size_t                 m_rows;
    std::size_t                 m_cols;
    
    void add_row( );            // Non mandatory help function
    friend std::istream& operator>> ( std::istream&, Matrix& );
};

std::istream& operator>> ( std::istream&, Matrix& ) ;
std::ostream& operator<< ( std::ostream&, Matrix& ); 
Matrix operator* ( int, const Matrix& );

#endif // MATRIX_H
//Vad man borde kunna göra: tilldela genom [ 1 2 3 ; 2 3 4 ; 3 4 5] t.ex., men går inte.(Likt matlab)