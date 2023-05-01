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

// void updateIthBit(int &n, int i, int v)
// {
//   if (v == 1)
//   {
//     setIthBit(n, i);
//   }
//   else if (v == 0)
//   {
//     clearIthBit(n, i);
//   }
// }

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

int main()
{
  int n, i, v;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter i: ";
  cin >> i;

  // cout << getIthBit(n, i) << endl;
  // setIthBit(n, i);
  // clearIthBit(n, i);

  // cin >> v;

  clearLastIBits(n, i);

  cout << n << endl;

  return 0;
}