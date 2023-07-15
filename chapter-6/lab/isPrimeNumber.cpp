/* This program prompts the user for a number and returns if its a prime number. */

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  // Declare header output.
  string ProgramHeader = "Description: A Program that returns if a number is prime";
  string projectName = "isPrimeNumber";
  string programmer = "Gil";

  // Define user input variable.
  int userInput;
  int primeNumbersLowerBound = 2;
  char selection;
  bool isInputValid = false;
  bool isPrime = true;
  bool keepGoing = true;

   // Output application header information
  cout << endl;
  cout << setw(52) << ProgramHeader << endl;
  cout << setw(24) << "Project: " << projectName << endl;
  cout << setw(30) << "Programmer(s): " << programmer << endl;
  cout << endl;

  // Main program loop. It will keep prompting user for prime numbers.
  while(keepGoing) {
  
    /* Input validation loop. It will coerce the user to input 
    a positive integer and not characters */
    while(!isInputValid) {
      cout << "Enter an integer: ";
      if (cin >> userInput) {
        if (userInput > 0) {
          isInputValid = true;
        } else {
          cout << endl;
          cout << "Error: Invalid input. Please enter a positive number." << endl;
          cout << endl;
        }
      } else {
        cout << endl;
        cout << "Error: Invalid input. Please enter an integer." << endl;
        cout << endl;
        cin.clear();
        cin.ignore(100, '\n');
      }
    }
    
    /* Loop to validate if number is prime. It checks if number 
    is only divisible by 1 and itself. Looping bounds are 2 to number - 1
    to prevent a true statement */

    for (int i = primeNumbersLowerBound; i < userInput; i++) {
      if (userInput % i == 0) {
        isPrime = false;
        break;
      } 
    }

    // Print result based
    if (isPrime == true) {
      cout << endl;
      cout << userInput << " is a prime number. It is only divisible by 1 and itself" << endl;
      cout << endl;
    } else {
      cout << endl;
      cout << userInput << " is not a prime number." << endl;
      cout << endl;
    }

    // Clear keyboard buffer and ask for re-run of program
    cout << "Press enter to run the program again . . . ";
    cin.clear();
    cin.ignore(100,'\n');
    selection = cin.get();

    // Check for enter as input. If so, reset run variables, else exit loop.
    if (selection == '\n') {
      isInputValid = false;
      isPrime = true;
    } else {
      cout << selection << endl;
      keepGoing = false;
    }
  }

  return 0;
}