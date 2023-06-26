template <typename T>
class Stack;

template <typename T>
class Node
{
public:
  T data;
  Node<T> *next;

  Node<T>(T d)
  {
    data = d;
  }
};

template <typename T>
class Stack
{
  Node<T> *head;

public:
  Stack<T>()
  {
    head = NULL;
  }

  void push(T d)
  {
    Node<T> *n = new Node<T>(d);
    n->next = head;
    head = n;
  }

  bool empty()
  {
    return head == NULL;
  }

  void pop()
  {
    Node<T> *temp = head;
    head = head->next;
    delete temp;
  }

  T top()
  {
    return head->data;
  }
};