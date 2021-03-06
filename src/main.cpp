#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <utility>
#include <vector>
#include <sstream>

#include "Exception/Exception.hpp"
#include "lib.hpp"

using namespace std;

int main()
{
  Inventory Inv;
  Crafting Craft;
  load_recipes(Craft); // Load Recipes
  load_items(Craft);
  
     // Load Items

  // Banner
  cout << "           __                                    ___  __        " << endl;
  cout << ".--------.|__|.-----..-----..----..----..---.-..'  _||  |_      " << endl;
  cout << "|        ||  ||     ||  -__||  __||   _||  _  ||   _||   _|     " << endl; 
  cout << "|__|__|__||__||__|__||_____||____||__|  |___._||__|  |____|     " << endl; 
  cout << "                     ___  __    __                              " << endl;
  cout << ".----..----..---.-..'  _||  |_ |__|.-----..-----.               " << endl;
  cout << "|  __||   _||  _  ||   _||   _||  ||     ||  _  |               " << endl;       
  cout << "|____||__|  |___._||__|  |____||__||__|__||___  |               " << endl;
  cout << ".-----..---.-..--------..-----.           |_____|               " << endl;     
  cout << "|  _  ||  _  ||        ||  -__|                                 " << endl;
  cout << "|___  ||___._||__|__|__||_____|                                 " << endl;
  cout << "|_____|                                                         " << endl;      
  cout << endl;
             
  string command;
  
  while (command != "EXIT")
  {
    cout << "ENTER COMMAND : " ;
    cin >> command;
    try
    { 
      if (command == "CRAFT")
      {
        // cout << "TODO" << endl;
        
        if(Craft.canCraft()){
          // Gak tau mau return ke mana
          /* Item *resultItem = Craft.craft(); */
          pair<Item*, int> resultItem = Craft.CRAFT();
          Inv.add_item(resultItem.first, resultItem.second);
          cout << "Item berhasil dicraft" <<endl;
        } else {
          BaseException* E = new NoRecipe();
          throw(E);
        }

      }
      else if (command == "DISCARD")
      {
        string slotSrc;
        int idSlotSrc;
        char typeSlotSrc;
        int itemQty;

        cin >> slotSrc >> itemQty;
        istringstream sSrc(slotSrc);
        
        sSrc >> typeSlotSrc >> idSlotSrc;


        if(typeSlotSrc == 'I'){
          
          
          if (itemQty <= 0)
          {
            BaseException *E = new InvalidNumberException(itemQty);
            throw(E);
          }
          else if (Inv[idSlotSrc].first->get_name() == "noname"){
            //NO ITEM EXCEPTION
            BaseException *E = new NoItemInventoryException(idSlotSrc);
            throw(E);
          }
          else if (itemQty > Inv[idSlotSrc].second){
              BaseException *E = new InputGreaterException(itemQty,Inv[idSlotSrc].second);
              throw (E);
          } else {
            Inv.DISCARD(idSlotSrc,itemQty);
            cout << "Item berhasil dibuang" <<endl;
          }
        }
        else{
          BaseException *E = new InvalidInputException<string>(slotSrc);
          throw (E);
        }
      }
      else if (command == "EXPORT")
      {
        string exportPath = "./";
        string outputPath;
        
        cin >> outputPath;
        
        ofstream outputFile(exportPath + outputPath);
        
        for (int i = 0; i < 27; i++)
        {
          if(Inv[i].first->get_type() == "NONTOOL") {

            outputFile << Inv[i].first->get_ID() << ":" << Inv[i].second;

          }
          else if (Inv[i].first->get_type() == "TOOL") {
            // masih belum tahu cara akses durability dari item nya
            outputFile << Inv[i].first->get_ID() << ":" << Inv[i].first->get_durability();
          
          }else if(Inv[i].first->get_type() == "notype"){
            
            outputFile << 0 << ":" << 0;
          
          }

          if (i < 26){
            outputFile << endl;
          }
          
        }

        cout << "Exported" << endl;
      }
      else if (command == "GIVE")
      {
        string itemName;
        int itemQty;
        cin >> itemName >> itemQty;
        if (itemQty <= 0)
        {
          BaseException *E = new InvalidNumberException(itemQty);
          throw(E);
        }
        else
        {
          Item *newItem = Craft.searchItem(itemName);
          Inv.add_item(newItem, itemQty); // TODO: CHANGE WHEN VIHO CHANGES THIS
          cout << "Item berhasil ditambahkan" <<endl;
        }
      }
      else if (command == "MOVE")
      {
        string slotSrc, slotDest;
        int idSlotSrc, idSlotDest;
        char typeSlotSrc, typeSlotDst;
        int slotQty;
        // need to handle multiple destinations
        cin >> slotSrc >> slotQty;
        // cout << "TODO" << endl;
        istringstream sSrc(slotSrc);
        
        
        sSrc >> typeSlotSrc >> idSlotSrc;
        
        // MOVE dari crafting slot ke inventory
        // MOVE dari crafting slot ke inventory quantity nya harus 1
        if(typeSlotSrc == 'C'){
          cin>>slotDest;
          istringstream sDst(slotDest);
          sDst >> typeSlotDst >> idSlotDest;
          if( typeSlotDst == 'I' && slotQty == 1){
            if(idSlotDest > 26){
              BaseException *E = new InvalidNumberException(idSlotDest);
              throw(E);
            }
          
            if(idSlotSrc > 8){
              BaseException *E = new InvalidNumberException(idSlotSrc);
              throw (E);
            }

            if(Craft.at(idSlotSrc).first->get_name() == "noname"){
              BaseException *E = new NoItemCraftingException(idSlotSrc);
              throw(E);
            }
            pair<Item*, int> tmp = Craft.ret_item(slotQty, idSlotSrc);

            if(Inv[idSlotDest].first->get_name() == tmp.first->get_name() && Inv[idSlotDest].second + tmp.second <= 64) {
              
              Inv.add_item(idSlotDest, tmp.first, tmp.second);
              cout << "Item berhasil dipindahkan" << endl;
            
            }else if(Inv[idSlotDest].first->get_name() == "noname"){

              Inv.add_item(idSlotDest, tmp.first, tmp.second);
              cout << "Item berhasil dipindahkan" << endl;
            } else {

              Craft.add_item(tmp.first, tmp.second, idSlotSrc);
              cout << "Item berhasil dipindahkan" << endl;
            }
            
          }
        } 
        else if (typeSlotSrc == 'I'){
          if(idSlotSrc > 26){
                BaseException *E = new InvalidNumberException(idSlotSrc);
                throw (E);
              }
          for (int i=0; i<slotQty; i++){
            cin>>slotDest;
            istringstream sDst(slotDest);
            sDst >> typeSlotDst >> idSlotDest;
            
            if (Inv[idSlotSrc].first->get_name() == "noname"){
            //NO ITEM EXCEPTION
                  int sisa = slotQty - i-1;
                                for (int j=0; j < sisa; j++ ){
                                  cin>>slotDest; 
                                }
              BaseException *E = new NoItemInventoryException(idSlotSrc);
              throw(E);
            
            } else if(slotQty - i > Inv[idSlotSrc].second){
                int sisa = slotQty - i-1;
                              for (int j=0; j < sisa; j++ ){
                                cin>>slotDest; 
                              }
              BaseException *E = new InputGreaterException(slotQty,Inv[idSlotSrc].second);
              throw (E);
            
            }
            if(typeSlotDst == 'C'){
              if(idSlotDest > 8){
                int sisa = slotQty - i-1;
              for (int j=0; j < sisa; j++ ){
                cin>>slotDest; 
              }

                BaseException *E = new InvalidNumberException(idSlotDest);
                throw(E);
              }

               if(Craft.at(idSlotDest).first->get_name() != Inv[idSlotSrc].first->get_name() && Craft.at(idSlotDest).first->get_name() != "noname")
                {
                  BaseException *E = new DifferentItemStackException(Craft.at(idSlotDest).first->get_name(),Inv[idSlotSrc].first->get_name());
                  throw(E);
                }

              Item* temp = Inv[idSlotSrc].first;
              Craft.add_item(temp,1, idSlotDest);
              Inv.remove_item(temp,1);
              cout << "Item berhasil dipindahkan" << endl;
            }else if(typeSlotDst == 'I'){

              Inv.MOVE(idSlotSrc, idSlotDest);
              cout << "Item berhasil dipindahkan" << endl;
            }
          }
        }
    
      }
      else if (command == "SHOW")
      {
         Craft.show();
         Inv.display_inventory();
      }
      else if (command == "USE")
      { 
        string slotInv;
        int invID;
        char type;

        cin >> slotInv;
        istringstream sInv(slotInv);
        sInv >> type >> invID;
        //SOME EXCEPTIONS, change parameters as you desire

        if (Inv[invID].first->get_name() == "noname"){
          //NO ITEM EXCEPTION
          BaseException *E = new NoItemInventoryException(invID);
          throw(E);
        }
        else{
          if(Inv[invID].first->get_type() == "TOOL"){
            
            if(Inv[invID].first->get_durability()-1 > 0){

              Inv[invID].first->set_durability(Inv[invID].first->get_durability()-1);
              cout << "Item berhasil digunakan, Durability: "<< Inv[invID].first->get_durability() << endl;
            }else{

              Inv.remove_item(Inv[invID].first, 1);
              cout << "Item berhasil digunakan, Durability habis, item hilang" <<endl;
            }
            
            
          }else{
            //NOT TOOL EXCEPTION
            BaseException *E = new NotToolException(invID);
            throw(E);
          }
        }
      }
      else if(command == "HELP"){
        cout << "1. SHOW " << endl;
        cout << "2. GIVE <Item_Name> <Item_Quantity> " << endl;
        cout << "3. DISCARD <Inventory_Slot_ID> <Item_Quantity> " << endl;
        cout << "4. MOVE <craft_slot_id> 1 <inventory_slot_id>" << endl;
        cout << "5. MOVE <inventory_slot_id> 1 <inventory_slot_id>" << endl;
        cout << "6. MOVE <inventory_slot_id> N <craft_slot_id_0> <craft_slot_id_N>" << endl;
        cout << "7. USE <Inventory_Slot_ID> " << endl;
        cout << "8. CRAFT" << endl;
        cout << "9. EXPORT <path_file>" << endl;

      }
      else if(command == "EXIT"){
        cout << "Byebye" << endl;
      }
      else
      {
        // todo
        cout << "Invalid command: " << command << endl;
      }
    }
    catch (BaseException *ex)
    {
      ex->printMessage();
    }
  }
  return 0;
}
