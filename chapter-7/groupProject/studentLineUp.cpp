/* 
  Programmer: Gil Del Busto
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
    int numStudents;
    string name;
    string inputFileName = "LineUp.txt";
    string frontStudent, endStudent;

    // Prompt the user to enter the number of students in the class
    while (true) {
        cout << "Enter the number of students in the class (1 to 25): ";
        if (cin >> numStudents && numStudents >= 1 && numStudents <= 25) {
            break;
        }
        cout << "Invalid input. Please enter a number between 1 and 25." << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }

    // Loop to read names and save them to the LineUp.txt file
    ofstream outFile(inputFileName);
    if (!outFile.fail()) {
        cin.ignore(); // Ignore the newline character from the previous input
        for (int i = 0; i < numStudents; i++) {
            cout << "Enter the name of student " << i + 1 << ": ";
            getline(cin, name);
            outFile << name << endl;

            // Determine the student in front of the line and at the end of the line
            if (i == 0) {
                frontStudent = name;
                endStudent = name;
            } else {
                frontStudent = min(frontStudent, name);
                endStudent = max(endStudent, name);
            }
        }
        outFile.close();
        cout << "Names have been saved to " << inputFileName << "." << endl;
    } else {
        cout << "Error: Unable to create " << inputFileName << "." << endl;
        return 1;
    }

    // Report the student in front of the line and at the end of the line
    cout << "The student in front of the line: " << frontStudent << endl;
    cout << "The student at the end of the line: " << endStudent << endl;

    return 0;
}
