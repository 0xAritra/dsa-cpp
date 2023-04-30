#include <iostream>
using namespace std;

class Vector
{
  int *arr;
  int cs;
  int ms;

public:
  Vector(int max_size = 1)
  {
    cs = 0;
    ms = max_size;
    arr = new int[ms];
  }

  void push_back(const int d)
  {
    if (cs == ms)
    {
      int *oldArr = arr;
      // new 2x arr
      ms = ms * 2;
      arr = new int[ms];
      // copy
      for (int i = 0; i < cs; i++)
      {
        arr[i] = oldArr[i];
      }
      // del old arr
      delete[] oldArr;
    }
    arr[cs] = d;
    cs++;
  }

  void pop_back()
  {
    if (cs >= 0)
      cs--;
  }

  bool isEmpty() const // not changing data members
  {
    return cs == 0;
  }

  int front() const
  {
    return arr[0];
  }

  int back() const
  {
    return arr[cs - 1];
  }

  int at(int n) const
  {
    return arr[n];
  }

  int size() const
  {
    return cs;
  }

  int capacity() const
  {
    return ms;
  }

  // operator overloading
  int operator[](const int i) const // i is not being changed
  {
    return arr[i];
  }
};

int main()
{
  Vector v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.pop_back();
  v.push_back(6);

  cout << v.front() << " " << v.back() << " " << v.at(1) << endl;
  cout << v.size() << " " << v.capacity() << endl;

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  return 0;
}