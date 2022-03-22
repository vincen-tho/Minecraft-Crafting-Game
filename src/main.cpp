#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
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
  load_items(Craft);   // Load Items

  string command;
  while (cin >> command)
  {
    try
    { 
      if (command == "CRAFT")
      {
        cout << "TODO" << endl;
        /* if(Craft.canCraft()){ */
        /*     // Gak tau mau return ke mana */
        /*     // Craft.craft(); */
        /* } else { */
        /*     BaseException* E = new NoRecipe(); */
        /*     throw(E); */
        /* } */

        //SOME EXCEPTIONS, change parameters as you desire

        //Items dalam crafting tidak membuat recipe
        //BaseException *E = new NoRecipe();
        //throw(E);

      }
      else if (command == "DISCARD")
      {
        string slotSrc;
        int idSlotSrc;
        char typeSlotSrc;
        int itemQty;

        cin >> slotSrc >> itemQty;
        istringstream sSrc(slotSrc);
        
        sSrc >> typeSlotSrc >> itemQty;


        if(typeSlotSrc == 'I'){
          if (itemQty <= 0)
          {
            BaseException *E = new InvalidNumberException(itemQty);
            throw(E);
          }
          else if (itemQty > Inv[idSlotSrc].first->get_quantity())
          {
              BaseException *E = new InputGreaterException(itemQty,Inv[idSlotSrc].first->get_quantity());
              throw (E);
          }
          else if (Inv[idSlotSrc].first->get_name() == "noname"){
            //NO ITEM EXCEPTION
            BaseException *E = new NoItemInventoryException(idSlotSrc);
            throw(E);
        }
          {
              Inv.DISCARD(idSlotSrc,itemQty);
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
        
        cout << "Input path file export : " ;
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
        else if (/*TODO: Verify if ITEM_NAME IS VALID*/ true)
        {
          BaseException *E = new ItemNameException(itemName);
        }
        else
        {
          // Inv.add_item(itemName, itemQty); // TODO: CHANGE WHEN VIHO CHANGES THIS
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

            Item* temp = Craft.return_item(idSlotSrc);
            Inv.add_item(idSlotDest, temp, slotQty);
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
            if(slotQty > Inv[idSlotSrc].first->get_quantity()){
                BaseException *E = new InputGreaterException(slotQty,Inv[idSlotSrc].first->get_quantity());
                throw (E);
            }
            if(typeSlotDst == 'C'){
              if(idSlotDest > 8){
                BaseException *E = new InvalidNumberException(idSlotDest);
                throw(E);
              }
              Item* temp = Inv[idSlotSrc].first;
              Craft.add_item(temp,idSlotDest);
              Inv.remove_item(temp,1);
            }
          }
        }
        //SOME EXCEPTIONS, change parameters as you desire

        //NO ITEM EXCEPTION (use this kalo inventory/crafting slot yg mau dipindah empty)
        //BaseException *E = new NoItemInventoryException(INVENTORY_SLOT_ID);
        //throw(E);
        //BaseException *E = new NoItemCraftingException(INVENTORY_SLOT_ID);
        //throw(E);

        //TRYING TO STACK DIFFERENT ITEMS EXCEPTION
        //BaseException *E = new DifferentItemStackException(ItemName1,ItemName2);
        //throw(E);

        //TRYING TO STACK TOOL EXCEPTION
        //BaseException *E = new ToolStackingException();
        //throw(E);
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
            Inv[invID].first->set_durability(Inv[invID].first->get_durability()-1);
          }else{
            //NOT TOOL EXCEPTION
            BaseException *E = new NotToolException(invID);
            throw(E);
          }
        }
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
