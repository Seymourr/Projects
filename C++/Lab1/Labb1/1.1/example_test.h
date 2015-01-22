#ifndef MATRIX_TEST_H_INCLUDED
#define MATRIX_TEST_H_INCLUDED

#include "Matrix.h"
#include "/info/cprog09/cxxtest/cxxtest/TestSuite.h"
#include <fstream>
#include <sstream>

class MatrixTestSuite : public CxxTest::TestSuite
{

    Matrix a_matrix_3by2() { 
        std::cout << "Första" << std::endl;   
        Matrix m;   
         std::cout << "stream1" << std::endl;           
        std::cout << m << std::endl;
        std::cout << "stream" << std::endl;   
        std::stringstream s("  [ 1 3 5 ; 0 2 0 ]");
        s >> m;
        std::cout << "Andra" << std::endl;   
        std::cout << m << std::endl;
       
        return m;
    }

    void init_matrix( Matrix& m, const char* file )
    {
        std::stringstream stream( file );   
        stream >> m;
    }

public:
    void testIndexOperator ( )
    {
        Matrix m( 2, 2 );
        TS_ASSERT( m[ 0 ][ 1 ] == 0 );

        m = a_matrix_3by2();
        std::cout << m << std::endl;
        std::cout << m[0][0] << std::endl;
        std::cout << m[0][1] << std::endl;
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );

        init_matrix(m, "  [ 1 3 5 ; 0 2 1 ]");
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );

        std::stringstream ss;
        ss << m;
        ss >> m;
        TS_ASSERT( m[ 0 ][ 0 ] == 1 );
    }
};

#endif

