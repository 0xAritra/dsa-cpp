#include <iostream>
#include <algorithm> // contains sort()
using namespace std;

// comparator
bool compare(int a, int b)
{
  return a > b;
}

int main()
{
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int n = sizeof(arr) / sizeof(int);

  // sort(arr, arr + n, greater<int>()); // greater - inbuilt comparator
  // reverse(arr, arr + n);

  sort(arr, arr + n, compare); // compare func is passed

  //
  for (int x : arr)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
