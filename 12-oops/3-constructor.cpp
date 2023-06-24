#include <iostream>
using namespace std;

class Product
{
private:
  int id;
  string name;
  int mrp = 0;
  int sellingPrice;

public:
  // constructor
  Product()
  {
    cout << "inside constructor!" << endl;
  }

  // parameterized constructor // overloading
  Product(int id, string name, int mrp, int sellingPrice)
  {
    this->id = id;
    this->name = name;
    this->mrp = mrp;
    this->sellingPrice = sellingPrice;
  }

  // setters
  void setMrp(int price)
  {
    if (price > 0)
    {
      mrp = price;
    }
  }

  void setSellingPrice(int price)
  {
    if (price > mrp)
    {
      sellingPrice = mrp;
    }
    else
    {
      sellingPrice = price;
    }
  }

  // getters
  int getMrp()
  {
    return mrp;
  }

  int getSellingPrice()
  {
    return sellingPrice;
  }
};

int main()
{
  // Product camera; // object
  Product camera(101, "GoPro Hero", 100, 90);

  // camera.setMrp(100);
  // camera.setSellingPrice(90);

  // cout << sizeof(camera) << endl;

  cout << "MRP: " << camera.getMrp() << " SellingPrice: " << camera.getSellingPrice() << endl;

  return 0;
}