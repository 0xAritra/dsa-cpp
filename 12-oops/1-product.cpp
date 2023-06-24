#include <iostream>
using namespace std;

class Product
{
  // private
  int id;
  string name;

public:
  int mrp;
  int sellingPrice;
};

int main()
{
  Product camera; // object

  // can't enforce conditions like sp <= mrp if public (!bad)
  camera.mrp = 100;
  camera.sellingPrice = 200;

  cout << sizeof(camera) << endl;

  cout << "MRP: " << camera.mrp << " SellingPrice: " << camera.sellingPrice << endl;

  return 0;
}