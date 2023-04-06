#include <iostream>
using namespace std;

int main()
{
  int x = 10;
  int *xptr = &x; // pointer

  cout << xptr << endl;

  // address of pointer
  cout << &xptr << endl;

  // pointer to pointer
  int **xxptr = &xptr;
  cout << xxptr << endl;

  return 0;
}