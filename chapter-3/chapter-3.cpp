

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
  string header = "This program creates a nicely formatted payroll table";
  string projectName = "OutputFormatter(Payroll)";
  string programmer = "Gil D.";

  cout << setw(60) << header << endl;
  cout << setw(24) << "Project: " << projectName << endl;
  cout << setw(30) << "Programmer(s): " << programmer << endl;

  return 0;
}