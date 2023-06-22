

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  string header = "This program creates a nicely formatted payroll table";
  string projectName = "OutputFormatter(Payroll)";
  string programmer = "Gil D.";
  string hoursWorkedPhrase = "Hours worked Employee #";
  string hoursWorkedDisclaimer = " [Only whole hours will be credited]: ";
  string hourlyPayRatePhrase = "Hourly pay rate for Employee #";
  string hourlyPayRateDisclaimer = " [Not necessarily whole dollars]: ";
  
  int hoursWorked1, hoursWorked2, hoursWorked3, hoursWorked4, hoursWorked5;
  double hourlyPayRate1, hourlyPayRate2, hourlyPayRate3, hourlyPayRate4, hourlyPayRate5;
  double totalPay1, totalPay2, totalPay3, totalPay4, totalPay5;

  // Output header information
  cout << setw(60) << header << endl;
  cout << setw(24) << "Project: " << projectName << endl;
  cout << setw(30) << "Programmer(s): " << programmer << endl;
  cout << endl;

  // Output phrases and get employees pay rate and hours worked 
  cout << hoursWorkedPhrase << "1" << hoursWorkedDisclaimer;
  cin >> hoursWorked1;
  cout << hourlyPayRatePhrase << "1" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate1;

  cout << hoursWorkedPhrase << "2" << hoursWorkedDisclaimer;
  cin >> hoursWorked2;
  cout << hourlyPayRatePhrase << "2" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate2;

  cout << hoursWorkedPhrase << "3" << hoursWorkedDisclaimer;
  cin >> hoursWorked3;
  cout << hourlyPayRatePhrase << "3" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate3;

  cout << hoursWorkedPhrase << "4" << hoursWorkedDisclaimer;
  cin >> hoursWorked4;
  cout << hourlyPayRatePhrase << "4" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate4;

  cout << hoursWorkedPhrase << "5" << hoursWorkedDisclaimer;
  cin >> hoursWorked5;
  cout << hourlyPayRatePhrase << "5" << hourlyPayRateDisclaimer;
  cin >> hourlyPayRate5;

  // Calculate total pay for each employee
  totalPay1 = hoursWorked1 * hourlyPayRate1;
  totalPay2 = hoursWorked2 * hourlyPayRate2;
  totalPay3 = hoursWorked3 * hourlyPayRate3;
  totalPay4 = hoursWorked4 * hourlyPayRate4;
  totalPay5 = hoursWorked5 * hourlyPayRate5;

  return 0;
}