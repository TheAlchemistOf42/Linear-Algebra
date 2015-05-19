/* Matrix.h
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		5/11/15
Description: A matrix object allowing one to do mathematics with matrices.
*/

#include<iostream>
using namespace std;

class Matrix
{
private:
    double * m_array;   // Array containin the elements of the matrix
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
    void setElement(double p_term, int p_r, int p_c);
    void setRow(const double p_array[], int p_size, int p_rowNum);
    void setColumn(const double p_array[], int p_size, int p_colNum);
    void resetMatrix(const double p_array[], int p_r, int p_c);
    // Operations
    bool checkOperation(const Matrix & first, const Matrix & second, char oper);
    Matrix & operator+(const Matrix & term);
    Matrix & operator-(const Matrix & term);
    Matrix & operator*(const Matrix & term);
    Matrix & operator=(const Matrix & term);
    bool operator==(const Matrix & term);
    bool operator!=(const Matrix & term);
    double determinant();
    // Display
    void displayMatrix(ostream & out);
};
// End of File
