/* 
Programmer(s): Gil
Program Name: Math Tutor 2.0
Program Description: This program behaves like a simple calculator. It accepts basic unary operators
such as -, + , *, / and %. It also has user input validation. 
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

// Function to print header banner.
void printBanner() {
  // Declare header output.
  string projectName = "Math Tutor 2.0";
  string programmer = "Gil";

  // Define variables for the operands, and operator.
  double firstOperand, secondOperand;
  char operatorSymbol;

  // Output header.
  cout << endl;
  cout << "*************************************" << endl;
  cout << setw(15) << "Project: " << projectName << endl;
  cout << setw(21) << "Programmer(s): " << programmer << endl;
  cout << "*************************************" << endl;
}

int getMenuSelection() {
  int selection;

   while(true) {
    // Output operator menu.
    cout << endl;
    cout << "**************** Menu *****************" << endl;
    cout << "1] Addition only" << endl;
    cout << "2] Subtraction only" << endl;
    cout << "3]  Multiplication only" << endl;
    cout << "4] Integer Division only" << endl;
    cout << "5] Real Division only" << endl;
    cout << "6] Modulo only" << endl;
    cout << "7] Addition and subtractions" << endl;
    cout << "8] Addition, subtraction and multiplication" << endl;
    cout << "9] Addition, subtraction, multiplication, and int division" << endl;
    cout << "10] All operators" << endl;
    cout << "11] End program" << endl;
    cout << "***************************************" << endl;
    cout << endl;

    cout  << setw(35) << "Make a selection from the menu (input integer only): ";

    if(!(cin >> selection) || selection != static_cast<int>(selection)) {
      cin.clear(); // Clear the error.
      cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
      cout << "Error: Please provide real numbers only.";
    } else if (selection < 1 || selection > 11) {
      cout << "Error: Invalid menu option. Please select a valid option." << endl;
    } else {
      break; // If input is valid it will exit the loop.
    }
  }

  return selection;
}

int getNumberOfQuestions() {
  int numberOfQuestions;

  while(true) {
    cout << "Enter number of questions on the quiz: ";
    cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
    cin.clear(); // Clear the error.

    if(!(cin >> numberOfQuestions) || numberOfQuestions != static_cast<int>(numberOfQuestions)) {
      cin.clear(); // Clear the error.
      cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
      cout << "Error: Please provide real numbers only." << endl;
    } else if (numberOfQuestions < 1) {
      cout << "Error: Please enter positive integers only." << endl;
    } else {
      break; // If input is valid it will exit the loop.
    }
  }

  return numberOfQuestions;
}

int generateRandomNumber() {
  int randomNumber;
  srand(time(0));

  return randomNumber = (rand() % (99 - 1 + 1) + 1);
}

int main() {
  printBanner();
  int userSelection = getMenuSelection();
  int numberOfQuestions = getNumberOfQuestions();

  cout << userSelection << endl;
  cout << numberOfQuestions << endl;
  return 0;
}
