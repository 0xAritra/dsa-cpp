#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> wts, vector<int> prices, int N, int W)
{
  vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

  for (int n = 1; n <= N; n++)
  {
    for (int w = 1; w <= W; w++)
    {
      int inc = 0, exc = 0;

      if (wts[n - 1] <= w)
      {
        inc = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
      }
      exc = dp[n - 1][w];

      dp[n][w] = max(inc, exc);
    }
  }

  return dp[N][W];
}

// + implement better space complexity instead of O(N*W)

int main()
{
  int n, w;
  vector<int> wts;
  vector<int> prices;

  cin >> n >> w;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    wts.push_back(temp);
  }

  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    prices.push_back(temp);
  }

  cout << knapsack(wts, prices, n, w) << endl;
}