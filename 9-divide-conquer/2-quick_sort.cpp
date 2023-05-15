#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
  int i = s - 1;
  int j = s;
  int pivot = e;
  while (j != e)
  {

    if (arr[j] < arr[pivot])
    {
      swap(arr[j], arr[++i]);
    }

    j++;
  }
  swap(arr[i + 1], arr[pivot]);
  return i + 1;
}

void quickSort(vector<int> &arr, int s, int e)
{
  // base
  if (s >= e)
    return;

  // recursive
  int p = partition(arr, s, e);
  quickSort(arr, s, p - 1);
  quickSort(arr, p + 1, e);
}

int main()
{
  vector<int> arr{10, 5, 2, 0, 7, 6, 4};
  int n = arr.size();
  quickSort(arr, 0, n - 1);

  for (int x : arr)
    cout << x << " ";
  cout << endl;

  return 0;
}