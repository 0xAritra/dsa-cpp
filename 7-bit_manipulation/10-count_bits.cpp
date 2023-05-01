// count set bits
#include <iostream>
using namespace std;

int countBits(int n)
{
  int count = 0;
  while (n > 0)
  {
    int last_bit = n & 1;
    count += last_bit;
    n = n >> 1;
  }
  return count;
}

int main()
{
  int n;
  cin >> n;

  cout << countBits(n) << endl;
  return 0;
}