#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char a[10];
  char b[] = {'a', 'b', 'c', 'd'};       // wrong - gets garbage value too
  char c[] = {'a', 'b', 'c', 'd', '\0'}; // correct
  char d[10] = "abc";

  char e[100];
  // cout << c << endl;

  cin >> e; // issue is you can't input strings like "hello world"
  cout << e << endl;

  cout << "c: "
       << "strlen: " << strlen(c) << " sizeof: " << sizeof(c) << endl; // sizeof gives +1 because of NULL char

  return 0;
}