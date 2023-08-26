#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// File Writing Functions
void writeBanner(ofstream& fileName);
void writeQuestion(int num1, int num2, char op, int questionNumber, int totalNumberOfQuestions, ofstream& fileName);
void writeSummary(int correctAnswers, int partialCorrectAnswers, int totalQuestions, ofstream& fileName);

// Terminal Output Functions
void displayBanner();
void displayQuestion(int num1, int num2, char op, int questionNumber, int totalNumberOfQuestions);
void displaySummary(int correctAnswers, int partialCorrectAnswers, int totalQuestions);

// Function to display the project banner
void displayBanner() {
  cout << "*************************************" << endl;
  cout << "*        This is Math Tutor 2       *" << endl;
  cout << "*  Written by [Gil, Prajwol, Nam]   *" << endl;
  cout << "*************************************" << endl;
}

void writeBanner(ofstream& fileName) {
  fileName << "*************************************" << endl;
  fileName << "*        This is Math Tutor 2       *" << endl;
  fileName << "*  Written by [Gil, Prajwol, Nam]   *" << endl;
  fileName << "*************************************" << endl;
}
// Function to display the main menu and get user's choice
int getMenuChoice() {
  int choice;
  cout << "\nPlease choose from the following options:\n";
  cout << "1] Addition only\n";
  cout << "2] Subtraction only\n";
  cout << "3] Multiplication only\n";
  cout << "4] Integer Division only\n";
  cout << "5] Real Division only\n";
  cout << "6] Modulo only\n";
  cout << "7] Addition and subtractions\n";
  cout << "8] Addition, subtraction and multiplication\n";
  cout << "9] Addition, subtraction, multiplication, and int division\n";
  cout << "10] All operators\n";
  cout << "11] End program\n";

  while (true) {
    cout << "Enter your choice: ";
    if (cin >> choice && choice >= 1 && choice <= 11) {
      break;
    } else {
      cout << "Invalid input. Please enter a valid option (1-11).\n";
      cin.clear();
      cin.ignore(100, '\n');
    }
  }

  return choice;
}

// Function to get the number of questions from the user
int getNumberOfQuestions() {
  int numQuestions;

  cout << "Enter the number of questions you want to have in the quiz: ";
  while (!(cin >> numQuestions) || numQuestions < 0) {
    cout << "Invalid input. Please enter a positive integer value.\n";
    cin.clear();
    cin.ignore(100, '\n');
  }

  return numQuestions;
}

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Function to generate a random operator based on user's choice
char generateRandomOperator(int choice) {
    switch (choice) {
        case 1:
            return '+';
        case 2:
            return '-';
        case 3:
            return '*';
        case 4:
            return '/';
        case 5:
            return '/';
        case 6:
            return '%';
        case 7:
        case 8:
        case 9:
        case 10:
            int randomOp = generateRandomNumber(1, 4);
            switch (randomOp) {
                case 1:
                    return '+';
                case 2:
                    return '-';
                case 3:
                    return '*';
                case 4:
                    return '/';
            }
    }

    return '+';
}

// Function to perform the math operation based on the operator
double performOperation(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return static_cast<double>(num1) / num2;
        case '%':
            return num1 % num2;
    }

    return 0.0;
}

string getUserInput() {
  string userInput;
  while(!(cin >> userInput) || (userInput != "yes" && userInput != "no")) {
    cout << "Invalid input. Please enter a valid lowercase choice: yes/no.\n";
    cin.clear();
    cin.ignore(100, '\n');
  }

  return userInput;
}

// Function to display and validate user input for questions
void displayQuestion(int num1, int num2, char op, int questionNumber, int totalNumberOfQuestions) {
  cout << "\nQuestion " << questionNumber << " of " << totalNumberOfQuestions << "\n";
  cout << "\n            " << num1 << "\n\n";
  cout << "      " << op << "     " << num2 << "\n";
  cout << "        ______\n";
}

