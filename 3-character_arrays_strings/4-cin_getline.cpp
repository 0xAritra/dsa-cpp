#include <iostream>
using namespace std;

int main()
{
  // char sentence[1000];
  // cin.getline(sentence, 1000); // by default stops at '\n'

  char paragraph[1000];
  cin.getline(paragraph, 1000, '#'); // at '#'

  cout << paragraph << endl;
  return 0;
}