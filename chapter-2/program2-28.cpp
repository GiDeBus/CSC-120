// a program that prompts user for name and number of brownies then outputs their name
// and a calculation of carbs based on the users input. 
// Note: user input is not validated!

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string chocolateBrowniePhrase = "Ghirardelli Dark Chocolate Brownie";
    
    int caloriesPerBrownie = 140;
    float gramsOfFatPerBrownie = 3.5;
    float gramsOfCarbsPerBrownie = 25;

    // prompt user for name

    string myName;
    cout << "What is your name?" << endl;
    cin >> myName;
    cout << "\n";

    // prompt user for number of brownies

    int numberOfBrownies;
    cout << "How many brownies do you want?" << endl;
    cin >> numberOfBrownies;
    cout << "\n";

    // perform calculations on number of brownies
    // Note: not all variables are used due to assignment requirements
 
    int caloriesInThreeBrownies = numberOfBrownies * caloriesPerBrownie; 
    float gramsOfFatInThreeBrownies = numberOfBrownies * gramsOfFatPerBrownie;
    float gramsOfCarbsInThreeBrownies = numberOfBrownies * gramsOfCarbsPerBrownie;

    // output nutritional facts and message

    cout << "Hi " + myName << endl;
    cout << "A " << chocolateBrowniePhrase << " contains:" << endl;
    cout << caloriesPerBrownie << " calories" << endl;
    cout << gramsOfFatPerBrownie << " grams of Fat" << endl;
    cout << gramsOfCarbsPerBrownie << " grams of Carbs" << endl;
    cout << "\n";
    cout << "There is also " << gramsOfCarbsInThreeBrownies << " grams of Carbs in " << numberOfBrownies << " brownies!";

    return 0;
}