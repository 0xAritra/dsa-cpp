#include <bits/stdc++.h>
using namespace std;

void printSubarrays(int arr[], int n)
{
  int max_sum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      for (int k = i; k <= j; k++)
      {
        cout << arr[k] << " ";
      }
      cout << endl;
    }
  }
}

int main()
{
  int arr[] = {10, 20, 20, 40, 50, 60};
  int n = sizeof(arr) / sizeof(int);

  printSubarrays(arr, n);
}