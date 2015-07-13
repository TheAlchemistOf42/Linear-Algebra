/* main.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		7/12/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/
// Todo: test operations
#include<iostream>
#include"Matrix.h"
using namespace std;

int main()
{
	double test[4] = { 0, 1, 2, 3 };
	double test2[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Matrix m1, m2(test, 2, 2), m3(m2);
	cout << "Beginning of Matrix test: \n";
	// Test, always display
	cout << "Always test display function of Matrix object.\n";
	// Default Constructor
	cout << "Testing Default Constructor:\n";
	cout << "\tMatrix 1:\n";
	m1.displayMatrix(cout);
	// Explicit Constructor
	cout << "Testing Explicit Constructor:\n";
	cout << "\tMatrix 2:\n";
	m2.displayMatrix(cout);
	// Copy Constructor
	cout << "Testing Copy Constructor:\n";
	cout << "\tMatrix 3:\n";
	m3.displayMatrix(cout);
	// getNumOfRows
	cout << "Testing getNumOfRows() :\n";
	cout << "\tMatrix 2 # of rows: " << m2.getNumOfRows() << '\n';
	// getNumOfCols
	cout << "Testing getNumOfCols() :\n";
	cout << "\tMatrix 3 # of Columns: " << m2.getNumOfCols() << '\n';
	// getSize
	cout << "Testing getSize() :\n";
	cout << "\tMatrix 2 # of Elements: " << m2.getSize() << '\n';
	// getElement
	cout << "Testing getElement() :\n";
	cout << "\tMatrix 2 Row 2 Column 1: " << m2.getElement(2,1) << '\n';
	cout << "\tMatrix 2 Row 1 Column 2: " << m2.getElement(1, 2) << '\n';
	// interchange
	cout << "Testing getElement() :\n";
	// rowScalar
	cout << "Testing getElement() :\n";
	// replacement
	cout << "Testing getElement() :\n";
	// matrixScalar
	cout << "Testing getElement() :\n";
	// setElement
	cout << "Testing getElement() :\n";
	// setRow
	cout << "Testing getElement() :\n";
	// setCol
	cout << "Testing getElement() :\n";
	// resetMatrix
	cout << "Testing getElement() :\n";
	// checkOp
		// +
		// -
		// *
		// augment
		// inverse
		// determinant
	cout << "End of Matrix Testing.\n";
	return 0;
}
// End of File
