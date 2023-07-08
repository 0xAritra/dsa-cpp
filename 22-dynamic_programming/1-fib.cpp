#include <iostream>
using namespace std;

// top-down dp (recursive)
int fib(int n, int *dp)
{
  if (n == 0 or n == 1)
    return n;

  if (dp[n] != 0)
    return dp[n];

  dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
  return dp[n];
}

// bottom-up dp (iterative)
int fibonacci(int n, int *dp)
{
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  int dp[n + 1] = {0};
  dp[1] = 1;

  // top-down
  cout << fib(n, dp) << endl;

  // bottom-up
  cout << fibonacci(n, dp) << endl;

  for (int i = 0; i <= n; i++)
    cout << dp[i] << " ";
  cout << endl;
}