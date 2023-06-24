#include <iostream>
using namespace std;

bool solveSudoko(int mat[9][9], int i, int j, int n)
{
}

int main()
{
  int n = 9;
  int mat[9][9] = {
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 9, 9, 9, 9, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    }
  }

  if (!solveSudoko(mat, 0, 0, n))
  {
    cout << "No solution exists!";
  }

  return 0;
}