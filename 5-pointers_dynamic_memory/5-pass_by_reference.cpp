#include <iostream>
using namespace std;

void applyTax(int &income) // pass by reference
{
  float tax = 0.1;
  income = (1 - tax) * income;
}

int main()
{

  int income;
  cin >> income;

  applyTax(income);

  cout << income << endl;

  return 0;
}