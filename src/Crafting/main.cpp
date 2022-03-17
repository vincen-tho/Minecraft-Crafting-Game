#include "../lib.hpp"
#include <iostream>

using namespace std;

int main() {
  Crafting Craft;
  load_recipes(Craft);
  load_items(Craft);
  NonTool* STK2 = new NonTool("STICK", 1, "-");
  Tool T("A", 10);

  Craft.show();
  /* Craft.show(); */
  /* Craft.show(); */
  /* Craft.show(); */
  Craft.add_item(*STK2, 4);
  /* Craft.show(); */
  Craft.add_item(*STK2, 7);
  Craft.add_item(T, 0);
  Craft.show();

  STK2->displayInfo();
  T.displayInfo();
  Craft.return_item(0)->displayInfo();
  /* Craft.show(); */

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
