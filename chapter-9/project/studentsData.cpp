/* 
Programmer(s): Gil Del Busto
Program Name: Students Data
Program Description: A program that answers inquiries about all students data or an individual student by id.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Function to display the main menu.
void displayMenu() {
  cout << endl;
  cout << "***************** Menu ******************" << endl;
  cout << "a. View all students’ records" << endl;
  cout << "b. View a student’s records by ID" << endl;
  cout << "c. Show the highest and the lowest final scores" << endl;
  cout << "d. Exit" << endl;
  cout << "*****************************************" << endl;
  cout << endl;
}

// Function to get and validate user choice from main menu.
void getUserInput(char& selection) {
  cout << endl;
  cout << "Make a selection: ";
  // Keep prompting until value is valid.
  while(true) {
    if (cin >> selection && (selection >= 'a' && selection <= 'd')) {
      break;
    }   
    // If not valid keep prompting and reset value.
    cout << endl;
    cout << "Please enter a valid input: ";
    cin.clear();
    cin.ignore(100, '\n');
  }
}

// Function that reads txt file and saves info to a two dimensional array.
void readStudentInfoFromFile(int studentData[][5], string headers[], int NUMBER_OF_STUDENTS, int NUMBER_OF_HEADERS) {
  // Define file.
  ifstream inputFile("studentgrade.txt");
  
  // Validate file exists.
  if (!inputFile) {
    cout << endl;  
    cout << "Error opening file." << endl;
    cout << endl;
  }

  // Save header values into string array.
  for( int i = 0; i < NUMBER_OF_HEADERS; i++) {
    inputFile >> headers[i];
  }

 // Skip the header row
  string header;
  getline(inputFile, header);

  // Saves student data into a two dimensional array.
  for (int i = 0; i < NUMBER_OF_STUDENTS; i++) {
    for(int j = 0; j < NUMBER_OF_HEADERS; j++) {
      inputFile >> studentData[i][j];
    }
  }

  // Close file.
  inputFile.close();

}

// Function to print headers to screen.
void printHeaders(string headers[], int size) {
  // Print all headers
  cout << endl;
  for(int i = 0; i < size; i++) {
    cout << setw(9) << headers[i] << " ";
  }
  cout << endl;
}

// Function that display all students.
void viewAllStudents(int data[][5], string headers[], int rows, int columns) {
  // Print student data
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++) {
      cout << setw(9) << data[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Function to get and validate student id input from user.
int getStudentId() {
  int studentId = 0;
  // keep prompting until a valid input is given.
  while(true) {
    cout << endl;
    cout << "Input a student ID: ";
    if(cin >> studentId && (studentId == 102 || studentId == 104 || studentId == 220 || studentId == 201)) {
      break;
    }
    // Output error message if input is not valid.
    cout << endl;
    cout << "Error: Please input a valid ID" << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }
  return studentId;
}

// Function that searches the matching student id and gets the index to the print the student info
void viewSingleStudent(int studentId, int studentData[][5], string headers[], int rows, int columns) {
  // get index of student from array
  int index;
  for(int i = 0; i < rows; i++) {
    if(studentData[i][0] == studentId) {
      index = i;
      break;
    }
  }
  cout << endl;
  // loop through array to get student info
  for(int k = 0; k < columns; k++) {
    cout << setw(9) << studentData[index][k] << " ";
  }
  cout << endl;
}

// Function to return the highest and lowest scores.
void viewHighAndLowScores(int studentData[][5], string headers[], int rows, int columns) {
  // Set each value to the first element of the final scores array.
  int lowestScore = studentData[0][4]; 
  int highestScore = studentData[0][4];
  
  cout << endl;

  // If value is higher/lower than saved value then replace.
  for(int i = 1; i < rows; i++) {
    if(studentData[i][rows] < lowestScore) {
      lowestScore = studentData[i][rows];
    }

    if(studentData[i][rows] > highestScore) {
      highestScore = studentData[i][rows];
    }
  }

  // Print out scores.
  cout << "The lowest score was: " << lowestScore << endl;
  cout << "The highest score was: " << highestScore << endl;
}

int main() {
  char selection;
  const int NUMBER_OF_HEADERS = 5;
  const int NUMBER_OF_STUDENTS = 4;
  int studentData[NUMBER_OF_STUDENTS][NUMBER_OF_HEADERS] = {};
  int studentId;
  string headers[NUMBER_OF_HEADERS] = {};

  displayMenu();
  readStudentInfoFromFile(studentData, headers, NUMBER_OF_STUDENTS, NUMBER_OF_HEADERS);

  while(true) {
    getUserInput(selection);
    if(selection == 'a') {
      printHeaders(headers, NUMBER_OF_HEADERS);
      viewAllStudents(studentData, headers, NUMBER_OF_STUDENTS, NUMBER_OF_HEADERS);
    }

    if(selection == 'b') {
      studentId = getStudentId();
      printHeaders(headers, NUMBER_OF_HEADERS);
      viewSingleStudent(studentId, studentData, headers, NUMBER_OF_STUDENTS, NUMBER_OF_HEADERS);
    }

    if(selection == 'c') {
      viewHighAndLowScores(studentData, headers, NUMBER_OF_STUDENTS, NUMBER_OF_HEADERS);
    }

    if(selection == 'd') {
      cout << endl;
      cout << "Thank you for using our students database. Goodbye!" << endl;
      break;
    }
  }
  return 1;
}
