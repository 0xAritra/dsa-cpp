#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
  string name;
  list<string> neighbors;
  Node(string name)
  {
    this->name = name;
  }
};

class Graph
{
  unordered_map<string, Node *> m;

public:
  Graph(vector<string> cities)
  {
    for (string city : cities)
    {
      m[city] = new Node(city);
    }
  }

  void addEdge(string x, string y, bool undir = false)
  {
    m[x]->neighbors.push_back(y);
    if (undir == true)
    {
      m[y]->neighbors.push_back(x);
    }
  }

  //
  void printAdjList()
  {
    for (auto cityPair : m)
    {
      Node *node = cityPair.second;
      cout << cityPair.first << ": ";

      // for (auto it = cityPair.second->neighbors.begin(); it != cityPair.second->neighbors.end(); it++)
      for (auto city : node->neighbors)
      {
        cout << city << " - ";
      }
      cout << endl;
    }
  }
};

int main()
{
  vector<string> cities = {"Delhi", "London", "Paris", "New York"};

  Graph g(cities);

  g.addEdge("Delhi", "London");
  g.addEdge("New York", "London");
  g.addEdge("Delhi", "Paris");
  g.addEdge("Paris", "New York");

  g.printAdjList();
}