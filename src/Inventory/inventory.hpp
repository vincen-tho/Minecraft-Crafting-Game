#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <utility>
#include <string>
#include "../Item/Item.h"
#include "../Exception/Exception.hpp"

using namespace std;

class Inventory
{
private:
    pair<Item*, int> inventory[27];

public:
    Inventory();
    void add_item(int inventoryID, Item *item, int quantity);
    void add_item(Item *item, int quantity);

    void add_item(Tool item, int quantity);
    void add_item(NonTool item, int quantity);
    
    void add_item(int inventoryID, Tool item, int quantity);
    void add_item(int inventoryID, NonTool item, int quantity);

    void remove_item(Item* item, int quantity);

    void DISCARD(int inventoryID, int quantity);
    void MOVE(int srcID, int destID);

    void display_inventory();

    pair<Item*, int> operator[](int i) const;
    pair<Item*, int> &operator[](int i);
};

#endif
