/* Matrix.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		8/2/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/

#include"Matrix.h"
using namespace std;
Matrix createIdentity(int R);

/*--------------------------------Constructors--------------------------------*/

// Default Constructor
Matrix::Matrix()
{
	m_array = new double[0];    // Array containin the elements of the matrix
	m_rows = 0;                 // Number of rows in matrix
	m_columns = 0;              // Number of columns in matrix
	m_size = 0;                 // Number of elements in matrix (#col*#rows)
}

// Explicit Constructor
// Preconditions: p_r * p_c = length of p_array
Matrix::Matrix(const double p_array[], int p_r, int p_c)
{
	m_rows = p_r;                 // Number of rows in matrix
	m_columns = p_c;              // Number of columns in matrix
	m_size = p_r * p_c;           // Number of elements in matrix (#col*#rows)
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
Matrix::~Matrix() { delete[] m_array; }

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
	otherwise 0 will be returned.                        */
double Matrix::getElement(int p_row, int p_column) const
{
	if (p_row <= m_rows && p_row >= 1 && p_column <= m_columns && p_column >= 1)
		return m_array[(p_row - 1) * m_columns + p_column - 1];
	return 0;
}

/*----------------------------------Mutators----------------------------------*/

/* Purpose: Swap two row 1 and row 2
Precondition: Intialized matrix, p_r1 and p_r2 are viable rows in the Matrix
Postcondition: The values of the first row will be swapped with the values
	of the second row as designated by the parameters		*/
void Matrix::interchange(int p_r1, int p_r2)
{
	if (p_r1 <= m_rows && p_r1 >= 1 &&
		p_r2 <= m_rows && p_r2 >= 1 &&
		p_r1 != p_r2)
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
	if (p_row <= m_rows && p_row >= 1)
	{
		for (int i = (p_row - 1)*m_columns; i < (p_row*m_columns); i++)
		{
			m_array[i] *= p_multiplier;
		}
	}
}

/* Purpose: Add a row times a scalar to another row
Precondition: Intialized matrix, p_rowDest and p_row are viable rows in Matrix
Postcondition: The values of the first row will be added with the values
	of the second row times a multiplier and stored in the first row.	*/
void Matrix::replacement(int p_rowDest, int p_row, double p_multiplier)
{
	if (p_rowDest <= m_rows && p_rowDest >= 1 &&
		p_row <= m_rows && p_row >= 1 &&
		p_rowDest != p_row)
	{
		int row2 = (p_row - 1)*m_columns;
		for (int i = (p_rowDest - 1) * m_columns; i < (p_rowDest * m_columns);
			  i++)
		{
			m_array[i] += p_multiplier * m_array[row2];
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

/* Purpose: Replace one element in the matrix with p_term
Precondition: p_r and p_c must be in the Matrix
Postcondition:  Element at p_c and p_r will equal p_term;
	else no change											*/
void Matrix::setElement(double p_term, int p_r, int p_c)
{
	if (p_r <= m_rows && p_r >= 1 && p_c <= m_columns && p_c >= 1)
		m_array[(p_r - 1) * m_columns + p_c - 1] = p_term;
}

/* Purpose: Replace one row in the matrix with p_array
Precondition: p_array size should match p_size, p_size must equal the
number of elements in a row, p_rowNum should be in the matrix
Postcondition: p_array will replace row p_rowNum,
	else no change											*/
void Matrix::setRow(const double p_array[], int p_size, int p_rowNum)
{
	if (p_size == m_columns && p_rowNum >= 1 && p_rowNum <= m_rows)
	{
		for (int i = m_columns * (p_rowNum - 1); i < p_rowNum*m_columns; i++)
		{
			m_array[i] = p_array[i % m_columns];
		}
	}
}

/* Purpose: Replace one column in the matrix with p_array
Precondition: p_array size should match p_size, p_size must equal the
number of elements in a row, p_colNum should be in the matrix
Postcondition:  p_array will replace column p_colNum,
	else no change											*/
void Matrix::setColumn(const double p_array[], int p_size, int p_colNum)
{
	if (p_size == m_rows && p_colNum >= 1 && p_colNum <= m_columns)
	{
		for (int i = p_colNum - 1; i < m_columns*(m_rows - 1) + p_colNum;
			 i += m_columns)
		{
			m_array[i] = p_array[i / m_columns];
		}
	}
}

/* Purpose: Reset a matrix with new size and elements
Precondition: p_r * p_c should be the number of elements in p_array
Postcondition:  m_array will contain the elements of p_array,*/
void Matrix::resetMatrix(const double p_array[], int p_r, int p_c)
{
	delete[] m_array;
	m_rows = p_r;
	m_columns = p_c;
	m_size = p_r * p_c;
	m_array = new double[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = p_array[i];  // Array containing the elements of the matrix
}

/*---------------------------------Operations---------------------------------*/

/* Purpose: Verify if an operation will work for the matrices
Precondition: Two valid matrices and a valid char option
Postcondition:  Will return true if the operation will work,
	else return false, default is false.						*/
bool Matrix::checkOperation(const Matrix & other, char oper)
{
	// Need to implement this
	if (oper == '+' || oper == '-')
		// Addition or subtraction
	{
		return (m_columns == other.m_columns && m_rows == other.m_rows);
	}
	else if (oper == '*')
		// Matrix multiplication (Ax=b) where A is host Matrix, x is other
	{
		return (m_columns == other.m_rows);
	}
	else if (oper == 'a')
		// Augment Matrix
	{
		return (m_rows == other.m_rows);
	}
	// Equals (=), Equal to (==) and Not equal to (!=) do not have requirements.
	// Transpose, inverse, and determinant do not need another Matrix.
	// Default Assumption
	return false;
}

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
		delete[] temp;
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
		delete[] temp;
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
	// May be able to make it one for loop
	if (m_columns == p_term.m_rows)
	{
		int productSize = m_rows * p_term.m_columns;
		double * productArray = new double[productSize];
		int row = 0,
			column = 0;
		for (int i = 0; i < m_rows * p_term.m_columns; i++)
		{
			double sum = 0;
			row = i / m_columns;
			column = i % m_columns;
			for (int k = 0; k < m_columns; k++)
			{
				sum += m_array[k + row * m_columns]
					 * p_term.m_array[k * p_term.m_columns + column];
			}
			productArray[i] = sum;
		}
		Matrix product(productArray, m_rows, p_term.m_columns);
		delete[] productArray;
		return product;
	}

	return *this;
}

/* Purpose: Sets the calling matrix equal to the term Matrix
Precondition: Intialized matrices
Postcondition: The calling matrix will be the same as the term matrix.	  */
Matrix & Matrix::operator=(const Matrix & p_term)
{
	delete[] m_array;
	m_rows = p_term.m_rows;
	m_columns = p_term.m_columns;
	m_size = p_term.m_size;
	m_array = new double[p_term.m_size];
	// Check memory, I guess
	for (int i = 0; i < p_term.m_size; i++)
		m_array[i] = p_term.m_array[i];
	return *this;
}

/* Purpose: Return the inverse of the matrix
Precondition: The matrix must be invertible
Postcondition: The inverse of the matrix will be returned,
	else the matrix itself will be returned.				*/
Matrix Matrix::inverse()
{
	if (m_rows == m_columns)
	{
		double * inverse = new double[m_size];
		double deter = determinant();
		if (deter != 0)
		{

			if (m_rows == 1)
				// Single element
			{
				inverse[0] = 1.0 / m_array[0];
			}
			else if (m_rows == 2)
				// 2x2 matrix
			{
				inverse[0] = 1.0 * m_array[3] / deter;
				inverse[1] = -1.0 * m_array[1] / deter;
				inverse[2] = -1.0 * m_array[2] / deter;
				inverse[3] = 1.0 * m_array[0] / deter;
			}
			else
			{
				// Use row reduce reduction formula, may be rounding issues
				Matrix invert = createIdentity(m_columns);
				int column = 0;
				for (int row = 0; row < m_rows; row++)
				{
					cout << "Row: " << row << '\n';
					if (m_array[row * m_columns + column] != 0)
					{
						// Reduces the front of the row to 0
						invert.rowScalar(row + 1, 1.0 / m_array[row * m_columns + column]);
						rowScalar(row + 1, 1.0 / m_array[row * m_columns + column]);
						// Reduces the rest of the values below to 0
						for (int i = (row + 1) * m_columns + column; i < m_size;
							i += m_columns)
						{
							if (m_array[i] != 0)
							{
								invert.replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
								replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
							}
						}
						// Reduces the rest of the values above to 0
						for (int i = column; i < row * m_columns + column; i += m_columns)
						{
							if (m_array[i] != 0)
							{
								invert.replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
								replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
							}
						}
					}
					else
					{
						// row interchange with ones below
						double max = 0,
							min = 0;
						int maxRow = 0,
							minRow = 0;
						for (int i = (row + 1) * m_columns + column; i < m_size;
							i += m_columns)
						{
							if (m_array[i] < min)
							{
								min = m_array[i];
								minRow = i / m_columns + 1;
							}
							else if (m_array[i] > max)
							{
								max = m_array[i];
								maxRow = i / m_columns + 1;
							}
						}
						// if max and min are 0 skip to next row, column
						// Max and min are checked in case there is a negative value
						if (max != 0)
						{
							interchange(row + 1, maxRow);
							invert.interchange(row + 1, maxRow);
							row--; // Force it to go through the first part of if statement
							column--;
						}
						else if (min != 0)
						{
							interchange(row + 1, minRow);
							invert.interchange(row + 1, minRow);
							row--; // Force it to go through the first part of if statement
							column--;
						}
						else
						{
							row--; // Both max and min of ones below are 0
							// Stay in the same row, move onto the next column
						}
					}
					column++;
					if (column >= m_columns)
					{
						cout << "Returning Invert from column:\n";
						return invert;
					}
				}
			}
			Matrix invert(inverse, m_rows, m_columns);
			delete[] inverse;
			return invert;
		}
	}
	// Else return current Matrix
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
		int c = 0;
		for (int i = 0; i < m_rows; i++)
		{
			for (int m1 = 0; m1 < m_columns; m1++)
			{
				temp[c] = m_array[i*m_columns + m1];
				c++;
			}
			for (int m2 = 0; m2 < p_term.m_columns; m2++)
			{
				temp[c] = p_term.m_array[i*p_term.m_columns + m2];
				c++;
			}
		}
		m_columns += p_term.m_columns;
		m_size = m_columns * m_rows;
		delete[] m_array;
		m_array = temp;
	}
}

/* Purpose: Transpose the matrix
Precondition: Intialized matrix
Postcondition: The rows of the matrix will become its columns   */
void Matrix::transpose()
{
	// see about reducing it to one for loop
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
				temp[i*m_rows + r] = m_array[r*m_columns + i];
			}
		}
		delete[] m_array;
		m_array = temp;
	}
	int tem = m_rows;
	m_rows = m_columns;
	m_columns = tem;
}

