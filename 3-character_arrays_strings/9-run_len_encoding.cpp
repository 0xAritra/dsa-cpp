#include <iostream>
using namespace std;

string compressString(string s)
{
  int n = s.length();
  string res;
  for (int i = 0; i < n; i++)
  {
    int count = 1;
    while (i < n - 1 && s[i] == s[i + 1])
    {
      count++;
      i++;
    }
    res += s[i];
    res += to_string(count);
  }

  if (res.length() >= s.length())
  {
    return s;
  }
  return res;
}

int main()
{
  cout << compressString("aaaabbbbccccccccc") << endl;
  cout << compressString("abcd") << endl;

  return 0;
}