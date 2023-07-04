#include <iostream>
#include <list>
#include <queue>
// #include <vector>
using namespace std;

class Graph
{
  int V;
  list<int> *l;

public:
  Graph(int v)
  {
    V = v;
    l = new list<int>[V];
  }

  void addEdge(int i, int j, bool undir = true)
  {
    l[i].push_back(j);
    if (undir == true)
    {
      l[j].push_back(i);
    }
  }

  void printAdjList()
  {
    for (int i = 0; i < V; i++)
    {
      cout << i << ": ";
      for (auto node : l[i])
      {
        cout << node << " -> ";
      }
      cout << endl;
    }
  }

  // BFS
  void bfs(int source)
  {
    queue<int> q;
    q.push(source);
    // vector<bool> visited(V, false);
    bool *visited = new bool[V]{0};
    visited[source] = true;

    while (!q.empty())
    {
      int f = q.front();
      q.pop();
      cout << f << " ";
      for (auto nbr : l[f])
      {
        if (!visited[nbr])
        {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }

  // DFS
  void dfsHelper(int source, bool *visited)
  {
    visited[source] = true;
    cout << source << " ";

    for (auto nbr : l[source])
    {
      if (!visited[nbr])
      {
        dfsHelper(nbr, visited);
      }
    }
  }
  void dfs(int source)
  {
    bool *visited = new bool[V]{0};
    dfsHelper(source, visited);
  }

  void topological_sort()
  {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++)
    {
      for (auto nbr : l[i])
      {
        indegree[nbr]++;
      }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int f = q.front();
      q.pop();

      cout << f << " ";

      for (auto nbr : l[f])
      {
        indegree[nbr]--;
        if (indegree[nbr] == 0)
        {
          q.push(nbr);
        }
      }
    }
  }
};

int main()
{
  // Graph g(6);
  // g.addEdge(0, 1);
  // g.addEdge(0, 4);
  // g.addEdge(2, 1);
  // g.addEdge(3, 4);
  // g.addEdge(4, 5);
  // g.addEdge(2, 3);
  // g.addEdge(3, 5);

  Graph g(7);
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(5, 6);
  g.addEdge(4, 5);
  g.addEdge(0, 4);
  g.addEdge(3, 4);

  // g.printAdjList();
  cout << "BFS: ";
  g.bfs(1);
  cout << endl;
  cout << "DFS: ";
  g.dfs(1);
  cout << endl;

  Graph g1(6); // DAG
  g.addEdge(0, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(4, 5);
  g.addEdge(1, 4);
  g.addEdge(1, 2);

  cout << "g1: topological sort: ";
  g1.topological_sort();
  cout << endl;
}