#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
  int arr[] = {10, 15, 20, 13, 6, 90};
  Heap h; // max heap
  // Heap h(10, false);

  for (int x : arr)
  {
    h.push(x);
  }

  while (!h.empty())
  {
    cout << h.top() << " ";
    h.pop();
  }
  cout << endl;
}