#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Car
{
  int x;
  int y;

public:
  string id;
  Car(string id, int x, int y)
  {
    this->id = id;
    this->x = x;
    this->y = y;
  }
  int dist() const
  {
    return x * x + y * y;
  }
};

class CarCompare
{
public:
  bool operator()(Car A, Car B)
  {
    return A.dist() < B.dist();
  }
};
/*
input:
5 3
C1 1 1
C2 2 1
C3 3 2
C4 0 1
C5 2 3
output:
C4
C1
C2
*/

void printNearestCars(vector<Car> cars, int k)
{
  priority_queue<Car, vector<Car>, CarCompare> maxHeap(cars.begin(), cars.begin() + k);

  for (int i = k; i < cars.size(); i++)
  {
    Car car = cars[i];

    if (car.dist() < maxHeap.top().dist())
    {
      maxHeap.pop();
      maxHeap.push(car);
    }
  }
  vector<Car> res;
  while (!maxHeap.empty())
  {
    // cout << maxHeap.top().id << " ";
    res.push_back(maxHeap.top());
    maxHeap.pop();
  }
  reverse(res.begin(), res.end());

  for (auto x : res)
  {
    cout << x.id << " ";
  }
}

int main()
{
  int N, K;
  cin >> N >> K;

  string id;
  int x, y;

  vector<Car> cars;
  for (int i = 0; i < N; i++)
  {
    cin >> id >> x >> y;
    Car car = Car(id, x, y);
    cars.push_back(car);
  }

  cout << endl;
  printNearestCars(cars, K);
  cout << endl;
}