#include <iostream>
using namespace std;

int main()
{
  float marks[100] = {-1}; // first value -1

  int n;
  cout << "Enter number of students: ";
  cin >> n;

  // INPUT
  for (int i = 1; i <= n; i++) // roll nos. from 1 to n
  {
    cin >> marks[i];
    // UPDATE
    marks[i] /= 10; // marks out of 10
  }

  // OUTPUT
  for (int i = 0; i < 100; i++) // printing complete array (or o/p only 1-n)
  {
    cout << marks[i] << ", ";
  }

  cout << endl;

  return 0;
}