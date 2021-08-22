/*
 * Calculator.cpp
 *
 *  Date: 7/10/2021
 *  Author: David Obi 
 */

#include <iostream>
using namespace std;

int main() // Changed to int because the return values are integers
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'Y'; // Fixed "" to '' 
		while (answer == 'y' || answer =='Y')   // Fixed to include an or/||
		{
			cout << "Enter expression" << endl;
			cin >> op1 >> operation >> op2;  // Fixed op1 and op2 so the order of operations are correctly aligned
			if (operation == '+')
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
			if (operation == '-')
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
			if (operation == '*')
				cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
				if (operation == '/')
					cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Fixed every syntax error from lines 22-29

			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
			
		}
		cout << "Program finished. " << endl;  // Added to end program 
}