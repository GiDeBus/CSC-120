// a program that prompts user for name and number of brownies then outputs their name
// and a calculation of carbs based on the users input. 
// Note: user input is not validated!

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // declare variables
    
    string myName = "Gilberto";
    string chocolateBrowniePhrase = "Ghirardelli Dark Chocolate Brownie";
    
    int caloriesPerBrownie = 140;
    float gramsOfFatPerBrownie = 3.5;
    float gramsOfCarbsPerBrownie = 25;
    int numberOfBrownies = 3;

    // perform calculations on number of brownies
     
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
    cout << "There is also " << gramsOfCarbsInThreeBrownies << " grams of Carbs" << endl;
    cout << gramsOfFatInThreeBrownies << " grams of Fat " << endl;
    cout << "For a total of " << caloriesInThreeBrownies << " calories in " << numberOfBrownies << " brownies!";

    return 0;
}