/* Purpose: Finds the RREF of the matrix
Precondition: Intialized matrix
Postcondition: The matrix will now be in RREF,
	though note, there may be rounding errors.			*/
void Matrix::rref()
{
	// m_columns, m_rows
	int column = 0;
	for (int row = 0; row < m_rows; row++)
	{
		if (m_array[row * m_columns + column] != 0)
		{
			// Reduces the front of the row to 0
			rowScalar(row + 1, 1.0 / m_array[row * m_columns + column]);
			// Reduces the rest of the values below to 0
			for (int i = (row + 1) * m_columns + column; i < m_size;
				i += m_columns)
			{
				if (m_array[i] != 0)
				{
					replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
				}
			}
			// Reduces the rest of the values above to 0
			for (int i = column; i < row * m_columns + column; i += m_columns)
			{
				if (m_array[i] != 0)
				{
					replacement(i / m_columns + 1, row + 1, -1.0 * m_array[i]);
				}
			}
		}
		else
		{
			// row interchange with ones below
			double max = 0,
				min = 0;
			int maxRow = 0,
				minRow = 0;
			for (int i = (row + 1) * m_columns + column; i < m_size;
				i += m_columns)
			{
				if (m_array[i] < min)
				{
					min = m_array[i];
					minRow = i / m_columns + 1;
				}
				else if (m_array[i] > max)
				{
					max = m_array[i];
					maxRow = i / m_columns + 1;
				}
			}
			// if max and min are 0 skip to next row, column
			// Max and min are checked in case there is a negative value
			if (max != 0)
			{
				interchange(row + 1, maxRow);
				row--; // Force it to go through the first part of if statement
				column--;
			}
			else if (min != 0)
			{
				interchange(row + 1, minRow);
				row--; // Force it to go through the first part of if statement
				column--;
			}
			else
			{
				row--; // Both max and min of ones below are 0
				// Stay in the same row, move onto the next column
			}
		}
		column++;
		if (column >= m_columns)
		{
			break;
		}
	}
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == 0)
			// Fixes problems where 0's sometimes have negative signs after rref
		{
			m_array[i] = abs(m_array[i]);
		}
	}
}

