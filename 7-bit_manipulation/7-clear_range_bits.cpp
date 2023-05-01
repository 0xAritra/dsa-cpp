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

//
void clearIthBit(int &n, int i)
{
  int mask = ~(1 << i);
  n = n & mask;
}

//
void updateIthBit(int &n, int i, int v)
{
  clearIthBit(n, i);
  int mask = v << i;
  n = n | mask;
}

void clearLastIBits(int &n, int i)
{
  int mask = -1 << i;
  n = n & mask;
}

void clearBitsInRange(int &n, int i, int j)
{
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1; // (2 ** i) - 1
  int mask = a | b;
  n = n & mask;
}

int main()
{
  int n, i, j;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter i: ";
  cin >> i;
  cout << "Enter j: ";
  cin >> j;

  // cout << getIthBit(n, i) << endl;
  // setIthBit(n, i);
  // clearIthBit(n, i);

  // cin >> v;
  // clearLastIBits(n, i);

  clearBitsInRange(n, i, j);

  cout << n << endl;

  return 0;
}