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

// Instantiate syllabus variables to be accessible in the entire app.
const string FIRST_SYLLABUS_FILE_NAME = "syllabus.txt";
const string SECOND_SYLLABUS_FILE_NAME = "syllabus2.txt";

// LOAD SYLLABUS DATA ----------------------

// Function to display program banner.
void displayBanner() {
  cout << left << setw(24) << "Programmer(s):" << "Gilberto Del Busto" << endl
    << setw(24) << "Program Name:" << "Course Grader" << endl
    << setw(24) << "Program Description:" << "A program that grades students based on a specific syllabus and creates\n"
    << setw(24) << "" << "separate grading files for each student." << endl;
}

// Function to validate syllabus exists or cannot be opened. 
void validateInputFile(ifstream& inputFile) {
  if(!inputFile) {
  cout << endl;  
  cout << "Error: File does not exist." << endl;
  cout << endl;
  exit(1);
  }
}

// Function to open and load the content of the syllabus into an array per requirements.
void readSyllabusFile(string fileName, int size, string syllabusAssignments[], int syllabusGradings[]) {
  ifstream inputFile(fileName);
  char percentageSymbol; // We instantiate a char symbol to ignore it when reading from the file.

  validateInputFile(inputFile);
  for(int i = 0; i < size; i++) {
    inputFile >> syllabusAssignments[i] >> syllabusGradings[i] >> percentageSymbol; // Save syllabus headers and content into respective array and ignore % sign.
  }
  inputFile.close();
}

// Function to display menu options.
void displayMenu() {
  cout << "\n ****** Syllabus Options ****** \n" << endl;
  cout << "  syllabus.txt or syllabus2.txt  " << endl;
  cout << "\n ****************************** \n" << endl;
}

// Function to validate user syllabus selection. Only either choice will work, otherwise it will re-prompt.
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

// Function to set the assignment size based on the syllabus selection.
int numberOfAssignments(string selectedSyllabus) {
    if (selectedSyllabus == FIRST_SYLLABUS_FILE_NAME) {
    return 7;
  } else {
    return 5;
  }
}

// Function to call the function in charge of reading the syllabus based on the selection.
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

// Function that validates number of students. It will only accept ints.
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

// Function to generate the files depending on the number of students.
void generateStudentFileNames(int numberOfStudents, string arrayOfFileNames[]) {
  for(int i = 1; i <= numberOfStudents; i++) {
    arrayOfFileNames[i - 1] = "Student#" + to_string(i) + ".txt";
  }
} 

// Function to open and read individual student files into an array of grades and a student name variable.
void readStudentData(string fileName, string& studentName, int studentGrades[], int numberOfAssignments) {
  ifstream inputFile(fileName);
  string firstName, lastName, suffix; // Define variables for the components of the student name.
  inputFile >> ws >> firstName >> lastName >> suffix; // Get the student name and avoid the white space at the beginning using the ws method.
  studentName = firstName + "" + lastName + "" + suffix; // Save name into a variable with no spaces.
  for(int i = 0; i < numberOfAssignments; i++) { // Save grades into array.
    inputFile >> studentGrades[i];
  }
  inputFile.close();
}

// Function to validate student file exists or can be opened.
bool studentFileExists(string fileName) {
  ifstream inputFile(fileName);
  return static_cast<bool>(inputFile);
}
// Function that calls the read function if the student file exists or can be opened.
void loadStudentData(string fileName, string& studentName, int studentGrades[], int numberOfAssignments) {
  if(studentFileExists(fileName)) {
    readStudentData(fileName, studentName, studentGrades, numberOfAssignments);
    return;
  }
  cout << "Error: student did not take the exam or file does not exist." << endl; 
}
// TODO: cout should only appear when 3 students are selected not when 1??

// WRITE STUDENT FILES ----------------------

// Function to grade the assignments based on student score and assignment weight.
double gradeAssignment(int StudentScore, int AssignmentWeight) {
  double percentage = (AssignmentWeight/ 100.00);
  double grade = StudentScore * percentage;
  return grade;
}

