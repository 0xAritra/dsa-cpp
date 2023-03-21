#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n)
{
  for (int pos = 0; pos < n - 1; pos++) // 0 to n - 2, coz last element will become the largest
  {
    int min_pos = pos;
    for (int curr = pos; curr < n; curr++)
    {
      if (arr[curr] < arr[min_pos])
      {
        min_pos = curr;
      }
    }
    swap(arr[pos], arr[min_pos]);
  }
}

int main()
{
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  selection_sort(arr, n);

  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