void displaySummary(int correctAnswers, int partialCorrectAnswers, int totalQuestions) {
  double score = (static_cast<double>(correctAnswers) + 0.5 * partialCorrectAnswers) / totalQuestions * 100.0;
  cout << "\n*******************************************";
  cout << "\n\tYou got " << correctAnswers << " correct answers";
  cout << "\n\tand " << partialCorrectAnswers << " partially correct answers";
  cout << "\n\tout of " << totalQuestions << " questions asked.";
  cout << "\n\tYou scored: " << fixed << setprecision(2) << score << "%" << endl;
  cout << "*******************************************\n";
}

void writeQuestion(int num1, int num2, char op, int questionNumber, int totalNumberOfQuestions, ofstream& fileName) {
  fileName << "\nQuestion " << questionNumber << " of " << totalNumberOfQuestions << "\n";
  fileName << "\n            " << num1 << "\n\n";
  fileName << "      " << op << "     " << num2 << "\n";
  fileName << "        ______\n";
}

void writeSummary(int correctAnswers, int partialCorrectAnswers, int totalQuestions, ofstream& fileName) {
  double score = (static_cast<double>(correctAnswers) + 0.5 * partialCorrectAnswers) / totalQuestions * 100.0;
  fileName << "\n*******************************************";
  fileName << "\n\tYou got " << correctAnswers << " correct answers";
  fileName << "\n\tand " << partialCorrectAnswers << " partially correct answers";
  fileName << "\n\tout of " << totalQuestions << " questions asked.";
  fileName << "\n\tYou scored: " << fixed << setprecision(2) << score << "%" << endl;
  fileName << "*******************************************\n";
}

double getUserAnswer() {
  double userAnswer;
  while(!(cin >> userAnswer)) {
    cout << "Invalid input. Please enter a number." << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }
  return userAnswer;
}

int main() {
  srand(static_cast<unsigned>(time(0)));
  int totalQuestions = 0;
  int correctAnswers = 0;
  int partialCorrectAnswers = 0;
  int choice; 
  bool isSolved = false;
  ofstream reportFile("Report.txt");
  
  if(!reportFile.is_open()) {
    cout << "Error: Unable to save report to file." << endl;
  }

  while (true) {
    displayBanner();
    writeBanner(reportFile);
    choice = getMenuChoice(); // Assign choice here

    if (choice == 11) {
      string message = "You did not practice any questions. Goodbye!";
      cout << message << endl;
      reportFile << message << endl;
      break;
    }

    int numQuestions = getNumberOfQuestions();

    for (int i = 1; i <= numQuestions; i++) {
      int num1 = generateRandomNumber(1, 99);
      int num2 = generateRandomNumber(1, 99);
      char op = generateRandomOperator(choice);
      double correctAnswer = performOperation(num1, num2, op);
      double userAnswer;

      for(int attempt = 1; attempt <= 2; attempt++) {
        displayQuestion(num1, num2, op, i, numQuestions);
        writeQuestion(num1, num2, op, i, numQuestions, reportFile);        
        cout << "Attempt #" << attempt << ": ";
        userAnswer = getUserAnswer();
        reportFile << "Attempt #" << attempt << ": " << userAnswer << endl;
        if(userAnswer == correctAnswer) {
          cout << "Congratulation!!!" << endl;
          reportFile << "Congratulation!!!" << endl;
          attempt == 1 ? correctAnswers++ : partialCorrectAnswers++;
          break;
        } else {
          cout << "Sorry, the answer is incorrect." << endl;
          reportFile << "Sorry, the answer is incorrect." << endl;
          if(attempt == 2) {
            cout << "The correct answer was: " << correctAnswer << endl;
            reportFile << "The correct answer was: " << correctAnswer << endl;
          }
        }
      }
      totalQuestions++;
    }

    displaySummary(correctAnswers, partialCorrectAnswers, totalQuestions);
    writeSummary(correctAnswers, partialCorrectAnswers, totalQuestions, reportFile);

    cout << "\nDo you want to run the program again? (yes/no): ";
    string input = getUserInput();
    if (input == "yes") {
      // Reset counts for the next run
      totalQuestions = 0;
      correctAnswers = 0;
      partialCorrectAnswers = 0;
      continue;
    } 
    
    if(input == "no") {
      cout << "Thank you for using Math Tutor! Goodbye!" << endl;
      reportFile << "Thank you for using Math Tutor! Goodbye!" << endl;
      break;
    }
  }

  reportFile.close();
  return 0;
}
