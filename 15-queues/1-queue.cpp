#include <iostream>
#include "queueLL.h"
using namespace std;

int main()
{
  // Queue q(3);
  Queue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.pop();
  q.pop();
  q.push(5);

  while (!q.empty())
  {
    cout << q.front() << endl;
    q.pop();
  }

  return 0;
}