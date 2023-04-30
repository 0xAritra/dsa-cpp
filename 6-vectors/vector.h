#include <iostream>
using namespace std;

template <typename T>
class Vector
{
  T *arr;
  int cs;
  int ms;

public:
  Vector(int max_size = 1)
  {
    cs = 0;
    ms = max_size;
    arr = new T[ms];
  }

  void push_back(const T d)
  {
    if (cs == ms)
    {
      T *oldArr = arr;
      // new 2x arr
      ms = ms * 2;
      arr = new T[ms];
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

  T front() const
  {
    return arr[0];
  }

  T back() const
  {
    return arr[cs - 1];
  }

  T at(int n) const
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
  T operator[](const int i) const // i is not being changed
  {
    return arr[i];
  }
};
