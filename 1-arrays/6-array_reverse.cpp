#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{
  int s = 0, e = n - 1;
  while (s < e) // will run n/2 times
  {
    // swap(arr[s], arr[e]);
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;
    s++;
    e--;
  }
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int arr[] = {10, 3, 4, 1, 54, 21, 45};
  int n = sizeof(arr) / sizeof(int);
  printArray(arr, n);
  reverseArray(arr, n);
  printArray(arr, n);
  /*
  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;
  */
  return 0;
}