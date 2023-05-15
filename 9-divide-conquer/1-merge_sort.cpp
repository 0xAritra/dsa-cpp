#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int r)
{
  int mid = (l + r) / 2;
  int i = l;
  int j = mid + 1;
  vector<int> temp;

  cout << l << '\t' << r << endl;

  while (i <= mid && j <= r)
  {
    if (arr[i] < arr[j])
    {
      temp.push_back(arr[i++]);
    }
    else
    {
      temp.push_back(arr[j++]);
    }
  }

  // copy remaining elements
  while (i <= mid)
  {
    temp.push_back(arr[i++]);
  }
  while (j <= r)
  {
    temp.push_back(arr[j++]);
  }

  int k = 0;
  for (int i = l; i <= r; i++)
  {
    arr[i] = temp[k++];
  }
}

void mergeSort(vector<int> &arr, int l, int r)
{
  if (l >= r)
  {
    return;
  }
  int mid = (l + r) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid + 1, r);
  merge(arr, l, r);
}

int main()
{
  vector<int> arr = {10, 5, 8, 11, 0, -4, 6, -6, -6, 0, 1};
  int l = 0;
  int r = arr.size() - 1;

  mergeSort(arr, l, r);

  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;
}