#include "../lib.hpp"
#include <iostream>
#include <sstream>


int main() {
  Crafting Craft;
  Inventory Inv;
  load_recipes(Craft);
  load_items(Craft);
  Tool T1("Tool 1", 4);
  Tool T2("Tool 1", 4);
  Inv.add_item(2,T1,2);
  Inv.add_item(3,T2,3);
  Inv.display_inventory();
  Craft.show();
  Craft.add_item(T1, 0);
  Craft.add_item(T2, 1);
  Craft.show();
}