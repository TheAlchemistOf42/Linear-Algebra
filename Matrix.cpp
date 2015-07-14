/* Matrix.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		7/13/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/

/* To Do:
-Add documentation
-finish implmentation of Accessors and Mutators
-test added functions
-finish implmentation of operations, start with simple then harder
-test added functions
-see if I can optimize functions
*/
#include"Matrix.h"
using namespace std;

/*--------------------------------Constructors--------------------------------*/

// Default Constructor
Matrix::Matrix()
{
	m_array = new double[0];    // Array containin the elements of the matrix
	m_rows = 0;                 // Number of rows in matrix
	m_columns = 0;              // Number of columns in matrix
	m_size = 0;                 // Number of elements in matrix (m_columns*m_rows)
}

// Explicit Constructor
Matrix::Matrix(const double p_array[], int p_r, int p_c)
{
	m_rows = p_r;                 // Number of rows in matrix
	m_columns = p_c;              // Number of columns in matrix
	m_size = p_r * p_c;           // Number of elements in matrix (m_columns*m_rows)
	m_array = new double[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = p_array[i];  // Array containin the elements of the matrix
}

// Copy Constructor
Matrix::Matrix(const Matrix & orig)
{
	m_array = new double[orig.m_size];
	// Check memory, I guess
	for (int i = 0; i < orig.m_size; i++)
	{
		m_array[i] = orig.m_array[i];
	}
	m_rows = orig.m_rows;
	m_columns = orig.m_columns;
	m_size = orig.m_size;
}

// Deconstructor
Matrix::~Matrix()
{
	delete [] m_array;
}

/*---------------------------------Accessors----------------------------------*/

/* Purpose: Returns the number of rows in the matrix
Precondition: Intialized Matrix
Postcondition: m_rows will be returned              */
int Matrix::getNumOfRows() const { return m_rows; }

/* Purpose: Returns the number of columns in the matrix
Precondition: Intialized Matrix
Postcondition: m_columns will be returned              */
int Matrix::getNumOfCols() const { return m_columns; }

/* Purpose: Returns the number of elements in the matrix
Precondition: Intialized matrix
Postcondition: m_size will be returned                 */
int Matrix::getSize() const { return m_size; }

/* Purpose: Returns the a specific element from the matrix
Precondition: Intialized matrix and valid row and column number
Postcondition: A specific element will be returned,
     otherwise 0 will be returned.                             */
double Matrix::getElement(int p_row, int p_column) const
{
	if (p_row <= m_rows && p_row >= 0 && p_column <= m_columns && p_column >= 0)
		return m_array[(p_row - 1) * m_columns + p_column];
	return 0;
}

/*----------------------------------Mutators----------------------------------*/

/* Purpose: Swap two row 1 and row 2
Precondition: Intialized matrix, p_r1 and p_r2 are viable rows in the Matrix
Postcondition: The values of the first row will be swapped with the values
of the second row as designated by the parameters */
void Matrix::interchange(int p_r1, int p_r2)
{
	if (p_r1 <= m_rows && p_r1 > 0 && p_r2 <= m_rows && p_r2 > 0 && p_r1 != p_r2)
	{
		double temp;
		int row2 = (p_r2 - 1)*m_columns;
		for (int i = (p_r1 - 1)*m_columns; i < (p_r1*m_columns); i++)
		{
			temp = m_array[i];
			m_array[i] = m_array[row2];
			m_array[row2] = temp;
			row2++;
		}
	}
}

/* Purpose: Multiply a row by a scalar
Precondition: Intialized matrix, p_row is a viable row in the Matrix
Postcondition: The values of the row will be multiplied by a scalar */
void Matrix::rowScalar(int p_row, double p_multiplier)
{
	if (p_row <= m_rows && p_row > 0)
	{
		for (int i = (p_row - 1)*m_columns; i < (p_row*m_columns); i++)
		{
			m_array[i] *= p_multiplier;
		}
	}
}

/* Purpose: Add a row times a scalar to another row
Precondition: Intialized matrix, p_rowDest and p_row are viable rows in the Matrix
Postcondition: The values of the first row will be added with the values
of the second row times a multiplier and stored in the first row. */
void Matrix::replacement(int p_rowDest, int p_row, double p_multiplier)
{
	if (p_rowDest <= m_rows && p_rowDest > 0 && p_row <= m_rows && p_row > 0 && p_rowDest != p_row)
	{
		int row2 = (p_row - 1)*m_columns;
		for (int i = (p_rowDest - 1)*m_columns; i < (p_rowDest*m_columns); i++)
		{
			m_array[i] += p_multiplier*m_array[row2];
			row2++;
		}
	}
}

/* Purpose: Scales a Matrix
Precondition: Intialized matrix
Postcondition: All elements of Matrix will be multiplied by p_multiplier */
void Matrix::matrixScalar(double p_multiplier)
{
	for (int i = 0; i < m_size; i++)
		m_array[i] *= p_multiplier;
}

/*---------------------------------Operations---------------------------------*/

/* Purpose: Adds together two matrices
Precondition: Intialized matrices and both be the same size
Postcondition: The sum of both matrices will be returned,
     else the original matrix will be returned.            */
Matrix Matrix::operator+(const Matrix & p_term)
{
	if (m_rows == p_term.m_rows && m_columns == p_term.m_columns)
	{
		double * temp = new double[m_size];
		// check alloc
		for (int i = 0; i < m_size; i++)
			temp[i] = m_array[i] + p_term.m_array[i];
		Matrix sum(temp, m_rows, m_columns);
		return sum;
	}
	else
		return *this;
}

/* Purpose: Subtracts the calling Matrix by the term Matrix
Precondition: Intialized matrices and both be the same size
Postcondition: The difference of both matrices will be returned,
     else the original matrix will be returned.                 */
Matrix Matrix::operator-(const Matrix & p_term)
{
	if (m_rows == p_term.m_rows && m_columns == p_term.m_columns)
	{
		double * temp = new double[m_size];
		// check alloc
		for (int i = 0; i < m_size; i++)
			temp[i] = m_array[i] - p_term.m_array[i];
		Matrix difference(temp, m_rows, m_columns);
		return difference;
	}
	else
		return *this;
}

/* Purpose: Multiply one matrix by another
Precondition: Intialized matrices and both be the same size
Postcondition: The difference of both matrices will be returned,
else the original matrix will be returned.                 */
Matrix Matrix::operator*(const Matrix & p_term)
{
	return *this;
}

/* Purpose: Sets the calling matrix equal to the term Matrix
Precondition: Intialized matrices
Postcondition: The calling matrix will be the same as the term
	matrix.														*/
Matrix & Matrix::operator=(const Matrix & p_term)
{
	m_rows = p_term.m_rows;
	m_columns = p_term.m_columns;
	m_size = p_term.m_size;
	m_array = new double[p_term.m_size];
	// Check memory, I guess
	for (int i = 0; i < p_term.m_size; i++)
		m_array[i] = p_term.m_array[i];
	return *this;
}

/* Purpose: Augment a matrix
Precondition: Intialized matrices with the same number of rows
Postcondition: The calling matrix will add term matrix, creating
an augmented matrix.   										     */
void Matrix::augment(const Matrix & p_term)
{
	if (m_rows == p_term.m_rows)
	{
		double * temp = new double[m_size + p_term.m_size];
		for (int i = 0; i < m_rows; i++)
		{
			int c = 0;
			for (int m1 = 0; m1 < m_columns; m1++)
			{
				temp[c] = m_array[i*m_columns + m1];
				c++;
			}
			for (int m2 = 0; m2 < p_term.m_columns; m2++)
			{
				temp[c] = m_array[i*p_term.m_columns + m2];
				c++;
			}
		}
		m_columns += p_term.m_columns;
		m_size = m_columns * m_rows;
	}
}

/* Purpose: Transpose the matrix
Precondition: Intialized matrix
Postcondition: The rows of the matrix will become its columns   */
void Matrix::transpose()
{
	if (m_rows != 1 && m_columns != 1)
	{
		double * temp = new double[m_size];
		// Check memory, I guess
		// r designates row#-1 in original, col#-1 in transpose
		for (int r = 0; r < m_rows; r++)
		{
			// i designates col#-1 in original, row#-1 in transpose
			for (int i = 0; i < m_columns; i++)
			{
				temp[i*m_columns + r] = m_array[r*m_columns + i];
			}
		}
		double * dump = m_array;
		m_array = temp;
		delete[] dump;
	}

	int tem = m_rows;
	m_rows = m_columns;
	m_columns = tem;
}

/* Purpose: Check if two matrices are the same
Precondition: Intialized matrices
Postcondition: Return true if they are the same, else
	return false                                              */
bool Matrix::operator==(const Matrix & p_term)
{
	if (m_rows != p_term.m_rows || m_columns != p_term.m_columns)
	{
		return false;
	}
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] != p_term.m_array[i])
			return false;
	}
	return true;
}

/* Purpose: Check if two matrices are not the same
Precondition: Intialized matrices
Postcondition: Return true if they are not the same, else
	return true                                              */
bool Matrix::operator!=(const Matrix & p_term)
{
	if (m_rows != p_term.m_rows || m_columns != p_term.m_columns)
	{
		return true;
	}
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] != p_term.m_array[i])
			return true;
	}
	return false;
}



/*----------------------------------Display-----------------------------------*/

/* Purpose: Display the matrix in the output stream
Precondition: Intialized matrix and valid output stream
Postcondition: The matrix will be outputted to the output stream,
    so it is in rows and columns like a matrix is typically drawn.
	If uninitialized, nothing is outputted.                        */
void Matrix::displayMatrix(ostream & out)
{
	if (m_array == 0 || m_size == 0) return;
	// Take time to format this so it looks better
	for (int i = 0; i < m_size; i++)
	{
		if (i % m_columns != 0)
			out << m_array[i] << ' ';
		else
			out << '\n' << m_array[i] << ' ';
	}
	out << '\n';
}

// End of File
