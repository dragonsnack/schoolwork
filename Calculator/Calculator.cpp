// Calculator by Joshua Golden

// Include the iostream library.
#include <iostream>

// Use the standard namespace.
using namespace std;

void main()
{

	// Declare the variables.
	float Number_1;
	float Number_2;
	float Result;
	int Which_Calculation = 1;

	// Give instructions.
	cout << "Choose a task. Press 1 to add, 2 to subtract, 3 to multiply, 4 to divide" << endl;
	cin >> Which_Calculation;

	// Get Numbers.
	cout << "Please enter the first number." << endl;
	cin >> Number_1;
	cout << "Please enter the second number." << endl;
	cin >> Number_2;

	if (Which_Calculation == 1)
	{
		// These commands run if This_Thing == 1.

		// Calculate the result.
		Result = Number_1 + Number_2;

	}

	if (Which_Calculation == 2)
	{
		// These commands run if This_Thing == 1.

		// Calculate the result.
		Result = Number_1 - Number_2;

	}

	if (Which_Calculation == 3)
	{
		// These commands run if This_Thing == 1.

		// Calculate the result.
		Result = Number_1 * Number_2;

	}

	if (Which_Calculation == 4)
	{
		// These commands run if This_Thing == 1.

		// Calculate the result.
		Result = Number_1 / Number_2;

	}

	// Print the answer is. . .
	cout << "The answer is. . ." << endl;

	// Print the result.
	cout << Result << endl;
	system("PAUSE");
}