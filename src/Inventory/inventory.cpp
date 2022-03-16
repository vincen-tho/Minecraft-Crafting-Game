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

void Inventory::DISCARD(int inventoryID, int quantity){
    if (inventory[inventoryID].second - quantity < 0)
    {
        cout << "Not enough quantity" << endl;
        return;
    }
    else
    {
        inventory[inventoryID].second -= quantity;
        return;
    }
}

void Inventory:: MOVE(int srcID, int destID){
    if (inventory[srcID].second == 0)
    {
        cout << "No item to move" << endl;
        return;
    }
    else if (inventory[destID].second == 64)
    {
        cout << "Destination is full" << endl;
        return;
    }
    else if (inventory[destID].second + inventory[srcID].second > 64)
    {
        int temp = 64 - inventory[destID].second;
        inventory[destID].second = 64;
        inventory[srcID].second -= temp;
    }
    else
    {
        inventory[destID].second += inventory[srcID].second;
        inventory[srcID].second = 0;
    }
}

pair<Item, int> Inventory::operator[](int i) const {

    return this->inventory[i];

}

pair<Item, int>& Inventory::operator[](int i) {

    return this->inventory[i];

}

