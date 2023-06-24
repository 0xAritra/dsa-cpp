#include <iostream>
using namespace std;

void printBoard(int board[][20], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool canPlace(int board[][20], int n, int x, int y)
{
  // column
  for (int i = 0; i < x; i++)
  {
    if (board[i][y] == 1)
    {
      return false;
    }
  }

  // left diagonal
  int i = x, j = y;
  while (i >= 0 and j >= 0)
  {
    if (board[i][j] == 1)
    {
      return false;
    }
    i--;
    j--;
  }

  // right diagonal
  i = x, j = y;
  while (i >= 0 and j < n)
  {
    if (board[i][j] == 1)
    {
      return false;
    }
    i--;
    j++;
  }

  return true;
}

bool solveNQueen(int board[][20], int n, int i)
{
  // base case
  if (i == n)
  {
    printBoard(board, n);
    return true;
  }

  // rec case
  for (int j = 0; j < n; j++)
  {
    if (canPlace(board, n, i, j))
    {
      board[i][j] = 1;
      if (solveNQueen(board, n, i + 1))
      {
        return true;
      }
      // backtrack
      board[i][j] = 0;
    }
  }
  return false;
}

int main()
{
  int board[20][20] = {0};
  int n;
  cin >> n;
  solveNQueen(board, n, 0);
  return 0;
}