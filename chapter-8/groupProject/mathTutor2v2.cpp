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
  cout << "*  Written by [Gil, Prajwol, Nam]   *" << endl;
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

  while (true) {
    cout << "Enter the number of questions you want to have in the quiz: ";
    if (cin >> numQuestions && numQuestions > 0) {
      break;
    } else {
      cout << "Invalid input. Please enter a positive integer value.\n";
      cin.clear();
      cin.ignore(100, '\n');
    }
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

// Function to display and validate user input for questions
bool askQuestion(int num1, int num2, char op, int questionNumber) {
  double correctAnswer = performOperation(num1, num2, op);

  cout << "\nQuestion " << questionNumber << " of 2\n";
  cout << "\n            " << num1 << "\n\n";
  cout << "      " << op << "     " << num2 << "\n";
  cout << "        ______\n";
  cout << "Your first try: ";

  for (int attempt = 1; attempt <= 2; attempt++) {
    int userAnswer;
    if (cin >> userAnswer) {
      if (userAnswer == correctAnswer) {
        cout << "Congratulation !!!" << endl;
        return true;
      } else {
        if (attempt == 1) {
          cout << "Sorry, the answer is incorrect." << endl;
          cout << "Please, enter your answer again: ";
        } else {
          cout << "Sorry, the answer is incorrect." << endl;
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
void saveReport(int totalQuestions, int correctAnswers, int partialCorrectAnswers, int choice) {
    double score = (static_cast<double>(correctAnswers) + 0.5 * partialCorrectAnswers) / totalQuestions * 100.0;

    ofstream reportFile("Report.txt");
    if (reportFile.is_open()) {
        reportFile << "*******************************************" << endl;
        reportFile << "This is Math Tutor 2" << endl;
        reportFile << "Written by [Gil, Prajwol, Nam]  " << endl;
        reportFile << "*******************************************" << endl;

        int questionNumber = 1;
        for (int i = 1; i <= totalQuestions; i++) {
            int num1 = generateRandomNumber(1, 99);
            int num2 = generateRandomNumber(1, 99);
            char op = generateRandomOperator(choice);

            reportFile << "\nQuestion " << questionNumber++ << " of " << totalQuestions << endl;
            reportFile << "\n            " << num1 << "\n\n";
            reportFile << "      " << op << "     " << num2 << "\n";
            reportFile << "        ______\n";
            reportFile << "Your first try: ";

            double correctAnswer = performOperation(num1, num2, op);
            int userAnswer;
            if (cin >> userAnswer) {
                if (userAnswer == correctAnswer) {
                    reportFile << userAnswer << endl;
                    reportFile << "Congratulation !!!" << endl;
                } else {
                    reportFile << userAnswer << endl;
                    reportFile << "Sorry, the answer is incorrect." << endl;
                    reportFile << "Please, enter your answer again: " << endl;
                    if (cin >> userAnswer && userAnswer == correctAnswer) {
                        reportFile << "Your second try: " << userAnswer << endl;
                        reportFile << "Congratulation !!!" << endl;
                    }
                }
            } else {
                reportFile << "Invalid input. Please enter a number." << endl;
            }
        }

        reportFile << "\n*******************************************" << endl;
        reportFile << "\tYou got " << correctAnswers << " correct answers" << endl;
        reportFile << "\tand " << partialCorrectAnswers << " partially correct answers" << endl;
        reportFile << "\tout of " << totalQuestions << " questions asked." << endl;
        reportFile << "\tYou scored: " << fixed << setprecision(2) << score << "%" << endl;
        reportFile << "*******************************************" << endl;

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
  int choice; // Declare choice here

  while (true) {
    displayBanner();
    choice = getMenuChoice(); // Assign choice here

    if (choice == 11) {
      cout << "Exiting the program. Goodbye!" << endl;
      break;
    }

    int numQuestions = getNumberOfQuestions();

    for (int i = 1; i <= numQuestions; i++) {
      int num1 = generateRandomNumber(1, 99);
      int num2 = generateRandomNumber(1, 99);
      char op = generateRandomOperator(choice);

      if (askQuestion(num1, num2, op, i)) {
        correctAnswers++;
      } else {
        partialCorrectAnswers++;
      }
      totalQuestions++;
    }

    char runAgain;
    cout << "\n*******************************************";
    cout << "\n\tYou got " << correctAnswers << " correct answers";
    cout << "\n\tand " << partialCorrectAnswers << " partially correct answers";
    cout << "\n\tout of " << totalQuestions << " questions asked.";
    double score = (static_cast<double>(correctAnswers) + 0.5 * partialCorrectAnswers) / totalQuestions * 100.0;
    cout << "\n\tYou scored: " << fixed << setprecision(2) << score << "%" << endl;
    cout << "*******************************************\n";

    cout << "\nDo you want to run the program again? (y/n): ";
    string input;
    if (getline(cin, input)) {
      if (input.length() > 0 && (input[0] == 'y' || input[0] == 'Y')) {
        // Reset counts for the next run
        totalQuestions = 0;
        correctAnswers = 0;
        partialCorrectAnswers = 0;
        continue;
      } else {
        break;
      }
    } else {
      cout << "Invalid input. Exiting the program. Goodbye!" << endl;
      break;
    }
  }

  saveReport(totalQuestions, correctAnswers, partialCorrectAnswers, choice);

  return 0;
}