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
  Product camera; // object

  camera.setMrp(100);
  camera.setSellingPrice(90);

  // cout << sizeof(camera) << endl;

  cout << "MRP: " << camera.getMrp() << " SellingPrice: " << camera.getSellingPrice() << endl;

  return 0;
}