#include <iostream>
using namespace std;

int convertToBinary(int n)
{
  int res = 0;
  int i = 1;
  while (n > 0)
  {
    int lastBit = n & 1;
    res += i * lastBit;
    i *= 10;
    n = n >> 1;
  }
  return res;
}

int main()
{
  int n;
  cin >> n;
  cout << convertToBinary(n) << endl;
  return 0;
}