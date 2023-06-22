/* This program assists in the calculation of total pay for 5 different employees
  and displays a formatted table with the information inputted by the user
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  // Phrases that will be used to output information
  string ProgramHeader = "This program creates a nicely formatted payroll table";
  string projectName = "OutputFormatter(Payroll)";
  string programmer = "Gil D.";
  string hoursWorkedPhrase = "Hours worked Employee #";
  string hoursWorkedDisclaimer = " [Only whole hours will be credited]: ";
  string hourlyPayRatePhrase = "Hourly pay rate for Employee #";
  string hourlyPayRateDisclaimer = " [Not necessarily whole dollars]: ";
  
  int hoursWorked1, hoursWorked2, hoursWorked3, hoursWorked4, hoursWorked5;
  int totalHours;
  
  double hourlyPayRate1, hourlyPayRate2, hourlyPayRate3, hourlyPayRate4, hourlyPayRate5;
  double salary1, salary2, salary3, salary4, salary5;
  double totalPay;

  // Output application header information
  cout << setw(60) << ProgramHeader << endl;
  cout << setw(24) << "Project: " << projectName << endl;
  cout << setw(30) << "Programmer(s): " << programmer << endl;
  cout << endl;

  // Output phrases and get employees pay rate and hours worked 
  cout << hoursWorkedPhrase << "1" << hoursWorkedDisclaimer;
  cin >> hoursWorked1;

  cout << hourlyPayRatePhrase << "1" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate1;
  cout << endl;

  cout << hoursWorkedPhrase << "2" << hoursWorkedDisclaimer;
  cin >> hoursWorked2;

  cout << hourlyPayRatePhrase << "2" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate2;
  cout << endl;

  cout << hoursWorkedPhrase << "3" << hoursWorkedDisclaimer;
  cin >> hoursWorked3;

  cout << hourlyPayRatePhrase << "3" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate3;
  cout << endl;

  cout << hoursWorkedPhrase << "4" << hoursWorkedDisclaimer;
  cin >> hoursWorked4;

  cout << hourlyPayRatePhrase << "4" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate4;
  cout << endl;

  cout << hoursWorkedPhrase << "5" << hoursWorkedDisclaimer;
  cin >> hoursWorked5;

  cout << hourlyPayRatePhrase << "5" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate5;
  cin.ignore();
  cout << endl;
  cout << endl;

  // Calculate salary for each employee
  salary1 = hoursWorked1 * hourlyPayRate1;
  salary2 = hoursWorked2 * hourlyPayRate2;
  salary3 = hoursWorked3 * hourlyPayRate3;
  salary4 = hoursWorked4 * hourlyPayRate4;
  salary5 = hoursWorked5 * hourlyPayRate5;

  // Calculate totals
  totalHours = hoursWorked1 + hoursWorked2 + hoursWorked3 + hoursWorked4 + hoursWorked5; 
  totalPay = salary1 + salary2 + salary3 + salary4 + salary5;

  // Output formatted table with employees salary information
  cout << fixed << showpoint << setprecision(2);
  cout << "Employee#" << setw(10) << "Hours" << setw(10) << "Pay Rate" << setw(16)  << "Total Pay" << endl;
  cout << "==============================================" << endl;
  cout << setw(3) << "1" << setw(14) << static_cast<double>(hoursWorked1) << setw(10) << hourlyPayRate1 << setw(18) << salary1 << endl;
  cout << setw(3) << "2" << setw(14) << static_cast<double>(hoursWorked2) << setw(10) << hourlyPayRate2 << setw(18) << salary2 << endl;
  cout << setw(3) << "3" << setw(14) << static_cast<double>(hoursWorked3) << setw(10) << hourlyPayRate3 << setw(18) << salary3 << endl;
  cout << setw(3) << "4" << setw(14) << static_cast<double>(hoursWorked4) << setw(10) << hourlyPayRate4 << setw(18) << salary4 << endl;
  cout << setw(3) << "5" << setw(14) << static_cast<double>(hoursWorked5) << setw(10) << hourlyPayRate5 << setw(18) << salary5 << endl;
  cout << "==============================================" << endl;
  cout << "Total" << setw(12) << static_cast<double>(totalHours) << setw(28) << totalPay << endl;
  cout << "==============================================" << endl;
  cout << endl;

  cout << "Press any key to continue . . . ";
  cin.get();

  return 0;
}