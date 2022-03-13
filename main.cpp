// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>

#include "Item.cpp"

using namespace std;

int main() {
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

  // read item from config file
  ifstream itemConfigFile(itemConfigPath);
  
  string ID, name, variant, toolType;
  int i = 0;
  int j = 0;
  Tool tool[12];
  NonTool nontool[12];
  while(itemConfigFile >> ID >> name >> variant >> toolType){
    if(toolType == "NONTOOL") {
      // cout << "TRUE" << endl;
      // construct item yang telah dibaca
      nontool[i].set_name(name);
      nontool[i].set_quantity(10);
      if(variant != "-") {
        nontool[i].set_variant(variant);
      }
      nontool[i].displayInfo();
      i++;

    }else if (toolType == "TOOL"){
      // cout << "FALSE" << endl;
      // construct item yang telah dibaca
      tool[j].set_name(name);
      tool[j].set_quantity(10);
      tool[j].set_durability(10);
      tool[j].displayInfo();
      j++;
    }
  }
  itemConfigFile.close();

  // for (string line; getline(itemConfigFile, line);) {
   
  // }

  // // read recipes
  // for (const auto &entry :
  //      filesystem::directory_iterator(configPath + "/recipe")) {
  //   cout << entry.path() << endl;
  //   // read from file and do something
  // }

  // sample interaction
  string command;
  while (cin >> command) {
    if (command == "EXPORT") {
      string outputPath;
      cin >> outputPath;
      ofstream outputFile(outputPath);

      // hardcode for first test case
      outputFile << "21:10" << endl;
      outputFile << "6:1" << endl;
      for (int i = 2; i < 27; i++) {
        outputFile << "0:0" << endl;
      }

      cout << "Exported" << endl;
    } else if (command == "CRAFT") {
      cout << "TODO" << endl;
    } else if (command == "GIVE") {
      string itemName;
      int itemQty;
      cin >> itemName >> itemQty;
      cout << "TODO" << endl;
    } else if (command == "MOVE") {
      string slotSrc;
      int slotQty;
      string slotDest;
      // need to handle multiple destinations
      cin >> slotSrc >> slotQty >> slotDest;
      cout << "TODO" << endl;
    } else {
      // todo
      cout << "Invalid command" << endl;
    }
  }
  return 0;
}
