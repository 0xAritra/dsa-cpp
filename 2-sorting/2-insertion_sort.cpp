#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int current = arr[i];
    int prev = i - 1;

    while (prev >= 0 && current < arr[prev])
    {
      arr[prev + 1] = arr[prev];
      prev--;
    }

    arr[prev + 1] = current;
  }
}

int main()
{
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  insertion_sort(arr, n);

  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}

// My Implementation
/* void insertion_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int temp = arr[i];
    int j;
    for (j = i - 1; j >= 0; j--)
    {
      if (temp < arr[j])
      {
        arr[j + 1] = arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j + 1] = temp;
  }
} */