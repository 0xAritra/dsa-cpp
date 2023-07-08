#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int> nums)
{
  // int dp[nums.size()] = {0};
  int dp[nums.size()];
  for (int i = 0; i < nums.size(); i++)
    dp[i] = 1;

  int res = 1;

  for (int i = 1; i < nums.size(); i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (nums[i] > nums[j])
      {
        dp[i] = max(dp[i], dp[j] + 1);
        if (dp[i] > res)
          res = dp[i];
      }
      // else
      //   dp[i] = max(dp[i], 1);
    }
  }
  return res;
}

/*
  INPUT:
    n: num of elements
    nums[]: enter n elements
*/
int main()
{
  int n;
  vector<int> nums;

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }

  cout << lis(nums) << endl;
}