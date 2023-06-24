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

  // copy constructor overides default
  Product(Product &X)
  {
    id = X.id;
    name = X.name;
    mrp = X.mrp;
    sellingPrice = X.sellingPrice;
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

  void getDetails()
  {
    cout << "id: " << id << endl;
    cout << "name: " << name << endl;
    cout << "mrp: " << mrp << endl;
    cout << "sellingPrice: " << sellingPrice << endl;
    cout << "---" << endl;
  }
};

int main()
{
  Product camera(101, "GoPro Hero", 100, 90);
  camera.getDetails();
  // copy!
  Product webcam(camera);
  webcam.getDetails();

  // calls copy constructor
  Product handyCam = camera;
  handyCam.getDetails();

  return 0;
}