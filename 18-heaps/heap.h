#include <vector>
using namespace std;

class Heap
{
  vector<int> v;
  bool isMinHeap;

  bool compare(int x, int y)
  {
    if (isMinHeap == false)
      return x < y;
    return x > y;
  }

  void heapify(int i)
  {
    int left = 2 * i;
    int right = 2 * i + 1;
    int minIdx = i;
    if (left < v.size() && compare(v[left], v[minIdx]))
    {
      minIdx = left;
    }
    if (right < v.size() && compare(v[right], v[minIdx]))
    {
      minIdx = right;
    }
    if (minIdx != i)
    {
      swap(v[i], v[minIdx]);
      heapify(minIdx);
    }
  }

public:
  Heap(int default_size = 10, bool isMinHeap = true) // is it a min heap or not?
  {
    this->isMinHeap = isMinHeap;
    v.reserve(default_size);
    v.push_back(-1);
  }

  // log N
  void push(int data)
  {
    v.push_back(data);

    int idx = v.size() - 1;
    int parent = idx / 2;

    while (idx > 1 && compare(v[idx], v[parent]))
    {
      swap(v[parent], v[idx]);
      idx = parent;
      parent = parent / 2;
    }
  }

  int top()
  {
    return v[1];
  }

  // log N
  void pop()
  {
    int lastIdx = v.size() - 1;
    swap(v[1], v[lastIdx]);
    v.pop_back();
    heapify(1);
  }

  bool empty()
  {
    return v.size() == 1;
  }
};