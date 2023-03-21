#include <iostream>
#include <vector>

using namespace std;

void counting_sort(int arr[], int n)
{
  // find largest element to find the range (size of freq/ count arr)
  int largest = -1;
  for (int i = 0; i < n; i++)
  {
    largest = max(largest, arr[i]);
  }

  // create count/ freq arr
  vector<int> freq(largest + 1, 0);
  for (int i = 0; i < n; i++)
  {
    freq[arr[i]]++;
  }

  // put back elements in order
  int j = 0;
  for (int i = 0; i <= largest; i++) // O(n + range)
  {
    while (freq[i] > 0)
    {
      arr[j] = i;
      j++;
      freq[i]--;
    }
  }
}

int main()
{

  int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
  int n = sizeof(arr) / sizeof(int);

  counting_sort(arr, n);

  for (int x : arr)
  {
    cout << x << " ";
  }

  cout << endl;

  return 0;
}