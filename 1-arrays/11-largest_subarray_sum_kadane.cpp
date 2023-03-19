// KADANE'S ALGORITHM O(n)
#include <bits/stdc++.h>
using namespace std;

void largestSubarraySum(int arr[], int n)
{
  int max_sum = INT_MIN;
  int curr_sum = 0;

  for (int i = 0; i < n; i++)
  {
    curr_sum += arr[i];
    if (curr_sum < 0)
    {
      curr_sum = 0;
    }
    max_sum = max(max_sum, curr_sum);
  }
  cout << "Maximum Sum: " << max_sum << endl;
}

int main()
{
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  largestSubarraySum(arr, n);
}