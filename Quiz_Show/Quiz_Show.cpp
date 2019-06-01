/*
The Great Quiz Show Game

		   by

	  Joshua Golden


*/

// Include the libraries
#include <iostream>
#include <string>
#include <fstream>


// Use the standard namespace
using namespace std; 

// Declare global variables
int Guess;
int Winnings;


// Define the Question class.
class Question
{
	private:
		string Question_Text;
		string Answer_1;
		string Answer_2;
		string Answer_3;
		string Answer_4;
		int Correct_Answer;
		int Prize_Amount; // How much the question is worth.
	public:
		void setValues(string, string, string, string, string, int, int);

		void askQuestion();

};

void main()
{
	// Declare local variables
	int High_Score[5];
	string High_Score_Name[5];
	int Rank;


	// Initialize a high score at 0
	High_Score[4] = 0;


	// Input the high scores from a file
	ifstream Input_High_Scores;
	Input_High_Scores.open("High_Scores.txt");
	for (int i = 0; i < 5; i++)
	{
		Input_High_Scores >> High_Score[i];
		Input_High_Scores >> High_Score_Name[i];
	}
	Input_High_Scores.close();

	if (High_Score[4] == 0)
	{

	
		// Initialize local variables
		High_Score[0] = 25000;
		High_Score[1] = 12000;
		High_Score[2] = 7500;
		High_Score[3] = 4000;
		High_Score[4] = 2000;
		High_Score_Name[0] = "Gwyneth";
		High_Score_Name[1] = "Adam";
		High_Score_Name[2] = "Nastasia";
		High_Score_Name[3] = "Nicolas";
		High_Score_Name[4] = "Dani";
	}




// Show the title screen
  cout << "***********************" << endl;
  cout << "*                     *" << endl;
  cout << "* The Great Quiz Show *" << endl;
  cout << "*                     *" << endl;
  cout << "*         By          *" << endl;
  cout << "*                     *" << endl;
  cout << "*    Joshua Golden    *" << endl;
  cout << "*                     *" << endl;
  cout << "***********************" << endl;
  cout << endl;

	// Create instances of Question
	Question q1;
	Question q2;
	Question q3;
	Question q4;
	Question q5;
	Question q6;

	// Set values of the Question instances.
	q1.setValues("What does cout do?",
		"Eject a CD",
		"Send text to the printer",
		"Print text on the screen",
		"Play a sound",
		3,
		2500);
	q2.setValues("What are the two sections in a class?",
		"public and local",
		"global and local",
		"global and private",
		"public and private",
		4,
		5000);
	q3.setValues("What does cin do?",
		"Gets input from a file",
		"Gets input from the user",
		"Gets input from the computer",
		"Gets the letter c",
		2,
		2500);
	q4.setValues("Which library lets you use the cout command?",
		"String",
		"cmath",
		"fstream",
		"iostream",
		4,
		4000);
	q5.setValues("Which namespace have you used in this course?",
		"std",
		"public",
		"private",
		"include",
		1,
		3000);
	q6.setValues("Which value below could an int variable hold?",
		"Harry",
		"-3.42",
		"792",
		"October 26",
		3,
		3000);

	// Ask the questions
	q1.askQuestion();
	q2.askQuestion();
	q3.askQuestion();
	q4.askQuestion();
	q5.askQuestion();
	q6.askQuestion();

	if (Winnings >= High_Score[4])
	{
	// Get user's rank
		for (int i = 4; Winnings >= High_Score[i] && i >= 0; i--)
		{
			Rank = i;

		}
		
		// Rearrange the high scores list
		for (int i = 4; i != Rank; i--)
		{
			High_Score[i] = High_Score[i - 1];
			High_Score_Name[i] = High_Score_Name[i - 1];
		}

		cout << "You got a high score!" << endl;
		cout << "Please enter your name." << endl;
		cin >> High_Score_Name[Rank];
		High_Score[Rank] = Winnings;

	}
	// Print the high score list
	cout << "High Score List" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << High_Score[i] << "" << High_Score_Name[i] << endl;

	}
	
	// Output the high scores to a file
	ofstream Output_High_Scores;
	Output_High_Scores.open("High_Scores.txt");

	for (int i = 0; i < 5; i++)
	{
		Output_High_Scores << High_Score[i] << endl;
		Output_High_Scores << High_Score_Name[i] << endl;

	}
	Output_High_Scores.close();

	system("PAUSE");
}

// Store values for Question variables.
void Question::setValues(string q, string a1, string a2,
	string a3, string a4, int ca, int pa)
{
	Question_Text = q;
	Answer_1 = a1;
	Answer_2 = a2;
	Answer_3 = a3;
	Answer_4 = a4;
	Correct_Answer = ca;
	Prize_Amount = pa;

}

void Question::askQuestion()
{
	// Ask the question
	cout << endl;
	cout << Question_Text << endl;
	cout << "1." << Answer_1 << endl;
	cout << "2." << Answer_2 << endl;
	cout << "3." << Answer_3 << endl;
	cout << "4." << Answer_4 << endl;
	cout << endl;

	// Ask for a guess
	cout << "What is your answer?" << endl;
	cin >> Guess;

	// If user Guesses right, add Prize_Amount to Winnings.
	if (Guess == Correct_Answer)
	{
		cout << endl;
		cout << "You are correct." << endl;
		Winnings = Winnings + Prize_Amount;
		cout << "You just won $" << Prize_Amount << "!" << endl;
		cout << "Total winnings: $" << Winnings << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "You are not correct." << endl;
		cout << "Total winnins: $" << Winnings << endl;
		cout << endl;
	}
}