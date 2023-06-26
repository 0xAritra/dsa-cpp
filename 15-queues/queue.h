
class Queue
{
  int *arr;
  int ms;
  int cs;

  int front;
  int rear;

public:
  Queue(int defaultSize = 5)
  {
    ms = defaultSize;
    arr = new int[ms];
    cs = 0;
    front = 0;
    rear = ms - 1;
  }

  bool full()
  {
    return ms == cs;
  }

  bool empty()
  {
    return cs == 0;
  }

  void push(int data)
  {
    if (!full())
    {
      rear = (rear + 1) % ms;
      arr[rear] = data;
      cs++;
    }
  }

  void pop()
  {
    if (!empty())
    {
      front = (front + 1) % ms;
      cs--;
    }
  }

  int getFront()
  {
    return arr[front];
  }
};