#include <iostream>
using namespace std;

int main()
{

  int n;
  cin >> n;

  // new
  int *arr = new int[n];

  cout << arr << endl;

  for (int i = 0; i < n; i++)
  {
    arr[i] = i + 1;
    // cout << arr[i] << " ";
    cout << *(arr + i) << " ";
  }

  cout << endl;

  // delete
  delete[] arr;

  cout << arr << endl; // arr still points to the memory!
  // cout << arr[2] << endl; // don't do this after deleting

  return 0;
}