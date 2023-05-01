#include <iostream>
using namespace std;

int getIthBit(int n, int i)
{
  int mask = (1 << i);
  return (n & mask) >= 1 ? 1 : 0;
}

void setIthBit(int &n, int i)
{
  int mask = 1 << i;
  n = n | mask;
}

int main()
{
  int n, i;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter i: ";
  cin >> i;

  // cout << getIthBit(n, i) << endl;
  setIthBit(n, i);
  cout << n << endl;

  return 0;
}