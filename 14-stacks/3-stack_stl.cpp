#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<string> s;
  s.push("C++");
  s.push("OOPs");
  s.push("OS");

  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}