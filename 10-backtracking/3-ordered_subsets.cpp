#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
  if (a.length() == b.length())
  {
    return a < b;
  }
  return a.length() < b.length();
}

void findSubsets(char *input, char output[], int i, int j, vector<string> &sol)
{
  if (input[i] == '\0')
  {
    output[j] = '\0';
    string temp(output);
    sol.push_back(temp);
    return;
  }

  // include
  output[j] = input[i];
  findSubsets(input, output, i + 1, j + 1, sol);

  // not include
  findSubsets(input, output, i + 1, j, sol);
}

int main()
{
  char input[100], output[100];
  cin >> input;
  vector<string> sol;
  findSubsets(input, output, 0, 0, sol);
  sort(sol.begin(), sol.end(), compare);

  for (string x : sol)
  {
    if (x == "\0")
      cout << "NULL";
    cout << x << endl;
  }
  return 0;
}