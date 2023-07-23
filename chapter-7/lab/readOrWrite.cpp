/* 
  Programmer: Gil Del Busto
  Program: Read or Write Lab
  Description: This program prompts the user for a selection. It allows the user to read or write a file. 

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
  bool keepGoing = true;
  char userChoice;
  char middleInitial;
  string fileName;
  string firstName;
  string lastName;
  string address;
  string line;
  int age;

  ifstream infile;
  ofstream outfile;

  // Loop to create the Menu
  while(keepGoing) {

    // Output menu options
    cout << endl;
    cout << "a. Create a file" << endl;
    cout << "b. Read a file" << endl;
    cout << "c. Exit" << endl;
    
    // Get user selection.
    cout << endl;
    cout << "Make a selection (Only enter the character Ex. a): ";
    cout << endl;
    cin >> userChoice;
    cin.clear();
    cin.ignore(100, '\n');

    // CREATE A FILE // 
    if(userChoice == 'a') {
      cout << endl;
      cout << "You chose to create a file" << endl;
      cout << endl;

      // Get file name form the user.
      cout << "Enter a filename with extension (Ex. file.txt): ";
      getline(cin, fileName);

      // Create file.
      outfile.open(fileName);

      if(outfile) {
        cout << endl;
        cout << "File was created" << endl;
        cout << endl;

        // Get first name from user and write it to file.
        cout << "Enter first name: ";
        cin >> firstName;
        outfile << "First Name: " << firstName << endl;
        cout << endl;

        // Get initial name from user and write it to file.
        cout << "Enter middle initial (without period, Ex. J): ";
        cin >> middleInitial;
        outfile << "Middle Initial: " << middleInitial << endl;
        cout << endl;

        // Get last name from user and write it to file.
        cout << "Enter last name: ";
        cin >> lastName;
        outfile << "Last Name: " << lastName << endl;
        cout << endl;

        // Get address from user and write it to file.
        cout << "Enter address: ";
        cin.ignore();
        getline(cin, address);
        outfile << "Address: " << address << endl;
        cout << endl;

        // Get address from user and write it to file.
        cout << "Enter age: ";
        cin >> age;
        outfile << "Age: " << age << endl;

        // Close file
        outfile.close();

        cout << endl;
        cout << "File created and information saved successfully!" << endl;
        cout << endl;

      } else { 
        
        // Output error if file cannot be created.
        cout << "Error: Could not create file or invalid input given.";
        cout << endl;
        return 1;
      }
    }

    // READ A FILE // 
    if(userChoice == 'b') {
      cout << endl;
      cout << "You chose to read a file" << endl;
      cout << endl;

      // Get filename from user
      cout << "Enter the filename including the extension (Ex. file.txt): ";
      cin >> fileName;

      // Open file
      infile.open(fileName);

      // Validate if file exists
      if (!infile) {
          cout << "Error: Could not open file or does not exist" << endl;
      } else {
        cout << endl;
        cout << "File contents:" << endl;

        // Output content from file until empty
        while (getline(infile, line)) {
            cout << line << endl;
        }

        // Close file
        infile.close();
      }
    }

    // EXIT PROGRAM // 
    if(userChoice == 'c') {
      cout << endl;
      cout << "You chose c, exit the program" << endl;
      cout << endl;

      // Set boolean to false to exit program
      keepGoing = false;
      continue; // Skips the re-run program prompt
    }
    
    // Prompt user to re-run the program
    cout << endl;
    while (true) {
      cout << "Would you like to run the program again? (yes or no): ";

      string response;
      cin >> response;
      cin.clear();
      cin.ignore(100, '\n');

      if (response == "yes") {
        cout << "Re-running program" << endl;
        cout << endl;
        break; // Exit the loop if response is "yes"
      } else if (response == "no") {
        keepGoing = false;
        break; // Exit the loop if response is "no"
      } else {
        cout << endl;
        cout << "Invalid response. Please enter 'yes' or 'no'." << endl;
        cout << endl;
      }
    }
  }
  return 0;
}