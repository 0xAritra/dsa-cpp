#include <iostream>

using namespace std;

void print(int arr[][10], int n, int m)
{

  int startRow = 0;
  int startCol = 0;
  int endRow = n - 1;
  int endCol = m - 1;

  while (endRow >= startRow and endCol >= startCol)
  {
    // print start row
    for (int col = startCol; col <= endCol; col++)
    {
      cout << arr[startRow][col] << " ";
    }

    // print end col
    for (int row = startRow + 1; row <= endRow; row++)
    {
      cout << arr[row][endCol] << " ";
    }

    // print end row
    for (int col = endCol - 1; col >= startCol; col--)
    {
      if (startRow == endRow)

        cout << arr[endRow][col] << " ";
    }

    // print start col
    for (int row = endRow - 1; row >= startRow + 1; row--)
    {
      if (startCol == endCol)
      {
        break;
      }
      cout << arr[row][startCol] << " ";
    }

    startRow++;
    endCol--;
    endRow--;
    startCol++;
  }
  cout << endl;
}

int main()
{
  int arr[][10] = {
      {1, 2, 3, 4},
      {12, 13, 14, 5},
      {11, 16, 15, 6},
      {10, 9, 8, 7},
  };

  int n = 4, m = 4;

  print(arr, n, m);

  int arr1[][10] = {
      {1, 2, 3, 4, 5},
      {12, 13, 14, 15, 6},
      {11, 10, 9, 8, 7},
  };
  n = 3;
  m = 5;
  print(arr1, n, m);
  return 0;
}