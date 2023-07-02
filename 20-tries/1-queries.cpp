#include <iostream>
#include "trie.h"
using namespace std;

int main()
{
  string words[] = {"hello", "he", "apple", "ape", "news"};
  Trie t;
  for (string word : words)
  {
    t.insert(word);
  }

  string key;
  cin >> key;

  cout << t.search(key) << endl;
}