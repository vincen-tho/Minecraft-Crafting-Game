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
// if item quantity is greater than 64 then add item to the next available slot
void Inventory::add_item(int inventoryID, Item item, int quantity)
{
    if ((inventory[inventoryID].first.get_name() != item.get_name()) && (inventory[inventoryID].first.get_name() != "noname"))
    {
        cout << "Inventory slot is used" << endl;
    }
    else if (inventory[inventoryID].first.get_name() == item.get_name())
    {
        if (inventory[inventoryID].second + quantity > 64)
        {
            int temp = inventory[inventoryID].second;
            inventory[inventoryID].second = 64;

            int availID = inventoryID + 1;
            while (inventory[availID].first.get_name() != "noname")
            {
                availID++;
            }
            add_item(availID, item, temp + quantity - 64);
        }
        else
        {
            inventory[inventoryID].second += quantity;
        }
    }
    else
    {
        inventory[inventoryID] = make_pair(item, quantity);
    }
}

void Inventory::remove_item(Item item, int quantity)
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first.get_name() == item.get_name())
        {
            if (inventory[i].second - quantity == 0)
            {
                inventory[i] = make_pair(Item(), 0);
                return;
            }
            else if (inventory[i].second - quantity < 0)
            {
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

void Inventory::DISCARD(int inventoryID, int quantity)
{
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

void Inventory::MOVE(int srcID, int destID)
{
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

pair<Item, int> Inventory::operator[](int i) const
{

    return this->inventory[i];
}

pair<Item, int> &Inventory::operator[](int i)
{

    return this->inventory[i];
}
