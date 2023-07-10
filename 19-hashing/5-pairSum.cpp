#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
  unordered_set<int> s;
  int arr[] = {1, 3, 5, 6, -1, -1, 0, 8, -2, -2, -2};
  // int arr[] = {1, 3, 5, 6, -1, 0, 8, -2};
  int n = sizeof(arr) / sizeof(int);
  int k = 6;

  for (int i = 0; i < n; i++)
  {
    if (s.find(k - arr[i]) != s.end())
    {
      cout << k - arr[i] << ", " << arr[i] << endl;
    }
    s.insert(arr[i]);
  }
}