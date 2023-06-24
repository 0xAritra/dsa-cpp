#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

void fillArray(int *arr, int n, int i, int val)
{
  // base
  if (i == n)
  {
    printArray(arr, n);
    return;
  }
  // rec
  arr[i] = val;
  fillArray(arr, n, i + 1, val + 1);
  // backtracking!
  arr[i] *= -1; // OR
  // arr[i] = val * -1;
}

int main()
{
  int arr[100] = {0};
  int n;
  cin >> n;
  int val = 1;
  int i = 0;
  fillArray(arr, n, i, val);
  printArray(arr, n);
  return 0;
}