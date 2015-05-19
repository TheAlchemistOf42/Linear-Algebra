/* main.cpp
Author:		Andrew Crutcher
Email:		alcrutcher1s@semo.edu
College:	Southeast Missouri State University
Course:		MA345-740 Linear Algebra
Prof:		Dr. Wang
Date:		4/8/15
Description: A matrix object allowing one to do mathematics with matrices.
*/
// Change this to test my Matrix object instead of the IntegerSet from my
// previous assignment
#include<iostream>
#include"Matrix.h"
using namespace std;

int main()
{
	int choice, size1, size2, para, numOfSet;
	bool repeat = true;
	cout << "Testing of Matrix class:\n";
	cout << "Enter size of each set:\nSet 1:";
	cin >> size1;
	cout << "Set 2:";
	cin >> size2;
	cout << "Initializing sets:\nSet 1:\n";
	IntegerSet set1(size1);
	cout << "Set 2:\n";
	IntegerSet set2(size2);
	while (repeat)
	{
		IntegerSet temp;
		cout << "Select which function you wish to test by choosing it's number:\n";
		cout << "Function 1: int size()\n";
		cout << "Function 2: bool isEmpty()\n";
		cout << "Function 3: bool isMember(int item)\n";
		cout << "Function 4: bool add(int item)\n";
		cout << "Function 5: bool remove(int item)\n";
		cout << "Function 6: bool isSubset(IntegerSet set2)\n";
		cout << "Function 7: IntegerSet intersection(IntegerSet set2)\n";
		cout << "Function 8: IntegerSet union(IntegerSet set2)\n";
		cout << "Function 9: IntegerSet difference(IntegerSet set2)\n";
		cout << "Function 10: void display()\n";
		cout << "Default Option: End testing and exit\n";
		cout << "Depending on function called output will be different\n";
		cin >> choice;
		cout << "Select calling set choices of 1 or 2, 1 is default: ";
		cin >> numOfSet;
		switch (choice)
		{
		case 1:
			if (numOfSet != 2)
				cout << "Size of Set 1: " << set1.size() << '\n';
			else
				cout << "Size of Set 2: " << set2.size() << '\n';
			break;
		case 2:
			if (numOfSet != 2)
				cout << "Is Set 1 Empty? " << (set1.isEmpty() ? "True" : "False") << '\n';
			else
				cout << "Is Set 2 Empty? " << (set2.isEmpty() ? "True" : "False") << '\n';
			break;
		case 3:
			cout << "Please input an int to be the parameter: ";
			cin >> para;
			if (numOfSet != 2)
				cout << "Is " << para << " a member of Set 1? " << (set1.isMember(para) ? "True" : "False") << '\n';
			else
				cout << "Is " << para << " a member of Set 2? " << (set2.isMember(para) ? "True" : "False") << '\n';
			break;
		case 4:
			cout << "Please input an int to be the parameter: ";
			cin >> para;
			if (numOfSet != 2)
				cout << "Could you add " << para << " to Set 1? " << (set1.add(para) ? "True" : "False") << '\n';
			else
				cout << "Could you add " << para << " to Set 2? " << (set2.add(para) ? "True" : "False") << '\n';
			break;
		case 5:
			cout << "Please input an int to be the parameter: ";
			cin >> para;
			if (numOfSet != 2)
				cout << "Could you remove " << para << " to Set 1? " << (set1.remove(para) ? "True" : "False") << '\n';
			else
				cout << "Could you remove " << para << " to Set 2? " << (set2.remove(para) ? "True" : "False") << '\n';
			break;
		case 6:
			if (numOfSet != 2)
				cout << "Is Set 2 a subset of Set 1? " << (set1.isSubset(set2) ? "True" : "False") << '\n';
			else
				cout << "Is Set 1 a subset of Set 2? " << (set2.isSubset(set1) ? "True" : "False") << '\n';
			break;
		case 7:
			// numOfSet does not matter for intersection
			temp = set1.intersection(set2);
			cout << "Intersection of Set 1 and 2:\n";
			temp.display();
			break;
		case 8:
			// numOfSet does not matter for union
			temp = set1.unionOf(set2);
			cout << "Union of Set 1 and 2:\n";
			temp.display();
			break;
		case 9:
			if (numOfSet != 2)
			{
				temp = set1.difference(set2);
				cout << "Set 2 subtracted from Set 1:\n";
			}
			else
			{
				temp = set2.difference(set1);
				cout << "Set 1 subtracted from Set 2:\n";
			}
            temp.display();
			break;
		case 10:
			if (numOfSet != 2)
				set1.display();
			else
				set2.display();
			break;
		default:
			repeat = false;
			break;
		}
		cout << "\n\n";
	}
	cout << "\nEnd of Testing of IntegerSet.\n";
	return 0;
}
// End of File
