/*
  default copy assignment operator performs a shallow copy!
*/

#include <iostream>
#include <cstring>
using namespace std;

class Product
{
private:
  int id;
  char *name;
  int mrp = 0;
  int sellingPrice;

public:
  // constructor
  Product()
  {
    cout << "inside constructor!" << endl;
  }

  // parameterized constructor // overloading
  Product(int id, char *n, int mrp, int sellingPrice)
  {
    this->id = id;
    name = new char[strlen(name) + 1];
    strcpy(name, n);
    this->mrp = mrp;
    this->sellingPrice = sellingPrice;
  }

  // DEEP COPY
  Product(Product &X)
  {
    id = X.id;
    name = new char[strlen(X.name) + 1];
    strcpy(name, X.name);
    mrp = X.mrp;
    sellingPrice = X.sellingPrice;
  }

  void operator=(Product &X)
  {
    id = X.id;
    name = new char[strlen(X.name) + 1];
    strcpy(name, X.name);
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

  void setName(char *name)
  {
    strcpy(this->name, name);
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
  Product camera(101, "GoPro Hero", 1000, 90);
  Product oldCamera;
  oldCamera = camera;

  oldCamera.setName("GoPro8");
  oldCamera.setSellingPrice(1000);
  camera.getDetails();
  oldCamera.getDetails();

  return 0;
}