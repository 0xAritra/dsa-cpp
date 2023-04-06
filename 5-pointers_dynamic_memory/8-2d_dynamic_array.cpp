#include <iostream>
using namespace std;

int **create2dArray(int rows, int cols)
{
  // create
  int **arr = new int *[rows];
  for (int i = 0; i < rows; i++)
  {
    arr[i] = new int[cols];
  }

  // init
  int n = 1;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      arr[i][j] = n;
      n++;
    }
  }
  return arr;
}

int main()
{
  int rows, cols;
  cin >> rows >> cols;

  int **arr = create2dArray(rows, cols);

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << arr[i][j] << '\t';
    }
    cout << endl;
  }

  return 0;
}