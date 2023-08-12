/* 
  Programmer: Gil Del Busto
  Program: Array Manipulation Lab
  Description: This program prompts the user for a menu to manipulate arrays. 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// Function to display banner.
void displayBanner() {
  // Declare banner variables.
  string ProgramHeader = "Description: Array Manipulation Lab";
  string projectName = "Array Manipulator";
  string programmer = "Gil";

  // Output banner.
  cout << endl;
  cout << ProgramHeader << endl;
  cout << "Project: " << projectName << endl;
  cout << "Programmer(s): " << programmer << endl;
  cout << endl;
}

// Function to display menu.
void displayMenu() {
  cout << endl;
  cout << "*************************************" << endl;
  cout << "Select the character from the following option: " << endl;
  cout << "a. Add Array" << endl;
  cout << "b. Subtract Array" << endl;
  cout << "c. Multiply Array" << endl;
  cout << "d. Exit" << endl;
  cout << "*************************************" << endl;
  cout << endl;
}

// Function to validate menu input.
char getMenuOption(char& selection) {
  cout << "Your selection: ";
  while(true) {
    if(cin >> selection && (selection >= 'a' && selection <= 'd')) {
      break;
    } // If not valid input it will re-prompt.
    cout << "Please input a valid option: ";
    cin.clear();
    cin.ignore(100, '\n');
  }
  cout << endl;
  return selection;
}

// Function to add the elements of the array.
void addArray(int array1[], int array2[], int result[], int size) {
  for (int i = 0; i < size; ++i) {
    result[i] = array1[i] + array2[i];
  }
}

// Function to subtract the elements of the array.
void subtractArray(int array1[], int array2[], int result[], int size) {
  for (int i = 0; i < size; ++i) {
    result[i] = array1[i] - array2[i];
  }
}

// Function to multiply the elements of the array.
void multiplyArray(int array1[], int array2[], int result[], int size) {
  for (int i = 0; i < size; i++) {
    result[i] = array1[i] * array2[i];
  }
}

// Function to print an array.
void printArray(int array[], int size) {
  for(int i = 0; i < size; i++) {
    cout << array[i] << " "; // Print the value of each element
  }
  cout << endl;
}

int main() {
  bool keepGoing = true;
  char selection;
  const int SIZE = 7;
  int array1[SIZE] = {0, 1, 2, 3, 4, 5, 6};
  int array2[SIZE] = {20, 15, 10, 5, 0, 2, 4};
  int result[SIZE] = {0};

  displayBanner(); // call the banner once.
  while(keepGoing) {
    displayMenu();
    getMenuOption(selection);
    // Control flow on user selection.
    if(selection == 'a') {
      addArray(array1, array2, result, SIZE);
      printArray(result, SIZE);
    }

    if(selection == 'b') {
      subtractArray(array1, array2, result, SIZE);
      printArray(result, SIZE);
    }

    if(selection == 'c') {
      multiplyArray(array1, array2, result, SIZE);
      printArray(result, SIZE);
    }

    // Exits program.
    if(selection == 'd') {
      cout << "Thank you for using array manipulator. Bye for now!" << endl;
      break;
    }
  }
  return 0;
}