/* Purpose: Check if two matrices are the same
Precondition: Intialized matrices
Postcondition: Return true if they are the same, else
	return false                                      */
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
	return true                                           */
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

/* Purpose: Calculate the determinant of the matrix
Precondition: It must be an n*n matrix
Postcondition: It will return the determinant if it is n*n
	otherwise return 0 */
double Matrix::determinant()
{
	// This function is recursive
	if (m_rows == m_columns)
	{
		// 1x1 trivial case
		if (m_rows == 1)
		{
			return m_array[0];
		}
		// 2x2 down - up, ad - cb
		else if (m_rows == 2)
		{
			return m_array[0] * m_array[3] - m_array[2] * m_array[1];
		}
		// 3x3 rule, aei + bfg + cdh - gec - hfa - idb
		else if (m_rows == 3)
		{
			return (m_array[0] * m_array[4] * m_array[8]
				  + m_array[1] * m_array[5] * m_array[6]
				  + m_array[2] * m_array[3] * m_array[7]
				  - m_array[6] * m_array[4] * m_array[2]
				  - m_array[7] * m_array[5] * m_array[0]
				  - m_array[8] * m_array[3] * m_array[1]);
		}
		// n*n, cofactor expansion
		else
		{
			// This will be a bit inefficient, need to see about improving
			double deter = 0;
			Matrix m;
			double * tempArray = new double[(m_columns - 1) * (m_rows - 1)];
			for (int i = 0; i < m_columns; i++)
			{
				if (m_array[i] != 0)
				{
					int newM = 0;
					for (int orig = m_columns; orig < m_size; orig++)
					{
						if (orig % m_columns != i % m_columns)
						{
							tempArray[newM] = m_array[orig];
							newM++;
						}
					}
					m.resetMatrix(tempArray, m_columns - 1, m_rows - 1);
					deter += m_array[i] * m.determinant()
					  	   * pow(-1, i / m_columns + i % m_columns);
				}
			}
			delete[] tempArray;
			return deter;
		}
	}
	return 0;
}

