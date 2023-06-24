#include <iostream>
using namespace std;

int fact(int n)
{
  if (n == 1 or n == 0)
    return 1;
  return n * fact(n - 1);
}

int gridWays(int m, int n)
{
  return fact(m - 1 + n - 1) / (fact(m - 1) * fact(n - 1));
}

int main()
{
  int m, n;
  cin >> m >> n;
  cout << gridWays(m, n) << endl;
  return 0;
}