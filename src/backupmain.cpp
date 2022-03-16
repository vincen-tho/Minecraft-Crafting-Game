// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "lib.hpp"
/* #include "Item.cpp" */
/* #include "Crafting.cpp" */
/* #include "inventory.cpp" */

using namespace std;

// int main() {
//   string configPath = "./config";
//   string itemConfigPath = configPath + "/item.txt";

//   // read item from config file
//   ifstream itemConfigFile(itemConfigPath);
  
//   string ID, name, variant, toolType;
//   int i = 0;
//   int j = 0;
//   Tool tool[12];
//   NonTool nontool[12];
  
//   while(itemConfigFile >> ID >> name >> variant >> toolType){
//     if(toolType == "NONTOOL") {
//       // construct item yang telah dibaca
//       nontool[i].set_name(name);
//       nontool[i].set_quantity(10);
//       nontool[i].set_type("NONTOOL");
//       if(variant != "-") {
//         nontool[i].set_variant(variant);
//       }
//       i++;
//     }else if (toolType == "TOOL"){
//       // construct item yang telah dibaca
//       tool[j].set_name(name);
//       tool[j].set_quantity(10);
//       tool[j].set_durability(10);
//       tool[j].set_type("TOOL");
//       j++;
//     }
//   }
//   itemConfigFile.close();

//   // for (string line; getline(itemConfigFile, line);) {
   
//   // }

//   // Inisialisasi crafting nya

//   Crafting c;
//   // read recipes
//   for (const auto &entry :
//        filesystem::directory_iterator(configPath + "/recipe")) {

//     // read from file and do something
//     ifstream recipeConfigFile(entry.path());

//     int dimension[2];
//     string crafted_item;
//     int crafted_item_q;
//     string line;
//     string **input;

//     // baca dimension
//     recipeConfigFile >> dimension[0] >> dimension[1];
//     // cout << dimension[0] << endl;
//     getline(recipeConfigFile, line);
    
//     //baca susunan crafting
//     input = new string *[dimension[0]];
//     for(int i = 0; i < dimension[0]; i++){
//       input[i] = new string [dimension[1]];
//       getline(recipeConfigFile, line);
//       int j = 0;
//       istringstream ss(line);
//       while(ss >> input[i][j]){
//         j++;
//       }
//     }
    
//     // baca crafted_item_name dan crafted_item_quantity
//     recipeConfigFile >> crafted_item >> crafted_item_q;

//     // construct resep nya
//     c.addRecipe(dimension, input, crafted_item, crafted_item_q);
    
//   }

//   // sample interaction
//   string command;
//   while (cin >> command) {
//     if (command == "EXPORT") {
//       string outputPath;
//       cin >> outputPath;
//       ofstream outputFile(outputPath);

//       // hardcode for first test case
//       outputFile << "21:10" << endl;
//       outputFile << "6:1" << endl;
//       for (int i = 2; i < 27; i++) {
//         outputFile << "0:0" << endl;
//       }

//       cout << "Exported" << endl;
//     } else if (command == "CRAFT") {
//       cout << "TODO" << endl;
//     } else if (command == "GIVE") {
//       string itemName;
//       int itemQty;
//       cin >> itemName >> itemQty;
//       cout << "TODO" << endl;
//     } else if (command == "MOVE") {
//       string slotSrc;
//       int slotQty;
//       string slotDest;
//       // need to handle multiple destinations
//       cin >> slotSrc >> slotQty >> slotDest;
//       cout << "TODO" << endl;
//     } else {
//       // todo
//       cout << "Invalid command" << endl;
//     }
//   }
//   return 0;
// }
