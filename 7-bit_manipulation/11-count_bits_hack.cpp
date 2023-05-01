#include <iostream>
using namespace std;

int count_bits_hack(int n)
{
  int count = 0;
  while (n > 0)
  {
    n = (n & n - 1); // removes last set bit from n
    count++;
  }
  return count;
}

int main()
{
  int n;
  cin >> n;

  cout << count_bits_hack(n) << endl;

  return 0;
}