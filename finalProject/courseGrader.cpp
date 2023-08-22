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

void readSyllabusFile(string fileName) {
  ifstream inputFile(fileName);
  string firstSyllabusAssignments[7] = {};
  string secondSyllabusAssignments[5] = {};
  int firstSyllabusGradings[7] = {};
  int secondSyllabusGradings[5] = {};
  int index = 0;
  char percentageSymbol;

  if(!inputFile) {
    cout << endl;  
    cout << "Error: File does not exist." << endl;
    cout << endl;
    return;
  }

  if(fileName == "syllabus.txt") {
    while(inputFile >> firstSyllabusAssignments[index] >> firstSyllabusGradings[index] >> percentageSymbol) {
      index++;
    }
  } else {
    while(inputFile >> secondSyllabusAssignments[index] >> secondSyllabusGradings[index] >> percentageSymbol) {
      index++;
    }
  }

  inputFile.close();
}

void displayMenu() {
  cout << "\n ****** Syllabus Options ****** \n" << endl;
  cout << "  syllabus or syllabus2  " << endl;
  cout << "\n ****************************** \n" << endl;
}

void getInputFile(string& selectedSyllabus) {
  string input;
  cout << "Which syllabus are you grading with: ";
  while(true) {
    if(cin >> input && (input == FIRST_SYLLABUS_FILE_NAME || input == SECOND_SYLLABUS_FILE_NAME)) {
      selectedSyllabus = input;
      break;
    }
    cin.clear();
    cin.ignore(100, '\n');
    cout << "please input a valid lowercased file name and its extension." << endl;
  }

}

int main() {
  int numberOfStudents;
  string selectedSyllabus;
  displayMenu();
  getInputFile(selectedSyllabus);
  readSyllabusFile(selectedSyllabus);
}