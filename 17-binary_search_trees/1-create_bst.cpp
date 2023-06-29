#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int key;
  Node *left;
  Node *right;

  Node(int key)
  {
    this->key = key;
    left = right = NULL;
  }
};

Node *insert(Node *root, int key)
{
  if (root == NULL)
    return new Node(key);

  if (key <= root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);

  return root;
}

bool search(Node *root, int key)
{
  if (root == NULL)
    return false;
  if (root->key == key)
    return true;
  else if (key < root->key)
  {
    return search(root->left, key);
  }
  else
  {
    return search(root->right, key);
  }
}

void printInorder(Node *root)
{
  if (root == NULL)
    return;

  printInorder(root->left);
  cout << root->key << " ";
  printInorder(root->right);
}

Node *findMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

// DELETE NODE - inorder traversal should stay same
Node *remove(Node *root, int key)
{
  if (root == NULL)
    return NULL;
  else if (key < root->key)
  {
    root->left = remove(root->left, key);
  }
  else if (key > root->key)
  {
    root->right = remove(root->right, key);
  }
  else
  {
    // match with key
    // no child
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }
    // 1 child
    else if (root->left == NULL)
    {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    // 2 children
    else
    {
      Node *temp = findMin(root->right);
      root->key = temp->key;
      root->right = remove(root->right, temp->key);
    }
  }
  return root;
}

void printRange(Node *root, int k1, int k2)
{
  if (root == NULL)
    return;
  else if ((root->key >= k1) && (root->key <= k2))
  {
    printRange(root->left, k1, k2);
    cout << root->key << " ";
    printRange(root->right, k1, k2);
  }
  else if (root->key > k2)
  {
    printRange(root->left, k1, k2);
  }
  else // (root->key < k1)
  {
    printRange(root->right, k1, k2);
  }
}

void printRoot2LeafPaths(Node *root, vector<int> &path)
{
  if (root == NULL)
    return;
  else if (root->left == NULL && root->right == NULL)
  {
    for (int x : path)
    {
      cout << x << " ";
    }
    cout << root->key << endl;
  }

  path.push_back(root->key);
  printRoot2LeafPaths(root->left, path);
  printRoot2LeafPaths(root->right, path);
  path.pop_back();
}

//
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

int main()
{
  Node *root = NULL;
  int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

  for (int x : arr)
  {
    root = insert(root, x);
  }

  printInorder(root);
  cout << endl;

  // cout << search(root, 11) << endl;

  // int key;
  // cin >> key;
  // root = remove(root, key);

  // printInorder(root);
  // cout << endl;

  // printRange(root, 5, 12);
  Node *root1 = buildTree(); // 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
  vector<int> path;
  printRoot2LeafPaths(root1, path);
}