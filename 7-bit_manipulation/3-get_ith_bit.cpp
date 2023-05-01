#include <iostream>
using namespace std;

// int getIthBit(int n, int i)
// {
//   return (n >> i) & 1;
// }

// OR ?

int getIthBit(int n, int i)
{
  int mask = (1 << i);
  return (n & mask) >= 1 ? 1 : 0;
}

int main()
{
  int n, i;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter i: ";
  cin >> i;

  cout << getIthBit(n, i) << endl;

  return 0;
}