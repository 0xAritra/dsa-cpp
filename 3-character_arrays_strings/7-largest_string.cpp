#include <iostream>
#include <cstring>

using namespace std;

int main()
{

  char sentence[1000];
  char largest[1000];

  int n;
  int largest_len = 0;
  cout << "Enter no. of lines: ";
  cin >> n;
  cin.get(); // to consume \n

  while (n--)
  {
    cin.getline(sentence, 1000);
    int len = strlen(sentence);
    if (len > largest_len)
    {
      strcpy(largest, sentence);
      largest_len = len;
    }
  }

  cout << largest_len << " - " << largest << endl;
  return 0;
}