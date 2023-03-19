#include <iostream>
using namespace std;

void printArray(int *arr, int size)
{
  cout << "printArray():" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << endl;
  }
  // arr[0] = -1; // as both main and printArray references same array in memory - the array changes
}

int main()
{

  int a[] = {1, 2, 3, 4};
  int n = sizeof(a) / sizeof(int);

  printArray(a, n);
  // printArray(a, n);

  // cout << "main():" << endl;
  // for (int i = 0; i < n; i++)
  // {
  //   cout << a[i] << endl;
  // }

  return 0;
}