// Function that returns true or false if student passed the final exam.
bool passingGrade(double score) {
  return (score >= 70 ? true : false);
}

// Function that grades and writes student information into individual file.
void writeStudentFile(string studentName, int syllabusGradings[], string syllabusAssignments[], int studentGrades[], int numberOfAssignments) {
  string fileName = studentName + ".txt"; // Generate filename based on student name.
  ofstream outputFile(fileName);

  // validate file existance.
  if(!outputFile) {
    cout << "Error: Creating file " + fileName << endl;
    return;
  }

  double finalScore = 0; // Set accumulator for grading.
  int finalExamIndex = numberOfAssignments - 2; // Set index so isolate final on syllabus.
  int finalExamScore = studentGrades[finalExamIndex]; // Get final exam score.
  bool studentPassed = passingGrade(finalExamScore); // Get if student passed the final or not.

  // Output table with student information.
  outputFile << "Student: " << studentName << endl;
  outputFile << "---------------------------------------------------------------" << endl;
  outputFile << left << setw(20) << "Assignment" << setw(15) << "Weight" << setw(10) << "Grade" << setw(15) << "Points" << endl;
  outputFile << "---------------------------------------------------------------" << endl;

  for (int i = 0; i < numberOfAssignments; i++) {
    // Obtain the student score on individual assignments.
    double assignmentPoints = gradeAssignment(syllabusGradings[i], studentGrades[i]);
    outputFile << left << setw(20) << syllabusAssignments[i] << setw(15) << syllabusGradings[i] << setw(13) << studentGrades[i] << setw(10) << assignmentPoints <<endl;
    // Increment the final score based on individual assignment score.
    finalScore += gradeAssignment(studentGrades[i], syllabusGradings[i]);
  }
    
  outputFile << "---------------------------------------------------------------" << endl;
  outputFile << "Course Grade: " << finalScore << "%" << endl;
  outputFile << "Final Exam Passed?: " << (studentPassed ? "true" : "false") << endl;
    
  outputFile.close();
}

int main() {
  int numberOfStudents;
  int numberOfSyllabusAssignments;
  int firstSyllabusGradings[7] = {};
  int secondSyllabusGradings[5] = {};
  int firstSyllabusDataSize = 7;
  int secondSyllabusDataSize = 5;
  int firstStudentGrades[7] = {};
  int secondStudentGrades[7] = {};
  int thirdStudentGrades[7] = {};

  string selectedSyllabus;
  string firstSyllabusAssignments[7] = {};
  string secondSyllabusAssignments[5] = {};
  string firstStudentName;
  string secondStudentName;
  string thirdStudentName;
  string studentFileNames[3];

  // Load banner
  displayBanner(); 
  
  // Display menu options
  displayMenu(); 
  
  // Get syllabus
  selectedSyllabus = getInputFile(); 
  
  // Read syllabus data
  loadSyllabus(
    selectedSyllabus, 
    firstSyllabusAssignments, 
    firstSyllabusGradings, 
    firstSyllabusDataSize, 
    secondSyllabusAssignments, 
    secondSyllabusGradings, 
    secondSyllabusDataSize
  ); 
  
  // Get number of students
  numberOfStudents = getNumberOfStudents(); 
  
  // Generate filenames for students.
  generateStudentFileNames(numberOfStudents, studentFileNames); 
  
  // Get number of assignments based on syllabus selection.
  numberOfSyllabusAssignments = numberOfAssignments(selectedSyllabus); 

  // Load each students score file data if file exists.
  loadStudentData(studentFileNames[0], firstStudentName, firstStudentGrades, numberOfSyllabusAssignments); 
  loadStudentData(studentFileNames[1], secondStudentName, secondStudentGrades, firstSyllabusDataSize);
  loadStudentData(studentFileNames[2], thirdStudentName, thirdStudentGrades, firstSyllabusDataSize);

  // Write and grade student data files if files exists, if not output error.
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