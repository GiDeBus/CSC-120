/* 
  Programmer: Gil Del Busto
  Program: Functions Lab
  Description: This program prompts the user for personal info and displays it using separate functions. 

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// function to display banner.
void displayBanner() {
  // Declare banner variables.
  string ProgramHeader = "Description: Display User Info with Functions";
  string projectName = "Display Info";
  string programmer = "Gil";

  // Output banner.
  cout << endl;
  cout << ProgramHeader << endl;
  cout << "Project: " << projectName << endl;
  cout << "Programmer(s): " << programmer << endl;
  cout << endl;
}

// function to parse int into positive.
int getAge(int age) {
  if (age < 0) {
    return abs(age);
  }
  return age;
}

// function that prompts user for info.
void displayUserInfo() {
  string name;
  int age;

  // prompt for user's name.
  cout << "Enter your name: ";
  getline(cin, name);

  // prompt for user's age.
  cout << "Enter your age: ";
  cin >> age;
  cin.ignore(100, '\n');

  // output user information.
  cout << endl;
  cout << "Your name is: " << name << endl;
  cout << "Your age is: " << getAge(age) << endl;
}

// main function to run the program.
int main() {
  displayBanner();
  displayUserInfo();
  return 0;
}