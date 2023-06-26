// #include <iostream>

class List;

class Node
{
  int data;

public:
  Node *next;
  Node(int d) : data(d), next(NULL) {}

  int getData()
  {
    return data;
  }

  ~Node()
  {
    // recursively calls destructor of next Node
    if (next != NULL)
    {
      delete next;
    }

    // std::cout << "Deleting: " << data << std::endl;
  }

  // friend class List; // so list can access private variables
};

class List
{
  Node *head;
  Node *tail;

  int searchHelper(Node *start, int key)
  {
    if (start == NULL)
    {
      return -1;
    }
    if (start->getData() == key)
    {
      return 0;
    }

    int subIdx = searchHelper(start->next, key);
    if (subIdx == -1)
    {
      return -1;
    }
    else
    {
      return 1 + subIdx;
    }
  }

public:
  List() : head(NULL), tail(NULL) {}

  Node *begin()
  {
    return head;
  }

  void pushFront(int data)
  {
    if (head == NULL)
    {
      Node *n = new Node(data);
      head = n;
      tail = n;
    }
    else
    {
      Node *n = new Node(data);
      n->next = head;
      head = n;
    }
  }

  void pushBack(int data)
  {
    if (head == NULL)
    {
      Node *n = new Node(data);
      head = tail = n;
    }
    else
    {
      Node *n = new Node(data);
      tail->next = n;
      tail = n;
    }
  }

  void insert(int data, int pos)
  {
    if (pos == 0)
    {
      pushFront(data);
      return;
    }

    Node *n = head;
    for (int i = 1; i <= pos - 1; i++)
    {
      n = n->next;
    }
    Node *temp = new Node(data);
    temp->next = n->next;
    n->next = temp;
  }

  int search(int key)
  {
    Node *tempPtr = head;
    int idx = 0;
    while (tempPtr != NULL)
    {

      if (tempPtr->getData() == key)
      {
        return idx;
      }

      tempPtr = tempPtr->next;
      idx++;
    }
    return -1;
  }

  int recursiveSearch(int key)
  {
    int idx = searchHelper(head, key);
    return idx;
  }

  int popFront()
  {
    Node *temp = head;
    head = head->next;
    int d = temp->getData();
    temp->next = NULL; // or complete LL will be deleted
    delete temp;
    return d;
  }

  void popBack()
  {
    Node *temp = head;
    while (temp->next->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
  }

  void remove(int pos)
  {
    if (pos == 0)
    {
      popFront();
      return;
    }
    Node *temp = head;
    Node *n;
    for (int i = 1; i <= pos - 1; i++)
    {
      temp = temp->next;
    }
    n = temp->next;
    temp->next = n->next;
    n->next = NULL;
    delete n;
  }

  // REVERSE
  void reverse()
  {
    Node *current = head;
    Node *prev = NULL;
    Node *temp;

    while (current != NULL)
    {
      temp = current->next;
      current->next = prev;
      prev = current;
      current = temp;
    }
    head = prev;
  }

  ~List()
  {
    if (head != NULL)
    {
      delete head;
      head = NULL;
    }
  }
};