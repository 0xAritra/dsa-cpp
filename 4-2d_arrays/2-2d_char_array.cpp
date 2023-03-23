#include <iostream>

using namespace std;

int main()
{

  char nums[][10] = {"one", "two", "three", "eighteen", "seventy", "hundred"};

  cout << nums[3] << endl; // nums[3] returns address but cout prints as string unlike int
  cout << nums[3][2] << endl;

  for (int i = 0; i < 6; i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}