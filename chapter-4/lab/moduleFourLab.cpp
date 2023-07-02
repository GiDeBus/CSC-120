/* This program provides a mathTutor for subtractions.
It outputs two numbers and asks the user to solve the subtraction.
If the input is wrong it displays the value, if the input is correct
it congratulates the user. */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  // Declare header output.
  string ProgramHeader = "Description: Math Tutor for subtractions";
  string projectName = "Subtraction Math Tutor";
  string programmer = "Gil";

  // Define operands and variables for user input.
  srand(time(0)); // Seed the random number generator.
  int firstOperand = (rand() % (99 - 1 + 1) + 1);
  int secondOperand = (rand() % (99 - 1 + 1) + 1);
  int userInput;
  int correctAnswer = firstOperand - secondOperand;

  // Output header
  cout << endl;
  cout << ProgramHeader << endl;
  cout << "Project: " << projectName << endl;
  cout << "Programmer(s): " << programmer << endl;

  // Output operands and ask for user input.
  cout << endl;
  cout << endl;
  cout << "Solve" << endl;
  cout << endl;
  cout << setw(4) << firstOperand << endl;
  cout << setw(2) << "-" << secondOperand << endl;
  cout << "======" << endl;
  cout << "  ";
  cin >> userInput;
  cout << "======" << endl;

  // Check if user input is correct.
  if(userInput == correctAnswer) // Correct answer output.
  {
    cout << endl;
    cout << "Good Job!" << endl;
  }
  else // Wrong answer output.
  {
  cout << endl;
  cout << "Wrong answer! The answer is: " << correctAnswer << endl;
  }

  return 0;
}