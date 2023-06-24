#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  // get reversed list
  for (int i = 0; i < n; i++)
  {
    arr[i] = n - i;
  }

  int start = clock();
  sort(arr.begin(), arr.end());
  int end = clock();
  cout << double(end - start) / CLOCKS_PER_SEC << endl;
}