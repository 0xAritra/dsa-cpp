#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// WITHOUT DP - has overlapping subproblems
int coin_change(vector<int> denoms, int m)
{
  if (m == 0)
    return 0;

  int res = INT_MAX;

  for (int i = 0; i < denoms.size(); i++)
  {
    if (m >= denoms[i])
    {
      res = min(res, coin_change(denoms, m - denoms[i]));
    }
  }

  return res + 1;
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