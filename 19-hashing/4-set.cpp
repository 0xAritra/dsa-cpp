#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
  // RANDOM ORDER // collection of keys
  unordered_set<int> s{2, 4, 5, 11, 6, 7, 7};

  // DELETE
  s.erase(7);

  // INSERT
  s.insert(10);

  int key;
  cin >> key;

  // FIND - O(1)
  if (s.find(key) != s.end())
    cout << key << " is FOUND" << endl;
  else
    cout << key << " NOT FOUND" << endl;

  // TRAVERSAL
  for (auto i : s)
    cout << i << " ";
  cout << endl;
}