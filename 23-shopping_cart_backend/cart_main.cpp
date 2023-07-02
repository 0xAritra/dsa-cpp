#include <iostream>
#include <vector>
#include "datamodel.h"
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 220),
    Product(2, "mango", 70),
    Product(3, "banana", 80),
    Product(4, "orange", 70),
};

Product *chooseProduct()
{
  string productList;
  cout << "Available Products: " << endl;

  for (auto product : allProducts)
  {
    productList.append(product.getDisplayName());
  }
  cout << productList << endl;

  cout << "------------------------------" << endl;

  string choice;
  cin >> choice;

  for (int i = 0; i < allProducts.size(); i++)
  {
    if (allProducts[i].getShortName() == choice)
    {
      return &allProducts[i];
    }
  }
  cout << choice << " NOT FOUND!" << endl;
  return NULL;
}

bool checkout(Cart &cart)
{
  if (cart.isEmpty())
    return false;

  int paid;
  int total = cart.getTotal();

  cout << "Pay ₹ " << total << endl;
  cout << "Enter amount paid: ";
  cin >> paid;

  if (paid >= total)
  {
    cout << "Change: " << paid - total << endl;
    cout << "Thanks for shopping!" << endl;
    return true;
  }
  return false;
}

int main()
{
  char action;
  Cart cart;
  while (true)
  {
    cout << "Select an action - (a)dd item, (v)iew item, (c)heckout" << endl;
    cin >> action;

    if (action == 'a')
    {
      Product *product = chooseProduct();
      if (product != NULL)
      {
        cout << "ADDED TO CART: " << product->getDisplayName() << endl;
        cart.addProduct(*product);
      }
    }
    else if (action == 'v')
    {
      cout << "------------------------------" << endl;
      cout << cart.viewCart();
      cout << "------------------------------" << endl;
    }
    else
    {
      cout << cart.viewCart();
      if (checkout(cart))
        break;
    }
  }
}