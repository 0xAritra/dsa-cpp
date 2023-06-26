class Node
{
public:
  int data;
  Node *next;

  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

class Queue
{
  Node *head;
  Node *tail;

public:
  Queue()
  {
    head = NULL;
    tail = NULL;
  }

  bool empty()
  {
    return head == NULL;
  }

  void push(int d)
  {
    Node *n = new Node(d);
    if (empty())
    {
      head = n;
      tail = n;
    }
    else
    {
      tail->next = n;
      tail = n;
    }
  }

  void pop()
  {
    if (empty())
      return;
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  int front()
  {
    return head->data;
  }
};