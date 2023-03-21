// https://cplusplus.com/reference/vector/vector/
#include <iostream>
#include <vector>

using namespace std;

int main()
{

  vector<int> arr = {1, 3, 5, 6, 7, 15};

  vector<int> v(10, 5); // size: 10, initialized with all 5

  arr.pop_back();    // removes last element from arr
  arr.push_back(10); // pushes element to end of arr

  // size, capacity
  cout << "Size: " << arr.size() << " "
       << "Capacity: " << arr.capacity() << endl;

  // traversal
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}