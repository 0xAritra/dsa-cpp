#include <iostream>
#include "list.h"
using namespace std;

int main()
{
  List l;
  l.pushFront(1);
  l.pushFront(0);
  l.pushBack(3);
  l.pushBack(4);

  l.insert(2, 2);
  // l.popBack();
  // l.popFront();

  // l.remove(2);

  // cout << "AT: " << l.recursiveSearch(2) << endl;

  l.reverse();

  // PRINT
  Node *head = l.begin();
  while (head != NULL)
  {
    cout << head->getData() << " ";
    head = head->next;
  }
  cout << endl;
  //

  return 0;
}