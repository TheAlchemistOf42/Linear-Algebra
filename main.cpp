/* main.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		7/17/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/
// Todo: test operations
//		add testing harness
#include<iostream>
#include"Matrix.h"
using namespace std;

int main()
{
	double test[4] = { 0, 1, 2, 3 };
	double test2[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double test3[3] = { 0, 1, 2 };
	Matrix m1, m2(test, 2, 2), m3(m2), m4(test2, 3, 3);
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
	// 4th matrix
	cout << "I need a 4th matrix.\n\tMatrix 4:\n";
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
	cout << "Testing interchange() :\n";
	cout << "Matrix 2: Switching row 1 and 2:\n";
	m2.interchange(1, 2);
	m2.displayMatrix(cout);
	// rowScalar
	cout << "Testing rowScalar() :\n";
	cout << "Matrix 4: Multiplying row 2 by 3:\n";
	m4.rowScalar(2, 3);
	m4.displayMatrix(cout);
	// replacement
	cout << "Testing replacement() :\n";
	cout << "Matrix 4: Adding row 1 times -2 to row three:\n";
	m4.replacement(3, 1, -2);
	m4.displayMatrix(cout);
	// matrixScalar
	cout << "Testing matrixScalar() :\n";
	cout << "Multiplying Matrix by 2:\n";
	m4.matrixScalar(2);
	m4.displayMatrix(cout);
	// setElement
	cout << "Testing setElement() :\n";
	cout << "Replacing row 1 column 1 with 0:\n";
	cout << "Replacing row 3 column 2 with 1:\n";
	cout << "Both for Matrix 4:\n";
	m4.setElement(0, 1, 1);
	m4.setElement(1, 3, 2);
	m4.displayMatrix(cout);
	// setRow
	cout << "Testing setRow() :\n";
	cout << "Matrix 4: Replaing row 1 with 0, 1, 2\n";
	m4.setRow(test3, 3, 1);
	m4.displayMatrix(cout);
	// setColumn
	cout << "Testing setColumn() :\n";
	cout << "Matrix 4: Replaing column 3 with 0, 1, 2\n";
	m4.setRow(test3, 3, 3);
	m4.displayMatrix(cout);
	// resetMatrix
	cout << "Testing resetMatrix() :\n";
	cout << "Reseting Matrix 4:\n";
	m4.resetMatrix(test2, 3, 3);
	m4.displayMatrix(cout);
	// checkOp
		// + addition
	cout << "Matrix 1 + Matrix 2 should be true: ";
	cout << (m1.checkOperation(m2, '+') ? "true" : "false") << '\n';
	cout << "Matrix 1 + Matrix 4 should be false: ";
	cout << (m1.checkOperation(m4, '+') ? "true" : "false") << '\n';
		// - subtraction
	cout << "Matrix 1 - Matrix 2 should be true: ";
	cout << (m1.checkOperation(m2, '-') ? "true" : "false") << '\n';
	cout << "Matrix 1 - Matrix 4 should be false: ";
	cout << (m1.checkOperation(m4, '-') ? "true" : "false") << '\n';
		// * multiplication
	cout << "Matrix 1 * Matrix 2 should be true: ";
	cout << (m1.checkOperation(m2, '*') ? "true" : "false") << '\n';
	cout << "Matrix 1 * Matrix 4 should be false: ";
	cout << (m1.checkOperation(m4, '*') ? "true" : "false") << '\n';
		// augment
	cout << "Matrix 1 augmented by Matrix 2 should be true: ";
	cout << (m1.checkOperation(m2, 'a') ? "true" : "false") << '\n';
	cout << "Matrix 1 augmented Matrix 4 should be false: ";
	cout << (m1.checkOperation(m4, 'a') ? "true" : "false") << '\n';
		// inverse
		// determinant
	// Test operations
	cout << "End of Matrix Testing.\n";
	return 0;
}
// End of File
