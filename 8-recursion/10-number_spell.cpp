#include <iostream>
using namespace std;

string numbersInLetters[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void numberSpell(int num)
{
  if (num == 0)
    return;
  int lastDigit = num % 10;
  numberSpell(num / 10);
  cout << numbersInLetters[lastDigit] << " ";
}

int main()
{
  int n;
  cin >> n;
  numberSpell(n);
  cout << endl;
  return 0;
}