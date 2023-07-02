/* This program behaves like a simple calculator. It accepts basic unary operators
such as -, + , *, / and %. It also has user input validation. */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  // Declare header output
  string ProgramHeader = "Description: Simple calculator";
  string projectName = "Calculator";
  string programmer = "Gil";

  // Define variables for the operands, and operator
  double firstOperand, secondOperand;
  char operatorSymbol;

  // Output header
  cout << endl;
  cout << setw(40) << ProgramHeader << endl;
  cout << setw(19) << "Project: " << projectName << endl;
  cout << setw(25) << "Programmer(s): " << programmer << endl;

  // Output operator menu
  cout << endl;
  cout << setw(40) << "************ Menu ************" << endl;
  cout << endl;
  cout << setw(36) << "Operators: + - / * % " << endl;
  cout << endl;
  cout << setw(40) << "******************************" << endl;
  cout << endl;

  cout  << setw(35) << "Enter the first operand: ";

  // Input validation.
  if(!(cin >> firstOperand)) // Program outputs an error message and returns if value != real number.
  {
    cout << endl;
    cout << "Error: Please provide real numbers only.";
    return 0;
  }
  cout << endl;

  cout  << setw(36) << "Enter the second operand: ";
  // Input validation.
  if(!(cin >> secondOperand))  // Program outputs an error message and returns if value != real number.
  {
    cout << endl;
    cout << "Error: Please provide real numbers only.";
    return 0;   
  }
  cout << endl;

  cout  << setw(51) << "Select and operator from the menu above: ";
  // Input validation for operator. Only the ones above are allowed. We compare the ASCII values.
  cin >> operatorSymbol;
  if (operatorSymbol != 45 && // ASCII value for -
    operatorSymbol != 43 && // ASCII value for +
    operatorSymbol != 42 && // ASCII value for *
    operatorSymbol != 47 && // ASCII value for /
    operatorSymbol != 37) // ASCII value for %
  {
    cout << endl;
    cout << "Error: Select only one of the operators from the menu above.";
    return 0;
  }
  cout << endl;

  // Output solution.
  cout  << setw(19) << "SOLUTION:" << endl;
  cout  << setw(29) << "-------------------" << endl;
  cout  << setw(12) << firstOperand << " " << operatorSymbol << " " << secondOperand << " = ";

  // Perform the selected operation

  if (operatorSymbol == '+')  // Addition
  {
    cout << (firstOperand + secondOperand);
  }

  if (operatorSymbol == '-') // Subtraction
  {
    cout << (firstOperand - secondOperand);
  }

  if (operatorSymbol == '*') // Multiplication
  {
    cout << (firstOperand * secondOperand);
  }

  if (operatorSymbol == '/') // Division
  {

    // Output error message if division by zero.
    if(secondOperand == 0)
    {
      cout << endl;
      cout << "Error: Division by zero is not allowed." << endl;
      return 0;

    } 
    cout << (firstOperand / secondOperand);
  }

  if (operatorSymbol == '%') // Modulo
  {

    // Output error message if modulo by zero.
    if(secondOperand == 0)
    {
      cout << endl;
      cout << "Error: Modulo by zero is not allowed." << endl;
      return 0;
    } 
    // Modulo cannot be performed on Doubles so values are converted to integers.
    // There is lose of precision but not mentioned in requirements.
    cout << (static_cast<int>(firstOperand) % static_cast<int>(secondOperand));
  }

  cout << endl;
  cout << endl;
  cout  << setw(29) << "-------------------" << endl;

  return 0;
}