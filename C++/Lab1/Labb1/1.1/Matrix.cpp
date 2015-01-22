#include "Matrix.h"
#include <boost/algorithm/string.hpp>
	Matrix::Matrix() : m_rows (0){
		m_rows = 0;
		m_cols = 0;

	}

	Matrix::Matrix(std::size_t row, std::size_t col) {
		m_rows = row;
		m_cols = col;
		for(int i = 0; i < rows(); ++i) {
			m_vectors.push_back( matrix_row(col)); 
		}
	}

	Matrix::Matrix(const Matrix & otherMatrix) {
		m_rows = otherMatrix.rows();
		m_cols = otherMatrix.cols();
		m_vectors = otherMatrix.m_vectors;
	}

	Matrix::Matrix(unsigned int size) {
		m_rows = size;
		m_cols = size;
		m_vectors = JVector<matrix_row>(size);
		for(int i = 0; i < rows(); i++) {
			m_vectors.push_back( matrix_row(size));
		}

	}

	Matrix::~Matrix() {
		//Assume vector class fix memory problems
	}

	Matrix& Matrix::operator= (const Matrix& otherMatrix) {
		m_rows = otherMatrix.rows();
		m_cols = otherMatrix.cols();
		m_vectors = otherMatrix.m_vectors;
		return *this;
	}

	Matrix Matrix::operator+ (const Matrix & otherMatrix) const {
		Matrix m = (*this); //Copy of ours
		if(rows() == otherMatrix.rows() && cols() == otherMatrix.cols()) {
			for(int i = 0; i < rows(); ++i) {
				for(int j = 0; j < cols(); ++j) {
					m[i][j] = m[i][j] + otherMatrix[i][j];
				}
			}
		} else {
		throw std::out_of_range("Wrong dimensions on the other matrix");
		}
		return m;
	}

	Matrix Matrix::operator* (const Matrix& otherMatrix) const {
		Matrix m(rows(), otherMatrix.rows());
		if(cols() == otherMatrix.cols()) {
			for(int i = 0; i < rows(); ++i) {
				for(int j = 0; j < cols(); ++j) {
					for(int k = 0; k < otherMatrix.rows(); ++k) {
						m[i][j] += (*this)[i][k] * otherMatrix[k][j]; //Svår att implementera.. #mindfuck
					}
			}
		}
		} else {
		throw std::out_of_range("Wrong dimensions on the other matrix");
		}
		return m;
	}

	Matrix Matrix::operator*(int scalar) const {
		Matrix m = (*this);
		for(int i = 0; i < rows(); ++i) {
			for(int j = 0; j < cols(); ++j) {
				m[i][j] = m[i][j] * scalar;
			}
		}
		return m;
	}

	Matrix Matrix::operator-(const Matrix& otherMatrix) const {
		Matrix m = (*this); //Copy of ours
		if(rows() == otherMatrix.rows() && cols() == otherMatrix.cols()) {
			for(int i = 0; i < rows(); ++i) {
				for(int j = 0; j < cols(); ++j) {
					m[i][j] = m[i][j] - otherMatrix[i][j];
				}
			}
		} else {
		throw std::out_of_range("Wrong dimensions on the other matrix");
		}
		return m;
		//return operator+(-otherMatrix);
	}

	Matrix Matrix::operator-() const {
		return operator*(-1);
	}


	Matrix const Matrix::transpose() const{
		Matrix m(cols(), rows());

		for(int i = 0; i < rows(); ++i) {
			for(int j = 0; j < cols(); ++j) {
				m[j][i] = (*this)[i][j];
			}
		}
		return m;
	}

	Matrix const Matrix::identity() const {
		if(rows() != cols()) {
			throw std::out_of_range("Not the same dimensions for rows and columns");
		} 
		Matrix m(rows(), cols());

		for(int i = 0; i < rows(); ++i) {
			m[i][i] = 1;
		}
		return m;
	}



	Matrix::matrix_row& Matrix::operator[](index i){
		return m_vectors[i];
	}

	const Matrix::matrix_row& Matrix::operator[](index i) const{

		return m_vectors[i];
	}

	std::istream& operator>>(std::istream& istr , Matrix& toUpdate) {
		char indata[256];
		int i = 0;
		int j = 0;

		istr.getline(indata, 256);
		
		std::string buf; // Have a buffer string
    	std::stringstream ss(indata); // Insert the string into a stream

   		 JVector<std::string> tokens; // Create vector to hold our words

    	while (ss >> buf)
        tokens.push_back(buf);

    	//Count rows and cols..
    	int rowAmnt = 0;
    	int colAmnt = 0; //Only needed to compute once
    	bool countCol = true;
    	for(int i = 1; i < (tokens.size() - 1); ++i) { //Ignore "[" and "]"
    		if(tokens[i] == ";") {
    			rowAmnt = rowAmnt + 1;
    			countCol = false;
    		} else {
    			if(countCol) {
    				colAmnt = colAmnt + 1;
    			}
    		}
    	}
    	if(rowAmnt > 0 || colAmnt > 0) {
    		rowAmnt = rowAmnt + 1;
    	} 
    	Matrix m(rowAmnt, colAmnt);

    	std::string c;
    	int row = 0;
    	int col = 0;
		for(int i = 1; i < (tokens.size() - 1); ++i) {  //Ignore "[" and "]"
			c = tokens[i];
			if(c != ";") {
				m[row][col] = std::stoi(c);
				col = col + 1;
			} else {
				col = 0;
				row = row + 1;
			}
		}
		toUpdate = m;
		return istr;
	}

	std::ostream& operator<< (std::ostream& ostr, Matrix& m) {
		ostr << "[ "; //Första tecknet
		for(int i = 0; i < m.rows(); ++i) {
			for(int j=0; j < m.cols(); ++j) {
				ostr << m[i][j] << " ";
			}
			if(i + 1 != m.rows()) {
				//Dags för newline och ett ";" tecken
				ostr << "" << std::endl;
				ostr << "; ";
			}
		}

		ostr << "]"; //Sista tecknet
	}
	

	const std::size_t  Matrix::rows() const {
		return m_rows;
	}

	const std::size_t  Matrix::cols() const {
		return m_cols;
	}


	Matrix operator* ( int scalar, const Matrix& mat) {
		Matrix m = mat;
		for(int i = 0; i < mat.rows(); ++i) {
			for(int j = 0; j < mat.cols(); ++j) {
				m[i][j] = m[i][j] * scalar;
			}
		}
		return m;
	}
