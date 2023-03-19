// PREFIX SUM APPROACH O(n^2)
#include <bits/stdc++.h>
using namespace std;

void largestSubarraySum(int arr[], int n)
{
  int max_sum = INT_MIN;

  // PREFIX SUM
  int prefix[n]; // extra space!
  prefix[0] = arr[0];
  for (int i = 1; i < n; i++) // O(n)
  {
    prefix[i] = prefix[i - 1] + arr[i];
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++) // O(n ^ 2)
    {
      //
      int current_sum = i > 0 ? prefix[j] - prefix[i - 1] : prefix[j];
      max_sum = max(current_sum, max_sum);
    }
  }
  cout << "Maximum Sum: " << max_sum << endl;
}

int main()
{
  int arr[] = {-2, -3, -4, -1, -5, -12, -6, -1, -3};
  int n = sizeof(arr) / sizeof(int);

  largestSubarraySum(arr, n);
}