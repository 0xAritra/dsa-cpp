// 2d array - sorted row-wise, col-wise
// can be done w/ brute force / binary search on each row
// staircase search - my implementation
#include <iostream>
using namespace std;

void search(int arr[][10], int n, int m, int key)
{
  int i = 0, j = m - 1;
  while (i < n and j >= 0)
  {
    if (arr[i][j] < key)
    {
      i++;
    }
    else if (arr[i][j] > key)
    {
      j--;
    }
    else
    {
      cout << key << " found at: " << i << "," << j << endl;
      return;
    }
  }
  cout << "Not Found!" << endl;
}

int main()
{
  int arr[][10] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {27, 29, 37, 48},
      {32, 33, 39, 50}};

  int n = 4, m = 4;

  search(arr, n, m, 41);

  return 0;
}