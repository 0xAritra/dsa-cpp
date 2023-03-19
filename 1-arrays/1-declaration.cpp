#include<iostream>
using namespace std;

int main() {

  // array of size 100 (indexes: 0 to 99)
  int a[100];

  int b[100] = {0}; // {0}: init list - initializes all elements with 0

  int c[100] = {1, 2, 3}; // {1, 2, 3}: init list - first three elements will be 1, 2, 3 - rest all elements will be 0

  int d[] = {1, 2, 3}; // array of size 3 - declaring size is optional if initialized

  string fruits[] = {"apple", "orange"}; // array of strings (strings themselves are char arrays - 2D array)

  return 0;
}