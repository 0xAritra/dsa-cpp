#include <iostream>
using namespace std;

void print(int arr[][100], int n, int m) // pass by ref, passing arr size of row is optional
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << arr[i][j] << '\t';
    }
    cout << endl;
  }
}

int main()
{
  int arr[100][100];
  // int arr[][2] = {{1, 2}};

  int n, m; // n: rows / m: cols
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> arr[i][j];
    }
  }

  print(arr, n, m);
}