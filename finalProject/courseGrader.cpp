/* 
Programmer(s): Gilberto Del Busto
Program Name: Course Grader
Program Description: A program that grades students based on a specific syllabus and creates
  separate grading files for each student.
*/

// TODO: Add comments to code. 
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

const string FIRST_SYLLABUS_FILE_NAME = "syllabus.txt";
const string SECOND_SYLLABUS_FILE_NAME = "syllabus2.txt";

// LOAD SYLLABUS DATA ----------------------
void displayBanner() {
  cout << left << setw(24) << "Programmer(s):" << "Gilberto Del Busto" << endl
    << setw(24) << "Program Name:" << "Course Grader" << endl
    << setw(24) << "Program Description:" << "A program that grades students based on a specific syllabus and creates\n"
    << setw(24) << "" << "separate grading files for each student." << endl;
}

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

int numberOfAssignments(string selectedSyllabus) {
    if (selectedSyllabus == FIRST_SYLLABUS_FILE_NAME) {
    return 7;
  } else {
    return 5;
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

// LOAD STUDENT DATA ----------------------

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

void readStudentData(string fileName, string& studentName, int studentGrades[], int numberOfAssignments) {
  ifstream inputFile(fileName);
  string firstName, lastName, suffix;
  inputFile >> ws >> firstName >> lastName >> suffix;
  studentName = firstName + "" + lastName + "" + suffix;
  for(int i = 0; i < numberOfAssignments; i++) {
    inputFile >> studentGrades[i];
  }
  inputFile.close();
}

bool studentFileExists(string fileName) {
  ifstream inputFile(fileName);
  return static_cast<bool>(inputFile);
}

void loadStudentData(string fileName, string& studentName, int studentGrades[], int numberOfAssignments) {
  if(studentFileExists(fileName)) {
    readStudentData(fileName, studentName, studentGrades, numberOfAssignments);
    return;
  }
  cout << "Error: student did not take the exam or file does not exist." << endl; // TODO: cout should only appear when 3 students are selected not when 1??
}

// WRITE STUDENT FILES ----------------------

double gradeAssignment(int score, int AssignmentWeight) {
  double percentage = (AssignmentWeight/ 100.00);
  double grade = score * percentage;
  return grade;
}

bool passingGrade(double score) {
  return (score >= 70 ? true : false);
}

void writeStudentFile(string studentName, int syllabus[], string syllabusAssignments[], int studentGrades[], int numberOfAssignments) {
  string fileName = studentName + ".txt";
  ofstream outputFile(fileName);
  double finalScore = 0;
  bool studentPassed;
  int index = numberOfAssignments - 2;
  int finalExamScore = studentGrades[index];

  if(!outputFile) {
    cout << "Error: Creating file " + fileName << endl;
    return;
  }

  outputFile << "Student: " << studentName << endl;
  outputFile << "---------------------------------------------------------------" << endl;
  outputFile << left << setw(20) << "Assignment" << setw(15) << "Weight" << setw(10) << "Grade" << setw(15) << "Points" << endl;
  outputFile << "---------------------------------------------------------------" << endl;

  for (int i = 0; i < numberOfAssignments; i++) {
    outputFile << left << setw(20) << syllabusAssignments[i] << setw(15) << syllabus[i] << setw(13) << studentGrades[i] << setw(10) << gradeAssignment(syllabus[i], studentGrades[i]) <<endl;
    finalScore += gradeAssignment(studentGrades[i], syllabus[i]);
  }

  studentPassed = passingGrade(finalExamScore);
    
  outputFile << "---------------------------------------------------------------" << endl;
  outputFile << "Course Grade: " << finalScore << "%" << endl;
  outputFile << "Final Exam Pass/Fail: " << (studentPassed ? "true" : "false") << endl;
    
  outputFile.close();
}

int main() {
  int numberOfStudents;
  string selectedSyllabus;
  int numberOfSyllabusAssignments;
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

  displayBanner();
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
  numberOfSyllabusAssignments = numberOfAssignments(selectedSyllabus);
  cout << "assignments: " << numberOfSyllabusAssignments << endl;
  loadStudentData(fileNames[0], firstStudentName, firstStudentGrades, numberOfSyllabusAssignments);
  loadStudentData(fileNames[1], secondStudentName, secondStudentGrades, firstSyllabusDataSize);
  loadStudentData(fileNames[2], thirdStudentName, thirdStudentGrades, firstSyllabusDataSize);
  if(numberOfSyllabusAssignments > 5) {
      writeStudentFile(firstStudentName, firstSyllabusGradings, firstSyllabusAssignments, firstStudentGrades, numberOfSyllabusAssignments);
      writeStudentFile(secondStudentName, firstSyllabusGradings, firstSyllabusAssignments, secondStudentGrades, numberOfSyllabusAssignments);
      writeStudentFile(thirdStudentName, firstSyllabusGradings, firstSyllabusAssignments, thirdStudentGrades, numberOfSyllabusAssignments);
  } else {
    writeStudentFile(firstStudentName, secondSyllabusGradings, secondSyllabusAssignments, firstStudentGrades, numberOfSyllabusAssignments);
    writeStudentFile(secondStudentName, secondSyllabusGradings, secondSyllabusAssignments, secondStudentGrades, numberOfSyllabusAssignments);
    writeStudentFile(thirdStudentName, secondSyllabusGradings, secondSyllabusAssignments, thirdStudentGrades, numberOfSyllabusAssignments);
  }
}