#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "lib.hpp"
#include "Load/load.hpp"
#include "Exception/Exception.hpp"

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

        //SOME EXCEPTIONS, change parameters as you desire

        //Items dalam crafting tidak membuat recipe
        //BaseException *E = new NoRecipe();
        //throw(E);

      }
      else if (command == "DISCARD")
      {
        //SOME EXCEPTIONS, change parameters as you desire

        //NO ITEM EXCEPTION
        //BaseException *E = new NoItemInventoryException(INVENTORY_SLOT_ID);
        //throw(E);

        //Exception kalau itemQty <= 0 
        //BaseException *E = new InvalidNumberException<int>(itemQty);
        //throw(E);

        //Should i make an exception if itemQty > Quantity yang ada?, ato kalo lebih interactionnya sama kalau ke delete total?
      }
      else if (command == "EXPORT")
      {
        string exportPath = "./export/";
        string outputPath;
        
        cout << "Input path file export : " ;
        cin >> outputPath;
        
        ofstream outputFile(exportPath + outputPath);
        
        for (int i = 0; i < 27; i++)
        {
          if(Inv[i].first.get_type() == "NONTOOL") {

            outputFile << Inv[i].first.get_ID() << ":" << Inv[i].second << endl;

          } else if (Inv[i].first.get_type() == "TOOL") {
            // masih belum tahu cara akses durability dari item nya
            // outputFile << Inv[i].first.get_ID() << ":" << Inv[i].first.get_durability() << endl;
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
          BaseException *E = new InvalidNumberException<int>(itemQty);
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
        string slotSrc;
        int slotQty;
        string slotDest;
        // need to handle multiple destinations
        cin >> slotSrc >> slotQty >> slotDest;
        cout << "TODO" << endl;

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
        //BaseException *E = new ToolStackException();
        //throw(E);


      }
      else if (command == "SHOW")
      {
        // Craft.show();
        // Inv.display_inventory();
      }
      else if (command == "USE")
      { 
        //SOME EXCEPTIONS, change parameters as you desire

        //NOT TOOL EXCEPTION
        //BaseException *E = new NotToolException(INVENTORY_SLOT_ID);
        //throw(E);

        //NO ITEM EXCEPTION
        //BaseException *E = new NoItemInventoryException(INVENTORY_SLOT_ID);
        //throw(E);
      }
      else
      {
        // todo
        cout << "Invalid command" << endl;
      }
    }
    catch (BaseException *ex)
    {
      ex->printMessage();
    }
  }
  return 0;
}
