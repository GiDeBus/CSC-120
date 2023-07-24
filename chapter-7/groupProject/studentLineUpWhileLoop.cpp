/* 
  Programmer: Gil, Nam, Prajwool
  Program: Student Organizer Group Project
  Description: This program prompts the user for a number of students. 
  It writes a file and outputs the first and last students. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int numberOfStudents;
  int counter = 0;
  string name;
  string inputFileName = "LineUp.txt";
  string frontOfLineStudent, endOfLineStudent;
  ofstream outFile;
  ifstream inFile;

  // Prompt the user to enter the number of students in the class
  while (true) {
    cout << "Enter the number of students in the class (1 to 25): ";
    if (cin >> numberOfStudents && numberOfStudents >= 1 && numberOfStudents <= 25) {
      break;
    }
    cout << "Invalid input. Please enter a number between 1 and 25." << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }

  // Loop to read names and save them to the LineUp.txt file
  outFile.open(inputFileName);
  if (!outFile.fail()) {
    cin.ignore(); // Ignore the newline character from the previous input
    for (int i = 0; i < numberOfStudents; i++) {
      cout << "Enter the name of student " << i + 1 << ": ";
      getline(cin, name);
      outFile << name << endl;
    }
    outFile.close();
    cout << "Names have been saved to " << inputFileName << "." << endl;
  } else {
    cout << "Error: Unable to create " << inputFileName << "." << endl;
    return 1;
  }

  inFile.open(inputFileName);

  if(!inFile) {
    cout << "Error: Could not open file or does not exist" << endl;
  } 

  while(getline(inFile, name)) {
    // Determine the student in front of the line and at the end of the line
    if (counter == 0) {
      frontOfLineStudent = name;
      endOfLineStudent = name;
    } else {
      frontOfLineStudent = (frontOfLineStudent < name) ? frontOfLineStudent : name;
      endOfLineStudent = (endOfLineStudent > name) ? endOfLineStudent : name;
    }
    counter++;
  }

  inFile.close();

  // Report the student in front of the line and at the end of the line
  cout << "The student in front of the line: " << frontOfLineStudent << endl;
  cout << "The student at the end of the line: " << endOfLineStudent << endl;

  return 0;
}
