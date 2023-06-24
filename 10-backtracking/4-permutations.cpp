// my implementation
#include <iostream>
using namespace std;

void permutations(string str, int s, int e)
{
  if (s == e)
  {
    cout << str << endl;
    return;
  }
  int i = s;
  while (i <= e)
  {
    swap(str[s], str[i]);
    permutations(str, s + 1, e);
    swap(str[s], str[i]);
    i++;
  }
}

int main()
{
  char input[100];
  cin >> input;
  string s(input);
  permutations(s, 0, s.length() - 1);

  return 0;
}