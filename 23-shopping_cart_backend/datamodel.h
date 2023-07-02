#include <string>
#include <unordered_map>
using namespace std;

class Item;
class Cart;

class Product
{
  int id;
  string name;
  int price;

public:
  Product() {}
  Product(int id, string name, int price)
  {
    this->id = id;
    this->name = name;
    this->price = price;
  }

  string getDisplayName()
  {
    return name + ": ₹ " + to_string(price) + '\n';
  }

  string getShortName()
  {
    return name.substr(0, 1);
  }

  friend class Item;
  friend class Cart;
};

class Item
{
  Product product;
  int quantity;

public:
  Item() {}
  Item(Product p, int q) : product(p), quantity(q) {}

  int getItemPrice()
  {
    return product.price * quantity;
  }

  string getItemInfo()
  {
    return to_string(quantity) + " x " + product.name + ": ₹" + to_string(getItemPrice()) + "\n";
  }

  friend class Cart;
};

class Cart
{
  unordered_map<int, Item> items;

public:
  void addProduct(Product product)
  {
    if (items.count(product.id) == 0)
    {
      Item newItem(product, 1);
      items[product.id] = newItem;
      return;
    }
    items[product.id].quantity++;
  }

  int getTotal()
  {
    int total = 0;
    for (auto itemPair : items)
    {
      Item item = itemPair.second;
      total += item.getItemPrice();
    }
    return total;
  }

  bool isEmpty()
  {
    return items.empty();
  }

  string viewCart()
  {
    if (isEmpty())
    {
      return "Cart is EMPTY!\n";
    }

    string itemsList;
    int itemsCount = 0;
    int cart_total = getTotal();

    for (auto itemPair : items)
    {
      Item item = itemPair.second;
      itemsCount += item.quantity;
      itemsList.append(item.getItemInfo());
    }

    return itemsList + "\n TOTAL ITEMS: " + to_string(itemsCount) + "\n TOTAL AMOUNT: ₹" + to_string(cart_total) + "\n";
  }
};