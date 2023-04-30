#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<vector<int> > arr = {
      {1, 2, 3},
      {4, 5},
      {6, 7, 8, 9}};

  for (int i = 0; i < arr.size(); i++)
  {
    // for (int j = 0; j < arr[i].size(); j++)
    // {
    //   cout << arr[i][j] << " ";
    // }

    // for each loop

    for (int x : arr[i])
    {
      cout << x << " ";
    }

    cout << endl;
  }

  return 0;
}