#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to display the project banner
void displayBanner() {
  cout << "*************************************" << endl;
  cout << "*        This is Math Tutor 2       *" << endl;
  cout << "*        Written by [Gil]           *" << endl;
  cout << "*************************************" << endl;
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
    if(!(cin >> choice) || choice != static_cast<int>(choice)) {
      cin.clear(); // Clear the error.
      cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
      cout << "Error: Please provide real numbers only.";
    } else if (choice < 1 || choice > 11) {
      cout << "Error: Invalid menu option. Please select a valid option." << endl;
    } else {
      break; // If input is valid it will exit the loop.
    }
  }

  return choice;
}

// Function to get the number of questions from the user
int getNumberOfQuestions() {
  int numberOfQuestions;

  while(true) {
    cout << "Enter number of questions on the quiz: ";
    cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
    cin.clear(); // Clear the error.

    if(!(cin >> numberOfQuestions) || numberOfQuestions != static_cast<int>(numberOfQuestions)) {
      cin.clear(); // Clear the error.
      cin.ignore(100, '\n'); // Clear the remaining characters in the buffer
      cout << "Error: Please provide real numbers only." << endl;
    } else if (numberOfQuestions < 1) {
      cout << "Error: Please enter positive integers only." << endl;
    } else {
      break; // If input is valid it will exit the loop.
    }
  }

  return numberOfQuestions;
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

// Function to display and validate user input for questions
bool askQuestion(int num1, int num2, char op) {
    double correctAnswer = performOperation(num1, num2, op);

    for (int attempt = 1; attempt <= 2; attempt++) {
        int userAnswer;
        cout << setw(2) << num1 << " " << op << " " << setw(2) << num2 << " = ";
        if (cin >> userAnswer) {
            if (userAnswer == correctAnswer) {
                cout << "Congratulations!" << endl;
                return true;
            } else {
                cout << "Sorry the answer is incorrect! ";
                if (attempt == 1) {
                    cout << "Please, enter your answer again:" << endl;
                } else {
                    cout << "The correct answer is: " << correctAnswer << endl;
                }
            }
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }

    return false;
}

// Function to save the quiz report to a file
void saveReport(int totalQuestions, int correctAnswers, int partialCorrectAnswers) {
    double score = (static_cast<double>(correctAnswers) + 0.5 * partialCorrectAnswers) / totalQuestions * 100.0;

    ofstream reportFile("Report.txt");
    if (reportFile.is_open()) {
        reportFile << "Quiz Report\n";
        reportFile << "-----------\n";
        reportFile << "Total Questions: " << totalQuestions << "\n";
        reportFile << "Correct Answers: " << correctAnswers << "\n";
        reportFile << "Partially Correct Answers: " << partialCorrectAnswers << "\n";
        reportFile << "Score: " << fixed << setprecision(2) << score << "%\n";
        reportFile.close();
    } else {
        cout << "Error: Unable to save report to file." << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int totalQuestions = 0;
    int correctAnswers = 0;
    int partialCorrectAnswers = 0;

    while (true) {
        displayBanner();
        int choice = getMenuChoice();

        if (choice == 11) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        int numQuestions = getNumberOfQuestions();

        for (int i = 1; i <= numQuestions; i++) {
            int num1 = generateRandomNumber(1, 99);
            int num2 = generateRandomNumber(1, 99);
            char op = generateRandomOperator(choice);

            cout << "Question " << i << ": ";
            if (askQuestion(num1, num2, op)) {
                correctAnswers++;
            } else {
                partialCorrectAnswers++;
            }
            totalQuestions++;
        }

        char runAgain;
        cout << "\nDo you want to run the program again? (y/n): ";
        if (cin >> runAgain && (runAgain == 'y' || runAgain == 'Y')) {
            continue;
        } else {
            break;
        }
    }

    saveReport(totalQuestions, correctAnswers, partialCorrectAnswers);

    return 0;
}
