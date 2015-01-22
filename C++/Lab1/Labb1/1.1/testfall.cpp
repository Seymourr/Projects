#ifndef MATRIX_TEST_H_INCLUDED
#define MATRIX_TEST_H_INCLUDED
#include "Matrix.h"
#include "/info/cprog09/cxxtest/cxxtest/TestSuite.h"
#include <fstream>
#include <sstream>

using namespace std;
class MatrixTestSuite : public CxxTest::TestSuite {


Matrix mAny(string matrix) {
	Matrix m;
	stringstream s(matrix);
	s >> m;
	return m;
}
Matrix m2by2first() {
	Matrix m;
	stringstream s("[ 3 4 ; 5 6 ]");
	s >> m;
	return m;
}

Matrix m2by2second() {
	Matrix m;
	stringstream s("[ -133 0 ; -5 6 ]");
	s >> m;
	return m;
}

Matrix m3by3first() {
	Matrix m;
	stringstream s("[ 1 23 4 ; -1 2 3 ; 55  6 6 ]");
	s >> m;
	return m;
}

Matrix m3by3second() {
	Matrix m;
	stringstream s("[ 0 0 -1 ; 0 0 2 ; 0  1 1 ]");
	s >> m;
	return m;
}

Matrix m2by3first() {
	Matrix m;
	stringstream s("[ 11 1000 -1 ; 0  1 1 ]");
	s >> m;
	return m;
}

Matrix m0by0() {
	Matrix m;
	stringstream s("[]");
	s >> m;
	return m;
}

Matrix identity(const Matrix & someM) {
	if(someM.rows() != someM.cols()) {
			throw std::out_of_range("Not the same dimensions for rows and columns");
		} 
		Matrix m(someM.rows(), someM.cols());

		for(int i = 0; i < someM.rows(); ++i) {
			m[i][i] = 1;
		}
		return m;
}
public: 
void testCreation() {
	Matrix  m1;
	Matrix m2 = m1;
	Matrix m3(1,5);
	Matrix m4(55);
	TS_ASSERT(m1.rows() == 0 && m1.cols() == 0);
	TS_ASSERT(m2.rows() == 0 && m2.cols() == 0);
	TS_ASSERT(m3.rows() == 1 && m3.cols() == 5);
	TS_ASSERT(m4.rows() == 55 && m4.cols() == 55);
	m1 = m2by2first();
	TS_ASSERT(m1.rows() == 2 && m1.cols() == 2);
	TS_ASSERT(m1[0][0] == 3);
	TS_ASSERT(m1[0][1] == 4);
	TS_ASSERT(m1[1][0] == 5);
	TS_ASSERT(m1[1][1] == 6);

	m1 = m3by3first();
	TS_ASSERT(m1.rows() == 3 && m1.cols() == 3);
	TS_ASSERT(m1[0][0] == 1);
	TS_ASSERT(m1[0][1] == 23);
	TS_ASSERT(m1[0][2] == 4);
	TS_ASSERT(m1[1][0] == -1);
	TS_ASSERT(m1[1][1] == 2);
	TS_ASSERT(m1[1][2] == 3);	
	TS_ASSERT(m1[2][0] == 55);
	TS_ASSERT(m1[2][1] == 6);
	TS_ASSERT(m1[2][2] == 6);

	m1 = m2by3first();
	TS_ASSERT(m1[0][0] == 11);
	TS_ASSERT(m1[0][1] == 1000);
	TS_ASSERT(m1[0][2] == -1);
	TS_ASSERT(m1[1][0] == 0);
	TS_ASSERT(m1[1][1] == 1);
	TS_ASSERT(m1[1][2] == 1);	


	Matrix m6 = m1;
	TS_ASSERT(m6[0][0] == 11);
	TS_ASSERT(m6[0][1] == 1000);
	TS_ASSERT(m6[0][2] == -1);
	TS_ASSERT(m6[1][0] == 0);
	TS_ASSERT(m6[1][1] == 1);
	TS_ASSERT(m6[1][2] == 1);	

	//Specialfall
	Matrix m5(1,1);
	TS_ASSERT(m5.rows() == 1 && m5.cols() == 1);
	TS_ASSERT(m5[0][0] == 0);
	m5[0][0] = 1337;
	TS_ASSERT(m5[0][0] == 1337);
	m5[0][0] = -1;
	TS_ASSERT(m5[0][0] == -1);

	m5 = m0by0();
	TS_ASSERT(m5.rows() == 0 && m5.cols() == 0);
	Matrix m7(0, 0);
	TS_ASSERT(m7.rows() == 0 && m7.cols() == 0);
	
	}

void testAccess() {
	Matrix m1(1,1);
	m1[0][0] = 123;
	TS_ASSERT(m1[0][0] == 123);
	m1[0][0] =	-123 ;
	TS_ASSERT(m1[0][0] == -123);	

	Matrix m2 = m3by3first();
	m2[2][2] = 0;
	m2[2][2] = 3;
	m2[2][2] = 1337;
	m2[2][2] = (-1* m2[2][2]);
	TS_ASSERT(m2[2][2] == -1337);

	m2[0][0] = 33;
	m2[0][0] = -33;
	m2[0][0] = m2[0][0];
	m2[0][0] = m2[0][0] + 1;
	TS_ASSERT(m2[0][0] == -32);
}

void testFailAccess() {
	Matrix m1;
	Matrix m2(1,1);
	Matrix m3 = m3by3first();


	TS_ASSERT_THROWS_ANYTHING(m1[0][0]);
	TS_ASSERT_THROWS_ANYTHING(m1[-1][2]);
	TS_ASSERT_THROWS_ANYTHING(m1[33][2]);

	TS_ASSERT(m2[0][0] == 0);
	TS_ASSERT_THROWS_ANYTHING(m2[1][1]);
	TS_ASSERT_THROWS_ANYTHING(m2[2][2]);
	TS_ASSERT_THROWS_ANYTHING(m2[-1][-1]);


	TS_ASSERT(m3[0][0] == 1);
	m3[0][0] = 3;
	TS_ASSERT(m3[0][0] == 3);
	TS_ASSERT_THROWS_ANYTHING(m3[3][0]);
	TS_ASSERT_THROWS_ANYTHING(m3[4][0]);
	TS_ASSERT_THROWS_ANYTHING(m3[3][3]);
}

void testAssignment() {
	Matrix m1(2,2);
	m1[0][0] = 1;
	m1[0][1] = 2;
	m1[1][0] = 3;
	m1[1][1] = 4;

	Matrix m2;
	m2 = m1;
	TS_ASSERT(m2[0][0] == 1);
	TS_ASSERT(m2[0][1] == 2);
	TS_ASSERT(m2[1][0] == 3);
	TS_ASSERT(m2[1][1] == 4);
	TS_ASSERT(m2.cols() == 2 && m2.rows() == 2);

	Matrix m3(1,1);
	m3[0][0] = 1337;
	m2 = m3;
	TS_ASSERT(m2[0][0] == 1337);
	TS_ASSERT(m2.cols() == 1 && m2.rows() == 1);
	TS_ASSERT_THROWS_ANYTHING(m2[1][0]);	

	Matrix m4;
	m2 = m4;
	TS_ASSERT(m2.cols() == 0 && m2.rows() == 0);
	TS_ASSERT_THROWS_ANYTHING(m2[0][0]);

	Matrix m5 = m3by3first();
	m2 = m5;
	for(int i = 0; i < m2.rows(); ++i) {
		for(int j = 0; j < m2.cols(); ++j) {
			TS_ASSERT(m2[i][j] == m5[i][j]);
		}
	}
}

void testMatrixAddition() {
	Matrix m1(1,1);
	m1[0][0] = 1;
	Matrix m2(1,1);
	m2 = m2 + m1;
	TS_ASSERT(m2[0][0] == 1);
	m2 = m2 + m2;
	TS_ASSERT(m2[0][0] == 2);

	m2 = m2 + m2 + m2 + m2 + m2 + m2;
	TS_ASSERT(m2[0][0] == 12);

	Matrix t3 = mAny("[ 0 0 0 3 0 ]");
	Matrix t4 = mAny("[ 1 1 1 0 1 ]");
	t3 = t4 + t3;
	TS_ASSERT(t3[0][3] == 3);
	Matrix m3 = m3by3first();

	Matrix m4 = m3by3second();
	Matrix m5;
	m5 = (m3 + m4);
	TS_ASSERT(m5[0][0] == 1);
	TS_ASSERT(m5[0][1] == 23);
	TS_ASSERT(m5[0][2] == 3);

	TS_ASSERT(m5[1][0] == -1);
	TS_ASSERT(m5[1][1] == 2);
	TS_ASSERT(m5[1][2] == 5);

	TS_ASSERT(m5[2][0] == 55);
	TS_ASSERT(m5[2][1] == 7);
	TS_ASSERT(m5[2][2] == 7);
		
}

void testMatrixSubstraction() {
	Matrix m1(1,1);
	m1[0][0] = 1;
	m1 = (m1 - m1);
	TS_ASSERT(m1[0][0] == 0);
	m1 = (m1 - m1);
	TS_ASSERT(m1[0][0] == 0);

	Matrix m2(1,1);
	m2[0][0] = 1;
	m1[0][0] = -1;
	m2 = m2 - m1;
	m2 = m2 - m1;
	m2 = m2 - m1;
	m2 = m2 - m1;

	TS_ASSERT(m2[0][0] == 5);
	Matrix m3 = m3by3first();
	Matrix m4 = m3by3second();
	Matrix m5;
	m5 = (m3 - m4);

	TS_ASSERT(m5[0][0] == 1);
	TS_ASSERT(m5[0][1] == 23);
	TS_ASSERT(m5[0][2] == 5);

	TS_ASSERT(m5[1][0] ==-1);
	TS_ASSERT(m5[1][1] == 2);
	TS_ASSERT(m5[1][2] == 1);

	TS_ASSERT(m5[2][0] == 55);
	TS_ASSERT(m5[2][1] == 5);
	TS_ASSERT(m5[2][2] == 5);

	Matrix m6 = mAny("[ 1 2 3 ]");
	Matrix m7 = mAny("[ 2 3 4 ]");
	m6 = m7 - m6;

	TS_ASSERT(m6[0][0] == 1);
	TS_ASSERT(m6[0][1] == 1);
	TS_ASSERT(m6[0][2] == 1);
}

void testMatrixMult() {
	Matrix m1(1,1);
	m1[0][0] = 12;
	Matrix m2 = m1;
	m2 = m2 * m1;
	TS_ASSERT(m2[0][0] = 144);
	m1[0][0] = -12;
	m2 = m1 * m1;
	TS_ASSERT(m2[0][0] = 144);


	Matrix m3 = m3by3first();
	m3 = m3 * m3;
	TS_ASSERT(m3[0][0] == 198);
	TS_ASSERT(m3[0][1] == 93);	
	TS_ASSERT(m3[0][2] == 97);

	TS_ASSERT(m3[1][0] == 162);
	TS_ASSERT(m3[1][1] == -1);	
	TS_ASSERT(m3[1][2] == 20);

	TS_ASSERT(m3[2][0] == 379);
	TS_ASSERT(m3[2][1] == 1313);	
	TS_ASSERT(m3[2][2] == 274);	


	TS_ASSERT(m3.rows() == 3 && m3.cols() == 3);
	Matrix m4 = m2by3first();
	m4 = m4 * m3by3second();	
	TS_ASSERT(m4[0][0] == 0);
	TS_ASSERT(m4[0][1] == -1);	
	TS_ASSERT(m4[0][2] == 1988);

	TS_ASSERT(m4[1][0] == 0);
	TS_ASSERT(m4[1][1] == 1);	
	TS_ASSERT(m4[1][2] == 3);
	TS_ASSERT(m4.rows() == 2 && m4.cols() == 3);

	Matrix m5 = m2by2first();
	m5 = m5 * m5;
	TS_ASSERT(m5[0][0] == 29);
	TS_ASSERT(m5[0][1] == 36);
	TS_ASSERT(m5[1][0] == 45);
	TS_ASSERT(m5[1][1] == 56);

	Matrix m6= m2by2second();
	Matrix t1 = mAny("[ 1 1 ; 1 1 ]");
	m6 = m6 * t1;
	TS_ASSERT(m6[0][0] == -133);
	TS_ASSERT(m6[0][1] == -133);
	TS_ASSERT(m6[1][0] == 1);
	TS_ASSERT(m6[1][1] == 1);
	cout << m4 << endl;

}

void testScalarMult() {
	Matrix m1 = mAny("[ 1 ]");
	m1 = m1 * 20;
	TS_ASSERT(m1[0][0] == 20);

	Matrix m2 = m2by2second();
	m2 = m2 * 100;
	TS_ASSERT(m2[0][0] == -13300);
	TS_ASSERT(m2[0][1] == 0);
	TS_ASSERT(m2[1][0] == -500);
	TS_ASSERT(m2[1][1] == 600);		

	m2 = m2 * -1;
	TS_ASSERT(m2[0][0] == 13300);
	TS_ASSERT(m2[0][1] == 0);
	TS_ASSERT(m2[1][0] == 500);
	TS_ASSERT(m2[1][1] == -600);	
	m2 = m2 * 0;
	TS_ASSERT(m2[0][0] == 0);
	TS_ASSERT(m2[0][1] == 0);
	TS_ASSERT(m2[1][0] == 0);
	TS_ASSERT(m2[1][1] == 0);	
	Matrix m3 = mAny("[ 3 44 -3 ; 0 3 2 ; 0 1 0 ]");
	m3 = m3 * 2;
	TS_ASSERT(m3[0][0] == 6);
	TS_ASSERT(m3[0][1] == 88);	
	TS_ASSERT(m3[0][2] == -6);

	TS_ASSERT(m3[1][0] == 0);
	TS_ASSERT(m3[1][1] == 6);	
	TS_ASSERT(m3[1][2] == 4);

	TS_ASSERT(m3[2][0] == 0);
	TS_ASSERT(m3[2][1] == 2);	
	TS_ASSERT(m3[2][2] == 0);			
}

void testNegation(){
	Matrix m1(1,1);
	m1[0][0] = 42;
	m1 = -m1;
	TS_ASSERT(m1[0][0] == -42);
	m1 = m1 +(-m1);
	TS_ASSERT(m1[0][0] == 0);

	Matrix m2 = -m3by3first();
	Matrix t1 = m3by3first();
	for(int i = 0; i < m2.rows(); ++i) {
		for(int j = 0; j < m2.cols(); ++j) {
			TS_ASSERT(m2[i][j] == (t1[i][j] * -1));
		}
	}
}

void testTransposition() {
	Matrix m1(1,1);
	m1[0][0] = 42;
	m1 = m1.transpose();

	TS_ASSERT(m1[0][0] == 42);
	TS_ASSERT(m1.rows() == 1 && m1.cols() == 1);

	Matrix m2 = m2by2first().transpose();

	TS_ASSERT(m2[0][0] == 3);
	TS_ASSERT(m2[0][1] == 5);
	TS_ASSERT(m2[1][0] == 4);
	TS_ASSERT(m2[1][1] == 6);
	TS_ASSERT(m2.rows() == 2 && m2.cols() == 2);

	Matrix m3 = mAny("[ 2 2 1 3 -1 ]");
	TS_ASSERT(m3.rows() == 1 && m3.cols() == 5);
	m3 = m3.transpose();
	TS_ASSERT(m3.rows() == 5 && m3.cols() == 1);
	TS_ASSERT(m3[0][0] == 2);
	TS_ASSERT(m3[1][0] == 2);
	TS_ASSERT(m3[2][0] == 1);
	TS_ASSERT(m3[3][0] == 3);
	TS_ASSERT(m3[4][0] == -1);

	Matrix m4 = m3by3second().transpose();
	TS_ASSERT(m4[0][0] == 0);
	TS_ASSERT(m4[0][1] == 0);
	TS_ASSERT(m4[0][2] == 0);
	TS_ASSERT(m4[1][0] == 0);
	TS_ASSERT(m4[1][1] == 0);
	TS_ASSERT(m4[1][2] == 1);
	TS_ASSERT(m4[2][0] == -1);
	TS_ASSERT(m4[2][1] == 2);
	TS_ASSERT(m4[2][2] == 1);
	TS_ASSERT(m4.cols() == 3 && m4.rows() == 3);

	Matrix m5 = m2by3first();
	TS_ASSERT(m5.cols() == 3 && m5.rows() == 2);
	m5 = m5.transpose();
	TS_ASSERT(m5.cols() == 2 && m5.rows() == 3);
	TS_ASSERT(m5[0][0] == 11);
	TS_ASSERT(m5[0][1] == 0);
	TS_ASSERT(m5[1][0] == 1000);
	TS_ASSERT(m5[1][1] == 1);
	TS_ASSERT(m5[2][0] == -1);
	TS_ASSERT(m5[2][1] == 1);
}

void testIdentity() {
	Matrix m1(1,1);
	m1 = identity(m1);
	TS_ASSERT(m1.rows() == 1 && m1.cols() == 1);
	TS_ASSERT(m1[0][0] == 1);

	Matrix m2 = m2by2first();
	Matrix t1(2,2);
	t1 = identity(t1);
	m2 = m2 * t1;
	TS_ASSERT(m2[0][0] == 3);
	TS_ASSERT(m2[0][1] == 4);
	TS_ASSERT(m2[1][0] == 5);
	TS_ASSERT(m2[1][1] == 6);

	Matrix m3 = m3by3first();
	Matrix t2(3,3);
	t2 = identity(t2);
	m3 = m3 * t2;
	TS_ASSERT(m3[0][0] == 1);
	TS_ASSERT(m3[0][1] == 23);
	TS_ASSERT(m3[0][2] == 4);
	TS_ASSERT(m3[1][0] == -1);
	TS_ASSERT(m3[1][1] == 2);
	TS_ASSERT(m3[1][2] == 3);
	TS_ASSERT(m3[2][0] == 55);
	TS_ASSERT(m3[2][1] == 6);
	TS_ASSERT(m3[2][2] == 6);
	TS_ASSERT(m3.rows() == 3 && m3.cols() == 3);
}

void testStreams() {
	stringstream ss;
	char ngt[256];
	string matrixString = "";

	Matrix m1 = m3by3first();
	ss << m1 << endl;
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "[ 1 23 4 " ||matrixString == "[_1_23_4_");
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "; -1 2 3 " ||matrixString == ";_-1_2_3_");
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "; 55 6 6 ]" ||matrixString == ";_55_6_6_]");
	//Glöm inte understreck

	TS_ASSERT(m1[0][0] == 1);
	TS_ASSERT(m1[0][1] == 23);
	TS_ASSERT(m1[0][2] == 4);
	TS_ASSERT(m1[1][0] == -1);
	TS_ASSERT(m1[1][1] == 2);
	TS_ASSERT(m1[1][2] == 3);
	TS_ASSERT(m1[2][0] == 55);
	TS_ASSERT(m1[2][1] == 6);
	TS_ASSERT(m1[2][2] == 6);
	TS_ASSERT(m1.rows() == 3 && m1.cols() == 3);

	m1 = m2by3first();
	ss << m1 << endl;
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "[ 11 1000 -1 " ||matrixString == "[_11_1000_-1_");

	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "; 0 1 1 ]" ||matrixString == ";_0_1_1_]");

	TS_ASSERT(m1.rows() == 2 && m1.cols() == 3);

	m1 = m2by2first();
	ss << m1 << endl;
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "[ 3 4 " ||matrixString == "[_3_4_");
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "; 5 6 ]" ||matrixString == ";_5_6_]");
	TS_ASSERT(m1.rows() == 2 && m1.cols() == 2);

	m1 = mAny("[ 1 ]");
	ss << m1 << endl;
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "[ 1 ]" || matrixString == "[_1_]");
	TS_ASSERT(m1.rows() == 1 && m1.cols() == 1);

	Matrix m2;
	ss << m2 << endl;
	ss.getline(ngt, 256);
	matrixString = ngt;
	TS_ASSERT(matrixString == "[ ]" || matrixString == "[_]");
	TS_ASSERT(m2.rows() == 0 && m2.cols() == 0);
}

void testFails() {
	Matrix m1 = m2by2first();
	Matrix m2 = m3by3first();
	TS_ASSERT_THROWS_ANYTHING(m1 * m2);
	TS_ASSERT_THROWS_ANYTHING(m1 - m2);
	TS_ASSERT_THROWS_ANYTHING(m1 + m2);
}
};
#endif


