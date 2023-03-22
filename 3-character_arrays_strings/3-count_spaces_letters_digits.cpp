#include <iostream>

using namespace std;

int main()
{

  char ch = cin.get();

  // counts
  int alphabets = 0;
  int spaces = 0;
  int digits = 0;

  while (ch != '\n')
  {
    if (ch >= '0' && ch <= '9') // '0' - '9' has ascii values
    {
      digits++;
    }
    else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
      alphabets++;
    }
    else if (ch == ' ' || ch == '\t')
    {
      spaces++;
    }
    ch = cin.get();
  }
  cout << "Alphabets: " << alphabets << " Spaces: " << spaces << " Digits: " << digits << endl;
  return 0;
}