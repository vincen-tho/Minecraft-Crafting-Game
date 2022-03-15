#include "inventory.hpp"
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    for (int i = 0; i < 27; i++)
    {
        inventory[i] = make_pair(Item(), 0);
    }
}

// add item with maximum quantity 64
void Inventory::add_item(Item item, int quantity)
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first.get_name() == item.get_name())
        {
            if (inventory[i].second + quantity > 64)
            {
                int temp = inventory[i].second;
                inventory[i].second = 64;
                add_item(item, temp + quantity - 64);
                return;
            }
            else
            {
                inventory[i].second += quantity;
                return;
            }
            return;
        }
    }

    // adding new item
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first.get_name() == "noname")
        {
            if (quantity > 64)
            {
                inventory[i].first = item;
                inventory[i].second = 64;
                add_item(item, quantity - 64);
                return;
            }
            else
            {
                inventory[i].first = item;
                inventory[i].second = quantity;
                return;
            }
        }
    }

    // if inventory is full
    cout << "Inventory is full" << endl;
}

void Inventory::remove_item(Item item, int quantity){
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first.get_name() == item.get_name())
        {
            if (inventory[i].second - quantity == 0)
            {
                inventory[i] = make_pair(Item(), 0);
                return;
            }
            else if(inventory[i].second - quantity < 0){
                cout << "Not enough quantity" << endl;
                return;
            }
            else
            {
                inventory[i].second -= quantity;
                return;
            }
        }
    }
    cout << "Item not found" << endl;
}
