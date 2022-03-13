#include "inventory.hpp"
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    for (int i = 0; i < 27; i++)
    {
        inventory[i] = make_pair("", 0);
    }
}

// add item with maximum quantity 64
void Inventory::add_item(string name, int quantity)
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first == name)
        {
            if (inventory[i].second + quantity > 64)
            {
                inventory[i].second = 64;
                add_item(name, quantity - 64);
            }
            else
            {
                inventory[i].second += quantity;
            }
            return;
        }
    }

    // adding new item
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first == "")
        {
            if (quantity > 64)
            {
                inventory[i].first = name;
                inventory[i].second = 64;
                add_item(name, quantity - 64);
            }
            else
            {
                inventory[i].first = name;
                inventory[i].second = quantity;
            }
            return;
        }
    }

    // if inventory is full
    cout << "Inventory is full" << endl;
}

void Inventory::remove_item(string name, int quantity)
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first == name)
        {
            inventory[i].second -= quantity;
            return;
        }
    }
}

void Inventory::display_inventory()
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first != "")
        {
            cout << inventory[i].first << ": " << inventory[i].second << endl;
        }
    }
}