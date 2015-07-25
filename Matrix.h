/* Matrix.h
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		7/25/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/

#include<iostream>
#include<iomanip>
using namespace std;

class Matrix
{
private:
	double * m_array;   // Array containing the elements of the matrix
	int m_rows,         // Number of rows in matrix
		m_columns,      // Number of columns in matrix
		m_size;         // Number of elements in matrix (m_columns*m_rows)
public:
	// Constructors
	Matrix();
	Matrix(const double p_array[], int p_r, int p_c);
	Matrix(const Matrix & orig);
	~Matrix();
	// Accessors
	int getNumOfRows() const;
	int getNumOfCols() const;
	int getSize() const;
	double getElement(int p_row, int p_column) const;
	// Mutators
	void interchange(int p_r1, int p_r2);
	void rowScalar(int p_row, double p_multiplier);
	void replacement(int p_rowDest, int p_row, double p_multiplier);
	void matrixScalar(double p_multiplier);
	void setElement(double p_term, int p_r, int p_c);
	void setRow(const double p_array[], int p_size, int p_rowNum);
	void setColumn(const double p_array[], int p_size, int p_colNum);
	void resetMatrix(const double p_array[], int p_r, int p_c);

	// Operations
	bool checkOperation(const Matrix & other, char oper);
	Matrix operator+(const Matrix & p_term);
	Matrix operator-(const Matrix & p_term);
	Matrix operator*(const Matrix & p_term);
	Matrix & operator=(const Matrix & p_term);
	Matrix inverse();
	void augment(const Matrix & p_term);
	void transpose();
	void ref();
	void rref();
	bool operator==(const Matrix & p_term);
	bool operator!=(const Matrix & p_term);
	double determinant();

	// Display
	void displayMatrix(ostream & out);
};
// End of File
