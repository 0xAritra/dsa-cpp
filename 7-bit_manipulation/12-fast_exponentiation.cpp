#include <iostream>
using namespace std;

int fastExp(int a, int n)
{
  int res = 1;
  while (n > 0)
  {
    int last_bit = n & 1;
    if (last_bit == 1)
      res = res * a;
    a = a * a;
    n = n >> 1;
  }
  return res;
}

int main()
{

  int a, n;
  cin >> a >> n;

  cout << fastExp(a, n) << endl;

  return 0;
}