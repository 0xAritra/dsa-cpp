#include <iostream>

using namespace std;

int main()
{

  char sentence[100];

  char temp = cin.get(); // takes one character at a time from the input buffer
  int len = 0;
  // while (temp != '#') // takes input until # is encountered

  while (temp != '\n') // ALSO, add a check len < 100 ! or seg fault
  {
    // cout << temp;
    sentence[len++] = temp;
    // len++;
    temp = cin.get();
  }
  sentence[len] = '\0';

  cout << sentence << endl;
  cout << "Length: " << len << endl;

  return 0;
}