/* 
  Programmer: Gil Del Busto
  Program: Lottery Winners
  Description: This program performs a linear search to see if 
    an individual won the lottery based on winning numbers. 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// Checks if a number is greater than 0.
bool isPositive(int input) {
  return static_cast<int>(input) > 0;
}

// Checks if input is an integer.
bool isInteger(int input) {
  return static_cast<int>(input) == input;
}

// Checks if number is the right length and contains no zeroes. Zeroes are not positive numbers.
bool isWithinRange(int input) {
  return (input < 99999 && input >= 11111);
}

// Checks if the number inputted is valid.
bool isValid(int input) {
  return (isInteger(input) && isPositive(input) && isWithinRange(input));
}

// Performs a linear search to match each number with the winning combination and returns true or false.
bool isWinner(int combinations[], int winningNumber, int size) {
  bool won = false;
  for(int i = 0; i < size; i++) {
    if(combinations[i] == winningNumber) {
      won = true;
      return won;
    }
  }
  return false;
}

// Validates input from user for winning numbers.
int getWinningNumbers() {
  int winningNumber; 
  cout << "Enter this week's winning 5-digit number: ";
  while(true) {
    if(cin >> winningNumber && isValid(winningNumber)) {
      break;
    }
    cout << "Please enter a valid 5 digit positive number with no 0" << endl;
    cin.clear();
    cin.ignore(100, '\n');
  }

  return winningNumber;
}

// Displays winning or losing message depending on boolean value.
void displayMessage(bool isWinner) {
  if(isWinner) {
    cout << "Congratulations You are a Winner!!!" << endl;
  } else {
    cout << "No matches. Better luck next time." << endl;
  }
}

int main() {
  int luckyCombinations[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
  const int LOTTERY_NUMBER_SIZE = 5;
  const int NUMBER_OF_LUCKY_TICKETS = 10;
  int winningNumber = getWinningNumbers();
  bool check = isWinner(luckyCombinations, winningNumber, NUMBER_OF_LUCKY_TICKETS);
  displayMessage(check);
}

