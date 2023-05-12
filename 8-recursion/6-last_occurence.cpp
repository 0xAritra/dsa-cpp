#include <iostream>
using namespace std;

int lastOcc(int arr[], int n, int key)
{
  if (n == 0)
  {
    return -1;
  }
  // my imp
  int idx = lastOcc(arr + 1, n - 1, key);
  if (idx >= 0)
    return idx + 1;
  if (arr[0] == key)
    return 0;
  return -1;
}

int main()
{

  int arr[] = {1, 4, 6, 3, 2, 0, 2, 6};
  int n = sizeof(arr) / sizeof(int);

  int key;
  cin >> key;

  cout << lastOcc(arr, n, key) << endl;

  return 0;
}