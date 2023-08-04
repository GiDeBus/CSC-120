/* 
Programmer(s): Gil Del Busto
Program Name: Interest Calculator
Program Description: This program calculates the interest after x months
in a bank account. It also prompts the user for amount withdrawn or added.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// calculate the monthly interest 
double calculateMonthlyInterest(double rate) {
  float monthlyInterest = (rate / 12);
  return monthlyInterest;
}

// calculates monthly interest earned
double calculateMonthlyInterestEarned(double balance, double rate) {
  return balance * rate;
}

// gets proper input for annual interest rates
void getAnnualInterestRate(double& interestRate) {
  cout << "Input the annual interest rate (in decimal. Ex. .30): ";
  while(true) {
    // if input is correct it breaks.
    if(cin >> interestRate && interestRate >= 0) {
      break;
      // if not it gives an error message and reprompts
    } else {
      cout << "Invalid Input. Please enter a valid positive float" << endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
}

// gets proper input for account running balance
void getAccountRunningBalance(double& runningBalance) {
  cout << "Input account starting balance: ";
  while(true) {
    // if input is correct it breaks.
    if(cin >> runningBalance && runningBalance >= 0) {
      break;
    // if not it gives an error message and reprompts
    } else {
      cout << "Invalid Input. Please enter a valid positive float" << endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
}

// gets proper input for months since account opening.
void getMonthsPassed(int& months) {
  cout << "Input how many months have passed since account opening: ";
  while(true) {
    // if input is correct it breaks.
    if(cin >> months && months >=0) {
      break;
    // if not it gives an error message and reprompts
    } else {
      cout << "Invalid Input. Please enter a valid positive integer" << endl;
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
}

// gets proper input for monthly deposits
void getMonthlyDeposits(double& deposits) {
  cout << "Enter amount deposited to account during the month (Enter 0 if none): ";
  while(true) {
    // if input is correct it breaks.
    if(cin >> deposits && deposits >= 0) {
      break;
    // if not it gives an error message and reprompts
    } else {
      cout << "Invalid Input. Enter a valid positive float: ";
      cin.clear();
      cin.ignore(100,'\n');
    }
  }
}

// gets proper input for the monthly withdrawals
void getMonthlyWithdrawals(double& withdrawals) {
  cout << "Enter amount withdrawn from the account during the month (Enter 0 if none): ";
  while(true) {
    // if input is correct it breaks.
    if(cin >> withdrawals && withdrawals >= 0) {
      break;
    // if not it gives an error message and reprompts
    } else {
      cout << "Invalid Input. Enter valid positive float: ";
      cin.clear();
      cin.ignore(100, '\n');
    }
  }
}

// Reading and displaying transactions from file
void readTransactionsFile() {

  // Gives error message if file does not exist or is not valid/
  ifstream inFile("transactions.txt");
  if (!inFile) {
    cerr << "Error opening file 'transactions.txt'" << endl;
  }

  string line;
  cout << "Transactions:" << endl;

  // Reads file inputs
  while (getline(inFile, line)) {
    cout << line << endl;
  }
  // close file
  inFile.close();
}

// increments running balance
void incrementRunningBalance(double& runningBalance, double amount) {
  runningBalance += amount;
}

// decrements running balance
void decrementRunningBalance(double& runningBalance, double amount) {
  runningBalance -= amount;
}

// increments total interest
void incrementTotalInterestEarned(double& totalInterestEarned, double amount) {
  totalInterestEarned += amount;
}

// increments total withdrawals
void incrementTotalWithdrawals(double& totalWithdrawals, double amount) {
  totalWithdrawals += amount;
}

// increments total deposits
void incrementTotalDeposits(double& totalDeposits, double amount) {
  totalDeposits += amount;
}


int main() {
  double interestRate, runningBalance;
  int months;
  double totalInterestEarned = 0;
  double totalDeposits = 0;
  double totalWithdrawals = 0;

  // File stream for saving transactions
  ofstream outFile("transactions.txt");
  if (!outFile) {
    cerr << "Error opening file 'transactions.txt'" << endl;
    return 1;
  }

  getAnnualInterestRate(interestRate);
  getAccountRunningBalance(runningBalance);
  getMonthsPassed(months);

  for(int i = 0; i < months; i++) {
    double deposits;
    double withdrawals;

    getMonthlyDeposits(deposits);
    incrementRunningBalance(runningBalance, deposits);
    incrementTotalDeposits(totalDeposits, deposits);
    getMonthlyWithdrawals(withdrawals);
    decrementRunningBalance(runningBalance, withdrawals);
    incrementTotalWithdrawals(totalWithdrawals, withdrawals);

    // Break if account fell below 0 to prevent negative interest.
    if(runningBalance < 0) {
      outFile << "Account closed. Balance fell below 0" << endl;
      cout << "Account closed. Balance fell below 0" << endl;
      break;
    }

    double monthlyInterestRate = calculateMonthlyInterest(interestRate);
    double monthlyInterestEarned = calculateMonthlyInterestEarned(runningBalance, monthlyInterestRate);
    incrementRunningBalance(runningBalance, monthlyInterestEarned);
    incrementTotalInterestEarned(totalInterestEarned, monthlyInterestEarned);

    // Save monthly transactions to file
    outFile << "Month " << (i + 1) << ": Deposits: " << deposits << ", Withdrawals: " << withdrawals << ", Monthly Interest Earned: " << monthlyInterestEarned << endl;
    outFile << "Running Balance: " << runningBalance << endl;

  }

  // write total amounts to txt file.
  outFile << "Total Deposits: " << totalDeposits << endl;
  outFile << "Total Withdrawals: " << totalWithdrawals << endl;
  outFile << "Total Interest Earned: " << totalInterestEarned << endl;
  outFile << "Ending Balance: " << runningBalance << endl;
  // close file.
  outFile.close();


  // Reading and displaying transactions from file
  readTransactionsFile();
  return 0;
}
