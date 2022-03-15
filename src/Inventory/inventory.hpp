#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <utility>
#include <string>
#include "Item.h"

using namespace std;

class Inventory
{
private:
    pair<Item, int> inventory[27];

public:
    Inventory();
    void add_item(Item item, int quantity);
    void remove_item(Item item, int quantity);
    void display_inventory();
};

#endif
