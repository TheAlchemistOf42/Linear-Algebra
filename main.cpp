/* main.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		8/1/2015
Description: A matrix object allowing one to do mathematics with matrices.
*/

#include<iostream>
#include"Matrix.h"
using namespace std;
Matrix createIdentity(int R);

int main()
{
	double test[4] = { 0, 1, 2, 3 };
	double test2[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double test3[3] = { 0, 1, 2 };
	double test4[25] = { 4, 6, -7, 3, -5, 3, 1, 2, 8, 9, 7, 3, -6, 4, -8, 5,
						2, 5, 2, -3, 2, 4, 9, -1, 2 };
	Matrix m1, m2(test, 2, 2), m3(m2), m4(test2, 3, 3), m5, m6(test4, 5, 5);
	cout << "Beginning of Matrix test: \n";
	// Test, always display ---------------------
	cout << "This will almost always test display function of Matrix object.\n";

	// Default Constructor ---------------------
	cout << "\nTesting Default Constructor:\n";
	cout << "Matrix 1:\n";
	m1.displayMatrix(cout);

	// Explicit Constructor ---------------------
	cout << "\nTesting Explicit Constructor:\n";
	cout << "Matrix 2:\n";
	m2.displayMatrix(cout);

	// Copy Constructor ---------------------
	cout << "\nTesting Copy Constructor:\n";
	cout << "Matrix 3:\n";
	m3.displayMatrix(cout);
	// 4th matrix
	cout << "\nI need a 4th matrix.\nMatrix 4:\n";
	m4.displayMatrix(cout);

	// operator= ---------------------
	// createIdentity
	cout << "\nTesting createIdentity() from main.cpp\n";
	cout << "Also testing operator=() :\n";
	cout << "Matrix 5, I^4\n";
	m5 = createIdentity(4);
	m5.displayMatrix(cout);

	// getNumOfRows ---------------------
	cout << "\nTesting getNumOfRows() :\n";
	cout << "Matrix 2 # of rows: " << m2.getNumOfRows() << '\n';

	// getNumOfCols ---------------------
	cout << "\nTesting getNumOfCols() :\n";
	cout << "Matrix 3 # of Columns: " << m2.getNumOfCols() << '\n';

	// getSize ---------------------
	cout << "\nTesting getSize() :\n";
	cout << "Matrix 2 # of Elements: " << m2.getSize() << '\n';

	// getElement ---------------------
	cout << "\nTesting getElement() :\n";
	cout << "Matrix 2 Row 2 Column 1: " << m2.getElement(2, 1) << '\n';
	cout << "Matrix 2 Row 1 Column 2: " << m2.getElement(1, 2) << '\n';

	// interchange ---------------------
	cout << "\nTesting interchange() :\n";
	cout << "Matrix 2: Switching row 1 and 2:\n";
	m2.interchange(1, 2);
	m2.displayMatrix(cout);

	// rowScalar ---------------------
	cout << "\nTesting rowScalar() :\n";
	cout << "Matrix 4: Multiplying row 2 by 3:\n";
	m4.rowScalar(2, 3);
	m4.displayMatrix(cout);

	// replacement ---------------------
	cout << "\nTesting replacement() :\n";
	cout << "Matrix 4: Adding row 1 times -2 to row three:\n";
	m4.replacement(3, 1, -2);
	m4.displayMatrix(cout);

	// matrixScalar ---------------------
	cout << "\nTesting matrixScalar() :\n";
	cout << "Multiplying Matrix by 2:\n";
	m4.matrixScalar(2);
	m4.displayMatrix(cout);

	// setElement ---------------------
	cout << "\nTesting setElement() :\n";
	cout << "Replacing row 1 column 1 with 0:\n";
	cout << "Replacing row 3 column 2 with 1:\n";
	cout << "Both for Matrix 4:\n";
	m4.setElement(0, 1, 1);
	m4.setElement(1, 3, 2);
	m4.displayMatrix(cout);

	// setRow ---------------------
	cout << "\nTesting setRow() :\n";
	cout << "Matrix 4: Replaing row 1 with 0, 1, 2\n";
	m4.setRow(test3, 3, 1);
	m4.displayMatrix(cout);

	// setColumn ---------------------
	cout << "\nTesting setColumn() :\n";
	cout << "Matrix 4: Replaing column 3 with 0, 1, 2\n";
	m4.setColumn(test3, 3, 3);
	m4.displayMatrix(cout);

	// resetMatrix ---------------------
	cout << "\nTesting resetMatrix() :\n";
	cout << "Reseting Matrix 4:\n";
	m4.resetMatrix(test2, 3, 3);
	m4.displayMatrix(cout);

	// checkOp---------------------
	cout << "\nTesting checkOperation() :\n";
	// + addition ---------------------
	cout << "Matrix 2 + Matrix 3 should be true: ";
	cout << (m2.checkOperation(m3, '+') ? "true" : "false") << '\n';
	cout << "Matrix 2 + Matrix 4 should be false: ";
	cout << (m2.checkOperation(m4, '+') ? "true" : "false") << '\n';
	// - subtraction ---------------------
	cout << "Matrix 2 - Matrix 3 should be true: ";
	cout << (m2.checkOperation(m3, '-') ? "true" : "false") << '\n';
	cout << "Matrix 2 - Matrix 4 should be false: ";
	cout << (m2.checkOperation(m4, '-') ? "true" : "false") << '\n';
	// * multiplication ---------------------
	cout << "Matrix 2 * Matrix 3 should be true: ";
	cout << (m2.checkOperation(m3, '*') ? "true" : "false") << '\n';
	cout << "Matrix 2 * Matrix 4 should be false: ";
	cout << (m2.checkOperation(m4, '*') ? "true" : "false") << '\n';
	// augment ---------------------
	cout << "Matrix 2 augmented by Matrix 3 should be true: ";
	cout << (m2.checkOperation(m3, 'a') ? "true" : "false") << '\n';
	cout << "Matrix 2 augmented by Matrix 4 should be false: ";
	cout << (m2.checkOperation(m4, 'a') ? "true" : "false") << '\n';

	// Test operations ---------------------
	cout << "\nTesting operators:\n";
	// +
	cout << "\nTesting operator+()\n";
	cout << "Matrix 5\n";
	m5.displayMatrix(cout);
	cout << "Matrix 5 + Matrix 5\n";
	(m5 + m5).displayMatrix(cout);
	cout << "Matrix 2\n";
	m2.displayMatrix(cout);
	cout << "Matrix 3\n";
	m3.displayMatrix(cout);
	cout << "Matrix 2 + Matrix 3\n";
	(m2 + m3).displayMatrix(cout);

	// -
	cout << "\nTesting operator-()\n";
	cout << "Matrix 5\n";
	m5.displayMatrix(cout);
	cout << "Matrix 5 - Matrix 5\n";
	(m5 - m5).displayMatrix(cout);
	cout << "Matrix 2\n";
	m2.displayMatrix(cout);
	cout << "Matrix 3\n";
	m3.displayMatrix(cout);
	cout << "Matrix 2 - Matrix 3\n";
	(m2 - m3).displayMatrix(cout);

	// *
	cout << "\nTesting operator*()\n";
	cout << "Matrix 5\n";
	m5.displayMatrix(cout);
	cout << "Matrix 5 * Matrix 5\n";
	(m5*m5).displayMatrix(cout);
	cout << "Matrix 2\n";
	m2.displayMatrix(cout);
	cout << "Matrix 3\n";
	m3.displayMatrix(cout);
	cout << "Matrix 2 * Matrix 3\n";
	(m2 * m3).displayMatrix(cout);

	// inverse ---------------------
	cout << "\nTesting inverse()\n";
	cout << "\nMatrix 2\n";
	cout << "\nMatrix 3\n";

	// augment ---------------------
	cout << "\nTesting augment():\n";
	cout << "Matrix 2:\n";
	m2.displayMatrix(cout);
	cout << "Matrix 3:\n";
	m3.displayMatrix(cout);
	cout << "\nMatrix 2 augmented by Matrix 3:\n";
	m2.augment(m3);
	m2.displayMatrix(cout);

	// transpose ---------------------
	cout << "\nTesting transpose():\n";
	cout << "Matrix 2:\n";
	m2.displayMatrix(cout);
	cout << "Matrix 2 transposed:\n";
	m2.transpose();
	m2.displayMatrix(cout);
	cout << "Matrix 3:\n";
	m3.displayMatrix(cout);
	cout << "Matrix 3 transposed:\n";
	m3.transpose();
	m3.displayMatrix(cout);

	// rref --------------------
	cout << "\nTesting rref():\n";
	cout << "Matrix 4:\n";
	m4.displayMatrix(cout);
	m4.rref();
	cout << "Matrix 4 rref():\n";
	m4.displayMatrix(cout);
	cout << "Reseting Matrix 4:\n";
	m4.resetMatrix(test2, 3, 3);
	m4.displayMatrix(cout);
	cout << "Matrix 6:\n";
	m6.displayMatrix(cout);
	m6.rref();
	cout << "Matrix 6 rref():\n";
	m6.displayMatrix(cout);
	cout << "Reseting Matrix 6:\n";
	m6.resetMatrix(test4, 5, 5);
	m6.displayMatrix(cout);

	// == ---------------------
	cout << "\nTesting == operator:\n";
	cout << "Matrix 2 == Matrix 2\n\t" << (m2 == m2 ? "True" : "False") << '\n';
	cout << "Matrix 2 == Matrix 4\n\t" << (m2 == m4 ? "True" : "False") << '\n';

	// != ---------------------
	cout << "\nTesting != operator:\n";
	cout << "Matrix 2 != Matrix 2\n\t" << (m2 != m2 ? "True" : "False") << '\n';
	cout << "Matrix 2 != Matrix 4\n\t" << (m2 != m4 ? "True" : "False") << '\n';

	// determinant
	cout << "\nTesting determinant() :\n";
	cout << "Matrix 3:\n";
	m3.displayMatrix(cout);
	cout << "Matrix 3 determinant: " << m3.determinant() << '\n';
	cout << "Matrix 4:\n";
	m4.displayMatrix(cout);
	cout << "Matrix 4 determinant: " << m4.determinant() << '\n';
	cout << "Matrix 5:\n";
	m5.displayMatrix(cout);
	cout << "Matrix 5 determinant: " << m5.determinant() << '\n';
	cout << "Matrix 6:\n";
	m6.displayMatrix(cout);
	cout << "Matrix 6 determinant: " << m6.determinant() << '\n';


	cout << "\nEnd of Matrix Testing.\n";
	return 0;
}

// End of File
