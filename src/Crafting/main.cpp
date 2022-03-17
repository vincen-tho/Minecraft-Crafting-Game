#include "../lib.hpp"
#include <iostream>

using namespace std;

int main() {
  Crafting Craft;
  load_recipes(Craft);
  load_items(Craft);
  Item STK = Item("STICK", "Non-Tool", 1);
  Item DIA = Item("DIAMOND", "Non-Tool", 1);
  Item BLG = Item("BIRCH_LOG", "Non-Tool", 1);
  Item SLG = Item("SPRUCE_LOG", "Non-Tool", 1);

  Craft.show();
  Craft.add_item(DIA, 2);
  /* Craft.show(); */
  Craft.add_item(DIA, 1);
  /* Craft.show(); */
  Craft.add_item(DIA, 0);
  /* Craft.show(); */
  Craft.add_item(STK, 4);
  /* Craft.show(); */
  Craft.add_item(STK, 7);
  Craft.show();
  Craft.return_item(0);
  Craft.show();

  /* Craft.refreshCraftState(); */
  /* Craft.add_item(DIA, 0); */
  /* Craft.add_item(DIA, 1); */
  /* Craft.add_item(DIA, 3); */
  /* Craft.add_item(STK, 4); */
  /* Craft.add_item(STK, 7); */
  /* Craft.show(); */
  /**/
  /* Craft.refreshCraftState(); */
  /* Craft.add_item(BLG, 0); */
  /* Craft.show(); */
  /**/
  /* Craft.refreshCraftState(); */
  /* Craft.add_item(SLG, 8); */
  /* Craft.show(); */
  return 0;
}
