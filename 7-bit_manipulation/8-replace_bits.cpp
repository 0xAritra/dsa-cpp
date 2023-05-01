#include <iostream>
using namespace std;

// Q: Replace bits of n in range i-j with m

void clearBitsInRange(int &n, int i, int j)
{
  int a = (~0) << (j + 1);
  int b = (1 << i) - 1; // (2 ** i) - 1
  int mask = a | b;
  n = n & mask;
}

void replaceBits(int &n, int i, int j, int m)
{
  clearBitsInRange(n, i, j);
  int mask = m << i;
  n = n | mask;
}

int main()
{
  int n, i, j, m;
  cin >> n >> i >> j >> m;
  replaceBits(n, i, j, m);
  cout << n << endl;
  return 0;
}