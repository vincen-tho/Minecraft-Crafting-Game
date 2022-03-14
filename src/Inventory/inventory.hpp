#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__

#include <utility>
#include <string>

using namespace std;

class Inventory
{
private:
    pair<string, int> inventory[27];

public:
    Inventory();
    void add_item(string name, int quantity);
    void remove_item(string name, int quantity);
    void display_inventory();
};

#endif
