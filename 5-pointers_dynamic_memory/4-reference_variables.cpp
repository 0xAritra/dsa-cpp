// pass by reference - 1. pointers 2. reference variables

#include <iostream>
using namespace std;

int main()
{
  int x = 10;
  int &y = x; // x, y are the same bucket/var

  y++;
  x++;

  cout << y << endl;
  cout << x << endl;

  cout << &y << endl;
  cout << &x << endl;

  return 0;
}