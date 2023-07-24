/*
  Project Name: Factorial
  Programmer(s): Gil Del Busto, Nam Nguyen, Prajwool Rana, Autino Vicente
  Description: This program prompts the user for a whole positive number
  and returns the factorial of such number.
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int main() {

  // Define input variables
  bool isInputValid = false;
  int userInput;
  int counter = 1;
  int result = 1;

  cout << "Enter a whole positive integer: ";

  // Prompt user for input
  while(!isInputValid) {
    if(cin >> userInput) { // Validates input is a number and not a character
      if(userInput > 0) { // Validates input is a positive number
        isInputValid = true;
      } else {
          cout << endl;
          cout << "Error: Invalid input. Please enter a positive number: ";
          cout << endl;
      }
    } else {
        cout << endl;
        cout << "Error: Invalid input. Please enter an integer: ";
        cout << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
  }

  // Performs the calculator of the factorial
  while(counter <= userInput) {
    result *= counter;
    counter++;
  }

  // reduce counter for screen output
  counter--;

  // Outputs the beginning of the formatted result
  cout << endl;
  cout << userInput << "! = ";

  // Loops through the counter again to provide the desired output based on the project criteria.
  // Ex.  5! = 5*4*3*2*1 = 120.

  while(counter > 1) {
    cout << counter << "*";
    counter--;
  }

  cout << "1 = " << result << endl;

}