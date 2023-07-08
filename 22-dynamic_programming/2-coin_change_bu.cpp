#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// BOTTOM-UP DP
int coin_change(vector<int> denoms, int m)
{
  int dp[m + 1] = {0};

  for (int i = 1; i <= m; i++)
  {
    dp[i] = INT_MAX;
    for (int d : denoms)
    {
      if (i - d >= 0 && dp[i - d] != INT_MAX)
      {
        dp[i] = min(dp[i], dp[i - d] + 1);
      }
    }
    // dp[i] = res + 1;
  }

  return dp[m] == INT_MAX ? -1 : dp[m];
}

/*
  INPUT:
  n: num of denoms
  denoms[n]: vector of demons
  m: target change
*/
int main()
{
  int n;
  cin >> n;
  vector<int> denoms;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    denoms.push_back(x);
  }

  int m;
  cin >> m;

  cout << coin_change(denoms, m) << endl;
}