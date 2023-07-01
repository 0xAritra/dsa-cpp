#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  string key;
  T value;
  Node *next;

  Node(string key, T value)
  {
    this->key = key;
    this->value = value;
    this->next = NULL;
  }

  ~Node()
  {
    if (next != NULL)
    {
      delete next;
    }
    // cout << "deleting: " << key << endl;
  }
};

template <typename T>
class Hashtable
{
  Node<T> **table;
  int cs;
  int ts;

  int hashFn(string key)
  {
    int idx = 0;
    int power = 1;
    for (auto ch : key)
    {
      idx = (idx + ch * power) % ts;
      power = (power * 29) % ts;
    }
    return idx;
  }

  void rehash()
  {
    Node<T> **oldTable = table;
    int oldTs = ts;

    cs = 0;
    ts = ts * 2 + 1; // better make prime num!
    table = new Node<T> *[ts];

    // set NULL in new table
    for (int i = 0; i < ts; i++)
    {
      table[i] = NULL;
    }

    for (int i = 0; i < oldTs; i++)
    {
      Node<T> *temp = oldTable[i];

      // INSERT into new table
      while (temp != NULL)
      {
        insert(temp->key, temp->value);
        temp = temp->next;
      }

      if (oldTable[i] != NULL)
      {
        delete oldTable[i];
      }
    }

    delete[] oldTable;
  }

public:
  Hashtable(int default_size = 7)
  {
    cs = 0;
    ts = default_size;

    table = new Node<T> *[ts];

    // set garbage to NULL
    for (int i = 0; i < ts; i++)
    {
      table[i] = NULL;
    }
  }

  // FOR TESTING
  void print()
  {
    for (int i = 0; i < ts; i++)
    {
      cout << i << ": ";
      Node<T> *temp = table[i];
      while (temp != NULL)
      {
        cout << temp->key << " " << temp->value << " -> ";
        temp = temp->next;
      }
      cout << endl;
    }
  }

  void insert(string key, T val)
  {
    int idx = hashFn(key);

    Node<T> *n = new Node<T>(key, val);

    // insert at HEAD
    n->next = table[idx];
    table[idx] = n;

    cs++;

    float load_factor = (float)cs / ts;
    if (load_factor > 0.7)
      rehash();
  }

  T *search(string key)
  {
    int idx = hashFn(key);
    Node<T> *temp = table[idx];

    while (temp != NULL)
    {
      if (temp->key == key)
      {
        return &temp->value;
      }
      temp = temp->next;
    }

    return NULL;
  }

  // do better approach!
  void erase(string key)
  {
    int idx = hashFn(key);
    Node<T> *temp = table[idx];

    // at head
    if (temp->key == key)
    {
      table[idx] = temp->next;
      temp->next = NULL;
      delete temp;
      return;
    }

    // mid, end
    Node<T> *prev = NULL;
    while (temp != NULL)
    {
      if (temp->key == key)
      {
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
  }

  T &operator[](string key)
  {
    T *valueFound = search(key);
    if (valueFound == NULL)
    {
      T object;
      insert(key, object);
      valueFound = search(key);
    }
    return *valueFound;
  }

  ~Hashtable()
  {
    for (int i = 0; i < ts; i++)
    {
      if (table[i] != NULL)
      {
        delete table[i];
        table[i] = NULL;
      }
    }
    delete[] table;
  }
};