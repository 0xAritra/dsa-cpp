#include <iostream>
using namespace std;

// increasing order
bool compare(int x, int y)
{
  return x > y;
}

void bubble_sort_rec(int arr[], int n)
{
  if (n == 1)
    return;

  for (int i = 0; i < n - 1; i++)
  {
    if (compare(arr[i], arr[i + 1]))
    {
      swap(arr[i], arr[i + 1]);
    }
  }

  bubble_sort_rec(arr, n - 1);
}

void bubble_sort_rec_2(int arr[], int n, int j)
{
  if (n == 1)
    return;

  if (j == n - 1)
  {
    bubble_sort_rec_2(arr, n - 1, 0);
    return;
  }

  if (compare(arr[j], arr[j + 1]))
  {
    swap(arr[j], arr[j + 1]);
  }

  bubble_sort_rec_2(arr, n, j + 1);
}

int main()
{
  int arr[] = {10, 3, -4, -12, 0, 5, -3};
  int n = sizeof(arr) / sizeof(int);
  // bubble_sort_rec(arr, n);
  bubble_sort_rec_2(arr, n, 0);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}