#include "inventory.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

Inventory::Inventory()
{
    for (int i = 0; i < 27; i++)
    {
        inventory[i] = make_pair(new Item(), 0);
    }
}

// add item with maximum quantity 64
// if item quantity is greater than 64 then add item to the next available slot
void Inventory::add_item(int inventoryID, Item *item, int quantity)
{
    if (item->get_type() == "TOOL")
    {
        this->add_item(inventoryID, *dynamic_cast<Tool *>(item), quantity);
    }
    else if (item->get_type() == "NONTOOL")
    {
        this->add_item(inventoryID, *dynamic_cast<NonTool *>(item), quantity);
    }
}

void Inventory::add_item(Item *item, int quantity)
{
    if (item->get_type() == "TOOL")
    {
        this->add_item(*dynamic_cast<Tool *>(item), quantity);
    }
    else if (item->get_type() == "NONTOOL")
    {
        this->add_item(*dynamic_cast<NonTool *>(item), quantity);
    }
}

void Inventory::add_item(Tool item, int quantity)
{
    Item *t = new Tool(item);

    //dicari dulu item yang namanya sama
    int i = 0;
    while (quantity > 0 && i < 27)
    {
        if (inventory[i].first->get_name() == t->get_name() && inventory[i].second < 64)
        {
            if (inventory[i].second + quantity <= 64)
            {
                inventory[i].second += quantity;
                quantity = 0;
                return;
            }
            else
            {
                quantity -= 64 - inventory[i].second;
                inventory[i].second = 64;
                add_item(t, quantity);
                return;
            }
        }
        i++;
    }

    //jika tidak ada item yang sama
    i = 0;
    while (quantity > 0 && i < 27)
    {
        if (inventory[i].first->get_name() == "noname")
        {
            if (quantity <= 64)
            {
                inventory[i].first = t;
                inventory[i].second = quantity;
                quantity = 0;
                return;
            }
            else
            {
                quantity -= 64;
                inventory[i].first = t;
                inventory[i].second = 64;
            }
        }
        i++;
    }

    if (quantity > 0)
    {
        cout << "Inventory is full" << endl;
        cout << "Remaining Quantity: " << quantity << endl;
    }
}

void Inventory::add_item(NonTool item, int quantity)
{
    Item *nt = new NonTool(item);

    int i = 0;

    while (i < 27 && inventory[i].first->get_name() != "noname")
    {
        i++;
    }

    if (inventory[i].first->get_name() == "noname")
    {
        inventory[i].first = nt;
        inventory[i].second = quantity;
    }
    else
    {
        cout << "Inventory is full" << endl;
    }
}

void Inventory::add_item(int inventoryID, Tool item, int quantity)
{

    Item *nt = new Tool(item);

    if (inventory[inventoryID].first->get_name() != "noname")
    {
        cout << "Inventory slot is used" << endl;
    }
    else
    {
        inventory[inventoryID] = make_pair(nt, quantity);
    }
}

void Inventory::add_item(int inventoryID, NonTool item, int quantity)
{

    Item *nt = new NonTool(item);

    if ((inventory[inventoryID].first->get_name() != nt->get_name()) &&
        (inventory[inventoryID].first->get_name() != "noname"))
    {
        cout << "Inventory slot is used" << endl;
    }
    else if (inventory[inventoryID].first->get_name() == nt->get_name())
    {
        if (inventory[inventoryID].second + quantity > 64)
        {
            int temp = inventory[inventoryID].second;
            inventory[inventoryID].second = 64;

            int availID = inventoryID + 1;
            while (inventory[availID].first->get_name() != "noname")
            {
                availID++;
            }
            add_item(availID, nt, temp + quantity - 64);
        }
        else
        {
            inventory[inventoryID].second += quantity;
        }
    }
    else
    {
        inventory[inventoryID] = make_pair(nt, quantity);
    }
}

void Inventory::remove_item(Item *item, int quantity)
{
    for (int i = 0; i < 27; i++)
    {
        if (inventory[i].first->get_name() == item->get_name())
        {
            if (inventory[i].second - quantity == 0)
            {
                inventory[i] = make_pair(new Item(), 0);
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
    if (inventory[inventoryID].second - quantity == 0)
    {
        inventory[inventoryID] = make_pair(new Item(), 0);
    }
    else if (inventory[inventoryID].second - quantity < 0)
    {
        cout << "Not enough quantity" << endl;
    }
    else
    {
        inventory[inventoryID].second -= quantity;
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
    else if (inventory[srcID].first->get_type() == "TOOL" &&
             inventory[destID].first->get_name() != "noname")
    {
        cout << "Cannot stack tool" << endl;
    }
    else if (inventory[srcID].first->get_type() == "NONTOOL")
    {
        if (inventory[srcID].first->get_name() ==
            inventory[destID].first->get_name())
        {

            if (inventory[destID].second + inventory[srcID].second > 64)
            {
                int temp = 64 - inventory[destID].second;
                inventory[destID].second = 64;
                inventory[srcID].second -= temp;
            }
            else
            {
                inventory[destID].second += inventory[srcID].second;
                inventory[srcID] = make_pair(new Item(), 0);
            }
        }
        else
        {
            cout << "Cannot stack different item" << endl;
        }
    }
}

pair<Item *, int> Inventory::operator[](int i) const
{

    return this->inventory[i];
}

pair<Item *, int> &Inventory::operator[](int i) { return this->inventory[i]; }

void Inventory::display_inventory()
{
    int name_len = 0;
    int name_q = 0;
    int k = 0;
    array<int, 9> bufn = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    array<int, 9> bufq = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int pre_i = 0; pre_i < 27; pre_i++)
    {
        if (inventory[pre_i].first->get_name() == "noname")
        {
            name_len = 1;
        }
        else
        {
            name_len = inventory[pre_i].first->get_name().length();
        }
        name_q = floor(log10(inventory[pre_i].second)) + 1;
        if (name_len > bufn[pre_i % 9])
        {
            bufn[pre_i % 9] = name_len;
        }
        if (name_q > bufq[pre_i % 9])
        {
            bufq[pre_i % 9] = name_q;
        }
    }
    for (int i = 0; i < 27; i++)
    {
        /* inventory[i] = make_pair(new Item(), 0); */
        cout << "[I" << setw(2) << i << ": ";
        if (inventory[i].first->get_name() == "noname")
        {
            if (bufq[i % 9] > 0)
            {
                k = 2;
            }
            else
            {
                k = 0;
            }
            cout << setw(bufn[i % 9] + bufq[i % 9] + k) << "-"
                 << " ]";
        }
        else
        {
            cout << setw(bufn[i % 9]) << inventory[i].first->get_name() << "("
                 << setw(bufq[i % 9]) << inventory[i].second << ") ]";
        }
        if (i % 9 == 8)
        {
            cout << endl;
        }
    }
}
