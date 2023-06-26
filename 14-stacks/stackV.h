#include <vector>
using namespace std;

template <typename T>
class Stack
{
  vector<T> v;

public:
  void push(int d)
  {
    v.push_back(d);
  }

  void pop()
  {
    v.pop_back();
  }

  bool empty()
  {
    return v.size() == 0;
  }

  T top()
  {
    int lastIdx = v.size() - 1;
    return v[lastIdx];
  }
};