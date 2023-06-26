#include <iostream>
#include "stackV.h"
using namespace std;

// INSERT AT BOTTOM OF STACK
void insertAtBottom(Stack<int> &s, int data)
{
  if (s.empty())
  {
    s.push(data);
    return;
  }
  int temp = s.top();
  s.pop();
  insertAtBottom(s, data);
  s.push(temp);
}

// REVERSE THE STACK
void reverse(Stack<int> &s)
{
  if (s.empty())
    return;

  int t = s.top();
  s.pop();
  reverse(s);
  insertAtBottom(s, t);
}

int main()
{
  Stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  // s.push(5);
  // insertAtBottom(s, 5);
  reverse(s);

  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }
}