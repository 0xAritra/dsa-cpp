#include <iostream>
#include <vector>
using namespace std;
// BOTTOM-UP
int wines(const vector<int> &prices)
{
  int n = prices.size();
  int dp[n][n] = {0};

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        dp[i][j] = n * prices[i];
      }
      else if (i < j)
      {
        int yr = n - (j - i);
        int pick_left = yr * prices[i] + dp[i + 1][j];
        int pick_right = yr * prices[j] + dp[i][j - 1];

        dp[i][j] = max(pick_left, pick_right);
      }
    }
  }

  // PRINT DP MATRIX
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << dp[i][j] << '\t';
    }
    cout << endl;
  }

  return dp[0][n - 1];
}

int main()
{
  vector<int> v = {2, 3, 5, 1, 4};
  cout << wines(v) << endl;
}