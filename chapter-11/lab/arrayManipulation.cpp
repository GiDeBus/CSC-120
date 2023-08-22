/* 
  Programmer: Gil Del Busto
  Program: Array Manipulation Lab Module 11
  Description: This program calculates the average on elements in an array. 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// Function to return the average of an array.
double avg(int arr[], int length) {
  
  double accumulator = 0; // variable to sum all elements of array.
  // Loop to sum all elements.
  for(int i = 0; i < length; i++) {
    accumulator += arr[i];
  }

  // Return the average.
  return (accumulator / length);
}

int main() {
  int arr[] = {1,2,4,6,7,9}; // Instantiate array.
  int length = sizeof(arr) / sizeof(arr[0]); // Get array length.
  double average = avg(arr, length); // Save average in variable.
  cout << "The Average is: " << average; // Return average.
}