/* 
Programmer(s): Gilberto Del Busto
Program Name: Course Grader
Program Description: A program that grades students based on a specific syllabus and creates
  separate grading files for each student.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const string FIRST_SYLLABUS_FILE_NAME = "syllabus.txt";
const string SECOND_SYLLABUS_FILE_NAME = "syllabus2.txt";

// LOAD SYLLABUS DATA
// ----------------------

void validateInputFile(ifstream& inputFile) {
  if(!inputFile) {
  cout << endl;  
  cout << "Error: File does not exist." << endl;
  cout << endl;
  exit(1);
  }
}

void readSyllabusFile(string fileName, int size, string syllabusAssignments[], int syllabusGradings[]) {
  ifstream inputFile(fileName);
  char percentageSymbol;

  validateInputFile(inputFile);
  for(int i = 0; i < size; i++) {
    inputFile >> syllabusAssignments[i] >> syllabusGradings[i] >> percentageSymbol;
  }
  inputFile.close();
}

void displayMenu() {
  cout << "\n ****** Syllabus Options ****** \n" << endl;
  cout << "  syllabus.txt or syllabus2.txt  " << endl;
  cout << "\n ****************************** \n" << endl;
}

string getInputFile() {
  string input;
  cout << "Which syllabus are you grading with: ";
  while(true) {
    if(cin >> input && (input == FIRST_SYLLABUS_FILE_NAME || input == SECOND_SYLLABUS_FILE_NAME)) {
      return input;
    }
    cin.clear();
    cin.ignore(100, '\n');
    cout << "please input a valid lowercased file name and its extension." << endl;
  }
}

void loadSyllabus(string selectedSyllabus, string firstSyllabusAssignments[], int firstSyllabusGradings[],
  int& firstSyllabusDataSize, string secondSyllabusAssignments[], int secondSyllabusGradings[],
  int& secondSyllabusDataSize) {
  if (selectedSyllabus == FIRST_SYLLABUS_FILE_NAME) {
    readSyllabusFile(selectedSyllabus, firstSyllabusDataSize, firstSyllabusAssignments, firstSyllabusGradings);
  } else {
    readSyllabusFile(selectedSyllabus, secondSyllabusDataSize, secondSyllabusAssignments, secondSyllabusGradings);
  }
}

// LOAD STUDENT DATA
// ----------------------

int getNumberOfStudents() {
  int input;
  cout << "How many students are in the course? ";
  while(true) {
    if(cin >> input && (input >= 1 || input <= 3 )) {
      return input;
    }
    cin.clear();
    cin.ignore(100,'\n');
    cout << "Please enter a valid int between 1 and 3: ";
  }
}

void generateStudentFileNames(int numberOfStudents, string arrayOfFileNames[]) {
  for(int i = 1; i <= numberOfStudents; i++) {
    arrayOfFileNames[i - 1] = "Student#" + to_string(i) + ".txt";
  }
} 

void readStudentData(string fileName, string studentName, int studentGrades[], int numberOfAssignments) {
  ifstream inputFile(fileName);
  getline(inputFile >> ws, studentName);
  cout << studentName << endl;
  for(int i = 0; i < numberOfAssignments; i++) {
    inputFile >> studentGrades[i];
    cout << studentGrades[i] << endl;
  }
  inputFile.close();
}

bool studentFileExists(string fileName) {
  ifstream inputFile(fileName);
  return static_cast<bool>(inputFile);
}

void loadStudentData(string fileName, string studentName, int studentGrades[], int numberOfAssignments) {
  if(studentFileExists(fileName)) {
    readStudentData(fileName, studentName, studentGrades, numberOfAssignments);
    return;
  }
  cout << "Error: " << fileName << " does not exist or student did not take the exam." << endl;
}

int main() {
  int numberOfStudents;
  string selectedSyllabus;
  string firstSyllabusAssignments[7] = {};
  string secondSyllabusAssignments[5] = {};
  int firstSyllabusGradings[7] = {};
  int secondSyllabusGradings[5] = {};
  int firstSyllabusDataSize = 7;
  int secondSyllabusDataSize = 5;

  string firstStudentName;
  string secondStudentName;
  string thirdStudentName;
  string fileNames[3];
  int firstStudentGrades[7] = {};
  int secondStudentGrades[7] = {};
  int thirdStudentGrades[7] = {};

  displayMenu();
  selectedSyllabus = getInputFile();
  loadSyllabus(
    selectedSyllabus, 
    firstSyllabusAssignments, 
    firstSyllabusGradings, 
    firstSyllabusDataSize, 
    secondSyllabusAssignments, 
    secondSyllabusGradings, 
    secondSyllabusDataSize
  );
  numberOfStudents = getNumberOfStudents();
  generateStudentFileNames(numberOfStudents, fileNames);
  loadStudentData(fileNames[0], firstStudentName, firstStudentGrades, firstSyllabusDataSize);
  loadStudentData(fileNames[1], secondStudentName, secondStudentGrades, firstSyllabusDataSize);
  loadStudentData(fileNames[2], thirdStudentName, thirdStudentGrades, firstSyllabusDataSize);
}