#include "../lib.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void showInventory(Inventory Inv){

  for(int i = 0; i < 27; i++){
    cout << Inv[i].first->get_name() << " : " << Inv[i].second << endl; 
  }

}


int main() {
  Crafting Craft;
  Inventory Inv;
  load_recipes(Craft);
  load_items(Craft);
  Item* i = Craft.search_item("OAK_PLANK");
  NonTool NT("aowuvuiavwdivaduvawdka", 63, "-");
  /* Craft.show(); */
  Craft.add_item(i, 0);
  Craft.add_item(i, 3);

  /* Craft.show(); */
  
  Craft.show();
  /* showInventory(Inv); */
  /* // Move  */
  Inv.add_item(1, i, 10);
  Inv.display_inventory();
  /* Item* temp = Inv[1].first; */
  /* Craft.add_item(temp,2); */
  /* Inv.remove_item(temp,1); */
  /* Craft.show(); */
  /* showInventory(Inv); */

  return 0;
}
