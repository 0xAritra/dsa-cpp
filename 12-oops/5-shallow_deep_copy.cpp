/*
  Shallow Copy:
    if dynamic variable (heap memory) is used on copying the object - the new object attribute points to the old objects attribute so changing it causes the common heap variable to change - so we need to have our own copy constructor
  Deep Copy:
    create own copy constructor - if object has ptr to dynamically allocated memory
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

  // SHALLOW COPY
  // Product(Product &X)
  // {
  //   id = X.id;
  //   name = X.name;
  //   mrp = X.mrp;
  //   sellingPrice = X.sellingPrice;
  // }

  // DEEP COPY
  Product(Product &X)
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
  Product camera(101, "GoPro Hero", 100, 90);
  Product oldCamera(camera);
  oldCamera.setName("GoPro8");
  oldCamera.setSellingPrice(1000);
  camera.getDetails();
  oldCamera.getDetails();

  return 0;
}