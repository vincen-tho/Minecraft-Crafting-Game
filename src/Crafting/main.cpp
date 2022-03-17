#include "../lib.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  Crafting Craft;
  Inventory Inv;
  load_recipes(Craft);
  load_items(Craft);
  Tool T1("Tool 1", 4);
  Tool T2("Tool 1", 4);
  Craft.show();
  Craft.add_item(T1, 0);
  Craft.add_item(T2, 1);
  Craft.show();
  
  string command;
  cin >> command;
  if (command == "MOVE") {

    string slotSrc, slotDest;
    int idSlotSrc, idSlotDest;
    char typeSlotSrc, typeSlotDst;
    int slotQty;
    // need to handle multiple destinations
    cin >> slotSrc >> slotQty >> slotDest;
    // cout << "TODO" << endl;
    istringstream sSrc(slotSrc);
    istringstream sDst(slotDest);
        
    sSrc >> typeSlotSrc >> idSlotSrc;
    sDst >> typeSlotDst >> idSlotDest;

    if(typeSlotSrc == 'C' && typeSlotDst == 'I' && slotQty == 1){
          
      // kembaliin item yang ada di slot craft
      // Item t = Craft.return_item(idSlotSrc);
      // Inv.add_item(t, slotQty);
    }
  }
    
  

  Craft.show();
  // showInventory(Inv);

  return 0;
}
