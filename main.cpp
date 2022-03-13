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
  
  string ID, name, type, toolType;
  int i = 0;
  
  while(itemConfigFile >> ID >> name >> type >> toolType){
    if(toolType == "NONTOOL") {
      cout << "TRUE" << endl;
      // construct item yang telah dibaca
    
    
    }else if (toolType == "TOOL"){
      cout << "FALSE" << endl;
      // construct item yang telah dibaca

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
