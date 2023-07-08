#include <iostream>
#include <vector>
using namespace std;

// TOP-DOWN DP
int knapsack(vector<int> wts, vector<int> prices, int N, int W, int **dp)
{
  // TODO
}
/*
  INPUT:
    n: num of elements in wts, prices
    w: max weight
    wts[]: vector of weights
    prices[]: vector of prices

*/

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

  int **dp = new int *[n];
  for (int i = 0; i < n; i++)
  {
    dp[i] = new int[n]{0};
  }

  cout << knapsack(wts, prices, n, w, dp) << endl;
}