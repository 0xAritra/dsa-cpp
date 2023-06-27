#include <iostream>
#include <queue>
using namespace std;
// PREORDER: ROOT, LEFT, RIGHT
// INPUT: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

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

// PREORDER BUILD
Node *buildTree()
{
  int d;
  cin >> d;

  if (d == -1)
    return NULL;
  Node *n = new Node(d);
  n->left = buildTree();
  n->right = buildTree();
  return n;
}

// PREORDER PRINT
// PREORDER OUTPUT: 1 2 4 5 7 3 6
void printPreorder(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  printPreorder(root->left);
  printPreorder(root->right);
}

// INORDER PRINT: LEFT, ROOT, RIGHT
// INORDER OUTPUT: 4 2 7 5 1 3 6

void printInorder(Node *root)
{
  if (root == NULL)
    return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

// POSTORDER PRINT: LEFT, RIGHT, ROOT
// BOTTOMUP TRAVERSAL
// POSTORDER OUTPUT: 4 7 5 2 6 3 1
void printPostorder(Node *root)
{
  if (root == NULL)
    return;
  printPostorder(root->left);
  printPostorder(root->right);
  cout << root->data << " ";
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

int main()
{
  Node *n = buildTree();
  printPreorder(n);
  cout << endl;

  printInorder(n);
  cout << endl;

  printPostorder(n);
  cout << endl;

  printLevelOrder(n);
}