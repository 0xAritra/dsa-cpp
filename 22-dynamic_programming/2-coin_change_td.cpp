#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// TOP-DOWN DP
int coin_change(vector<int> denoms, int m, vector<int> &dp)
{
  if (m == 0)
    return 0;

  int res = INT_MAX;
  for (int i = 0; i < denoms.size(); i++)
  {
    if (m >= denoms[i])
    {
      if (dp[m] == -1)
        dp[m - denoms[i]] = coin_change(denoms, m - denoms[i], dp);
      res = min(res, dp[m - denoms[i]]);
    }
  }
  dp[m] = res + 1;
  return dp[m];
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

  vector<int> dp(m + 1, -1);
  dp[0] = 0;

  cout << coin_change(denoms, m, dp) << endl;

  // for (auto x : dp)
  // {
  //   cout << x << " ";
  // }
  // cout << endl;
}