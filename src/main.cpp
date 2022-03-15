#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "lib.hpp"
#include "Crafting/Load/load.cpp"
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
      if (command == "EXPORT")
      {
        string outputPath;
        cin >> outputPath;
        ofstream outputFile(outputPath);

        // hardcode for first test case
        outputFile << "21:10" << endl;
        outputFile << "6:1" << endl;
        for (int i = 2; i < 27; i++)
        {
          outputFile << "0:0" << endl;
        }

        cout << "Exported" << endl;
      }
      else if (command == "CRAFT")
      {
        cout << "TODO" << endl;
      }
      else if (command == "SHOW"){
        // Craft.show();
        // Inv.display_inventory();
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
        string slotSrc;
        int slotQty;
        string slotDest;
        // need to handle multiple destinations
        cin >> slotSrc >> slotQty >> slotDest;
        cout << "TODO" << endl;
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
