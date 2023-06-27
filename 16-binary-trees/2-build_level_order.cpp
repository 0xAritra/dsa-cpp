#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
Node *buildTree()
{
  int x, y;
  cin >> x;

  queue<Node *> q;
  Node *root = new Node(x);
  q.push(root);

  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    cin >> x >> y;

    if (x != -1)
    {
      temp->left = new Node(x);
      q.push(temp->left);
    }
    if (y != -1)
    {
      temp->right = new Node(y);
      q.push(temp->right);
    }
  }

  return root;
}

// LEVEL ORDER PRINT (BFS)
/* O/P:
1
2 3
4 5 6
7
*/
void printLevelOrder(Node *root)
{

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *temp = q.front();
    if (temp == NULL)
    {
      cout << endl;
      q.pop();
      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      q.pop();
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }
}

// HEIGHT OF A TREE
// O(n)
int height(Node *root)
{
  if (root == NULL)
    return 0;
  int h1 = height(root->left);
  int h2 = height(root->right);

  return 1 + max(h1, h2);
}

// DIAMETER
// O(N^2)
int diameter(Node *root)
{
  if (root == NULL)
    return 0;

  int d1 = height(root->left) + height(root->right);
  int d2 = diameter(root->left);
  int d3 = diameter(root->right);

  return max(d1, max(d2, d3));
}

// DIAMETER OPTIMIZED
class HDPair
{
public:
  int h;
  int d;
};

HDPair dia(Node *root)
{
  HDPair p;
  if (root == NULL)
  {
    p.h = p.d = 0;
    return p;
  }

  HDPair left = dia(root->left);
  HDPair right = dia(root->right);

  p.h = max(left.h, right.h) + 1;

  int d1 = left.h + right.h;
  int d2 = left.d;
  int d3 = right.d;

  p.d = max(d1, max(d2, d3));
  return p;
}

int main()
{
  Node *root = buildTree();
  cout << "HEIGHT: " << height(root) << endl;
  printLevelOrder(root);

  // cout << "DIAMETER: " << diameter(root) << endl;
  cout << "DIAMETER: " << dia(root).d << endl;
  return 0;
}