/*----------------------------------Display-----------------------------------*/

/* Purpose: Display the matrix in the output stream
Precondition: Intialized matrix and valid output stream
Postcondition: The matrix will be outputted to the output stream,
	so it is in rows and columns like a matrix is typically drawn.
	If uninitialized, nothing is outputted.                        */
void Matrix::displayMatrix(ostream & out)
{
	out << left;
	if (m_array == 0 || m_size == 0) return;
	for (int i = 0; i < m_size; i++)
	{
		if (i % m_columns != 0 || i == 0)
			out << setw(3) << m_array[i] << ' ';
		else
			out << '\n' << setw(3) << m_array[i] << ' ';
	}
	out << '\n';
}

/*-----------------------------Related Functions------------------------------*/

/* Purpose: Create an identity matrix of I^R
Precondition: R is greater then or equal to 1
Postcondition: The matrix return will be an Identity matrix,
R does not meet Precondition, then an empty matrix will be returned*/
Matrix createIdentity(int R)
{
	if (R >= 1)
	{
		int insert1 = 0;
		double * array = new double[R*R];
		for (int k = 0; k < R*R; k++)
		{
			if (k == insert1)
			{
				array[k] = 1.0;
				insert1 += R + 1;
			}
			else
			{
				array[k] = 0.0;
			}
		}
		Matrix identity(array, R, R);
		delete[] array;
		return identity;
	}

	return Matrix();
}

// End of File
