#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int key)
{
  //
  if (n == 0)
    return -1;
  if (arr[0] == key)
    return 0;
  //
  int index = firstOcc(arr + 1, n - 1, key);
  if (index >= 0)
    return index + 1;
  return -1;
}

int main()
{
  int arr[] = {10, 8, 56, 9, 10, 5, 7};
  int n = sizeof(arr) / sizeof(int);
  int key = 7;
  cout << firstOcc(arr, n, key) << endl;

  return 0;
}