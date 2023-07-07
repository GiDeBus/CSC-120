/* This is a program that prompts the user for a float number input
and checks the variable for whole numbers.*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

  // Define the user input variable
  float input;
  string ProgramHeader = "This program checks for whole numbers";
  string projectName = "What You See Is What You Get Approach";
  string programmer = "Gil D.";

  // Output application header information
  cout << endl;
  cout << setw(52) << ProgramHeader << endl;
  cout << setw(24) << "Project: " << projectName << endl;
  cout << setw(30) << "Programmer(s): " << programmer << endl;
  cout << endl;


  // Prompt the user for input
  cout << "please enter a float number: " ;
  cin >> input;
  cout << endl;

  // Validate if the input is a float
  if(input == static_cast<int>(input))
  {
    cout << "The number " << input << " you enter is a whole number " << endl;
  }
  else
  {
    cout << "The number " << input << " you enter is NOT a whole number " << endl;
  }

  // Halt the screen
  cout << endl;
  cout << "Press any key to continue . . . ";
  cin.ignore();
  cin.get();

  return 0;
}

