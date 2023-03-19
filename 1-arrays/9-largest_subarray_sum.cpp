// BRUTE FORCE APPROACH O(n^3)
#include <bits/stdc++.h>
using namespace std;

void largestSubarraySum(int arr[], int n)
{
  int max_sum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int current_sum = 0;
      for (int k = i; k <= j; k++)
      {
        current_sum += arr[k];
      }
      /*
      if (current_sum > max_sum)
      {
        max_sum = current_sum;
      } */
      max_sum = max(current_sum, max_sum);
      // cout << "Sum: " << sum << endl;
    }
  }
  cout << "Maximum Sum: " << max_sum << endl;
}

int main()
{
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  largestSubarraySum(arr, n);
}