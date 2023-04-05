#include <iostream>
using namespace std;

pair<int, int> staircaseSearch(int arr[][10], int n, int m, int key)
{
  int i = 0, j = m - 1;
  if (key < arr[0][0] or key > arr[n - 1][m - 1])
    return {-1, -1};
  while (i < n and j >= 0)
  {
    if (arr[i][j] == key)
    {
      return {i, j};
    }
    else if (arr[i][j] < key)
    {
      i++;
    }
    else
    {
      j--;
    }
  }
  return {-1, -1};
}

int main()
{
  int arr[][10] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {27, 29, 37, 48},
      {32, 33, 39, 50}};

  int n = 4, m = 4;

  pair<int, int> coords = staircaseSearch(arr, n, m, 33);
  cout << coords.first << " " << coords.second << endl;
  return 0;
}