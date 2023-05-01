#include <iostream>
using namespace std;

bool isPowerOf2(int n)
{
  return (n & (n - 1)) == 0 ? true : false;
}

int main()
{
  int n;
  cin >> n;
  cout << isPowerOf2(n) << endl;
  return 0;
}