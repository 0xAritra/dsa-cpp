#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string s; // dynamic vector
  string s1 = "hello world";
  string s2("hello world");

  // cout << s1 << endl;
  // cout << s2 << endl;

  getline(cin, s);
  // getline(cin, s, '#');
  for (char ch : s)
  {
    cout << ch << ", ";
  }
  cout << endl;
  //
  int n;
  cin >> n;
  cin.get();
  string temp;
  vector<string> sarr;
  while (n--)
  {
    getline(cin, temp);
    sarr.push_back(temp);
  }
  for (string s : sarr)
  {
    cout << s << ", ";
  }
  cout << endl;
  return 0;
}