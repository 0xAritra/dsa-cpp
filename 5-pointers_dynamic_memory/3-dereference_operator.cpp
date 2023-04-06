// * : value pointed to by

#include <iostream>
using namespace std;

int main()
{

  int x = 10;
  int *xptr = &x;

  cout << *xptr << endl;
  cout << *&x << endl;

  // NULL Pointer
  // int *nullptr = 0;
  int *nullptr1 = NULL;

  cout << nullptr1 << endl;
  // null ptr cant be dereferenced - seg fault

  return 0;
}