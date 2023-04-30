#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int key;
  vector<int> arr = {1, 2, 3, 4, 5, 6};
  cin >> key;
  vector<int>::iterator it = find(arr.begin(), arr.end(), key);
  if (it == arr.end())
  {
    cout << "Not Found!" << endl;
  }
  else
  {
    cout << it - arr.begin() << endl;
  }

  return 0;
}