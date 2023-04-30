#include <iostream>
#include "vector.h"
using namespace std;

int main()
{
  Vector<int> v;
  Vector<char> v1;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  v.pop_back();
  v.push_back(6);

  v1.push_back('b');
  v1.push_back('a');

  cout << v.front() << " " << v.back() << " " << v.at(1) << endl;
  cout << v.size() << " " << v.capacity() << endl;

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < v1.size(); i++)
  {
    cout << v1[i] << " ";
  }
  cout << endl;

  return 0;
}