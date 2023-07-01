#include <iostream>
#include "hashtable.h"
using namespace std;

int main()
{
  Hashtable<int> h;

  h.insert("Mango", 70);
  h.insert("Apple", 220);
  h.insert("Banana", 80);
  h.insert("Orange", 70);

  // h.insert("Avocado", 180);
  // h.insert("Watermelon", 25);
  // h.insert("Strawberry", 420);
  // h.insert("Mosambi", 60);

  h.print();

  // SEARCH
  // string fruit;
  // cin >> fruit;
  // int *price = h.search(fruit);

  // if (price != NULL)
  // {
  //   cout << "Price of " << fruit << ": " << *price << endl;
  // }
  // else
  // {
  //   cout << fruit << " not present!" << endl;
  // }
  //

  h.erase("Banana");

  h["newFruit"] = 100;
  cout << "newFruit: " << h["newFruit"] << endl;
  h["newFruit"] += 20;
  cout << "updated newFruit: " << h["newFruit"] << endl;
}
