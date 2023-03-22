#include <iostream>
#include <cstring>
using namespace std;

int main()
{

  char a[100] = "apple";
  char b[100];

  cout << strlen(a) << endl;

  strcpy(b, a); // copy a to b
  cout << b << endl;

  cout << strcmp(a, b) << endl; // returns 0 if same

  char web[] = "www.";
  char domain[] = "aritra.xyz";

  cout << strcat(web, domain) << endl; // concatenates two strings

  cout << strcmp(web, a) << endl; // returns a +ve or -ve value on false

  return 0;
}