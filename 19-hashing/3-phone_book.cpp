#include <iostream>
#include <map>
#include <list>

using namespace std;

int main()
{
  map<string, list<int> > phone_book;

  phone_book["Prateek"].push_back(64284);
  phone_book["Prateek"].push_back(5454);

  phone_book["Ari"].push_back(12345);
  phone_book["Ari"].push_back(48320);
  phone_book["Ari"].push_back(4718234);

  for (auto nameList : phone_book)
  {
    cout << nameList.first << " -> ";
    for (auto num : nameList.second)
    {
      cout << num << " - ";
    }
    cout << endl;
  }
}