/* Matrix.h
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		10/31/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/

#include<iostream>

class Matrix
{
private:
	double * m_array;   // Array containing the elements of the matrix
	unsigned m_rows,         // Number of rows in matrix
			 m_columns,      // Number of columns in matrix
			 m_size;         // Number of elements in matrix (m_columns*m_rows)
public:
	// Constructors
	Matrix();
	Matrix(const double p_array[], unsigned p_r, unsigned p_c);
	Matrix(const Matrix & orig);
	~Matrix();
	// Accessors
	unsigned getNumOfRows() const;
	unsigned getNumOfCols() const;
	unsigned getSize() const;
	double getElement(unsigned p_row, unsigned p_column) const;
	// Mutators
	void interchange(unsigned p_r1, unsigned p_r2);
	void rowScalar(unsigned p_row, double p_multiplier);
	void replacement(unsigned p_rowDest, unsigned p_row, double p_multiplier);
	void matrixScalar(double p_multiplier);
	void setElement(double p_term, unsigned p_r, unsigned p_c);
	void setRow(const double p_array[], unsigned p_size, unsigned p_rowNum);
	void setColumn(const double p_array[], unsigned p_size, unsigned p_colNum);
	void resetMatrix(const double p_array[], unsigned p_r, unsigned p_c);

	// Matrix Operations


	// Overloaded Operators
	// Operations
	bool checkOperation(const Matrix & other, char oper);
	Matrix operator+(const Matrix & p_term);
	Matrix operator-(const Matrix & p_term);
	Matrix operator*(const Matrix & p_term);
	Matrix & operator=(const Matrix & p_term);
	Matrix inverse();
	void augment(const Matrix & p_term);
	void transpose();
	void rref();
	bool operator==(const Matrix & p_term);
	bool operator!=(const Matrix & p_term);
	double determinant();

	// Display
	void displayMatrix(std::ostream & out);
};
// End of File
