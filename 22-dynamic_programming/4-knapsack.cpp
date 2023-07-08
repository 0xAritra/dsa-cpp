#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> wts, vector<int> prices, int N, int W)
{
  if (N == 0 or W == 0)
    return 0;

  int inc = 0, exc = 0;

  if (wts[N - 1] <= W)
  {
    inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
  }
  exc = knapsack(wts, prices, N - 1, W);

  return max(inc, exc);
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

  cout << knapsack(wts, prices, n, w) << endl;
}