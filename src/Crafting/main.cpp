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
  Tool T1("Tool 112371093710273091730", 4);
  Tool T2("Tool 1", 4);
  NonTool OAK("OAK_LOG", 10, "-");
  /* Craft.show(); */
  Craft.add_item(OAK, 0);

  /* Craft.show(); */
  
  Craft.show();
  /* showInventory(Inv); */
  /* // Move  */
  /* Inv.add_item(1, T1, 10); */
  /* Item* temp = Inv[1].first; */
  /* Craft.add_item(temp,2); */
  /* Inv.remove_item(temp,1); */
  /* Craft.show(); */
  /* showInventory(Inv); */

  return 0;
}
