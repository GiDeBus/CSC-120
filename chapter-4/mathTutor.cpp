/* This program behaves like a simple calculator. It accepts basic unary operators
such as -, + , *, / and %. It also has user input validation. */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  string ProgramHeader = "Description: Simple calculator";
  string projectName = "Calculator";
  string programmer = "Gil";

  double firstOperand, secondOperand;
  char operatorSymbol;

  cout << endl;
  cout << setw(40) << ProgramHeader << endl;
  cout << setw(19) << "Project: " << projectName << endl;
  cout << setw(25) << "Programmer(s): " << programmer << endl;

  cout << endl;
  cout << setw(40) << "************ Menu ************" << endl;
  cout << endl;
  cout << setw(36) << "Operators: + - / * % " << endl;
  cout << endl;
  cout << setw(40) << "******************************" << endl;
  cout << endl;

  cout << setw(34) << "Enter the first operand:" << endl;
  cout << endl;
  cin >> firstOperand;

  cout << setw(35) << "Enter the second operand:" << endl;
  cout << endl;
  cin >> secondOperand;

  cout << setw(40) << "Select and operator from the menu above:" << endl;
  cout << endl;
  cin >> operatorSymbol;

  cout << "SOLUTION:" << endl;
  cout << endl;

  return 0;
}