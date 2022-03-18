#include "../lib.hpp"
#include <iostream>
#include <sstream>

using namespace std;

void showInventory(Inventory Inv){

  for(int i = 0; i < 27; i++){
    cout << Inv[i].first.get_name() << " : " << Inv[i].second << endl; 
  }

}


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
    
    istringstream sSrc(slotSrc);
    istringstream sDst(slotDest);
        
    sSrc >> typeSlotSrc >> idSlotSrc;
    sDst >> typeSlotDst >> idSlotDest;

    // CRAFT -> INVENTORY
    if(typeSlotSrc == 'C' && typeSlotDst == 'I' && slotQty == 1){
          
      // kembaliin item yang ada di slot craft
      // buat ngecek di lokasi itu ada itemnya atau engga
      // harusnya udah di handle di method return_item nya
      try{

        if(idSlotDest > 26){
          BaseException *E = new InvalidNumberException(idSlotDest);
          throw(E);
        }
        
        if(idSlotSrc > 8){
          BaseException *E = new InvalidNumberException(idSlotSrc);
          throw (E);
        }

        Item* temp = Craft.return_item(idSlotSrc);
        // method Inv.add_item nya perlu dimodifikasi jadi berdasarkan item, quantity, dan lokasi
        Inv.add_item(*temp, slotQty);

      }catch(BaseException *E){
        E->printMessage();
      }
         
    } else if (typeSlotSrc == 'I' && typeSlotDst == 'I' && slotQty == 1){

      // ISI BUAT YANG NUMPUK ITEM DI INVENTORY

    } 
  }
  // make drive_test TDIR=Crafting
  Craft.show();
  showInventory(Inv);

  return 0;
}
