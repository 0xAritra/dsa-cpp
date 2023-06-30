#include <iostream>
#include <queue>

using namespace std;

class Compare
{
public:
  bool operator()(int x, int y)
  {
    return x > y;
  }
};

int main()
{
  int arr[] = {10, 15, 20, 13, 6, 90};
  // priority_queue<int> h; // max heap
  // priority_queue<int, vector<int>, greater<int> > h; // min heap w/ stl comparator (greater)
  priority_queue<int, vector<int>, Compare> h;

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