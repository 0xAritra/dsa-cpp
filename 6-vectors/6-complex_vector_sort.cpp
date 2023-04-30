#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcSum(vector<int> v)
{
  int sum = 0;
  for (auto i : v)
  {
    sum += i;
  }
  return sum;
}

bool compare(pair<string, vector<int> > v1, pair<string, vector<int> > v2)
{
  return calcSum(v1.second) > calcSum(v2.second);
}

int main()
{
  vector<pair<string, vector<int> > > v = {
      {"Ram", {1, 6, 8}},
      {"Aritra", {7, 9, 5}},
      {"Rahul", {10, 10, 9}},
  };

  sort(v.begin(), v.end(), compare);

  for (auto i : v)
  {
    cout << i.first << " " << calcSum(i.second) << endl;
  }
  return 0;
}