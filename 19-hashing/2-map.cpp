#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// MAP - O(log N): for all operations + sorts acc to keys

int main()
{
  // unordered_map<string, int> menu;
  map<string, int> menu;

  // insert
  menu["dosa"] = 50;
  menu["idli"] = 20;
  menu["poha"] = 30;
  menu["parantha"] = 60;

  // update
  menu["idli"] += 15;

  // delete
  menu.erase("dosa");

  // search
  string s;
  cin >> s;
  if (menu.count(s) == 0)
    cout << s << " Not FOUND!" << endl;
  else
    cout << "FOUND: " << s << " -> " << menu[s] << endl;

  // traversal // O(n) + no order (unordered)
  for (pair<string, int> item : menu)
  {
    cout << item.first << " -> " << item.second << endl;
  }
}