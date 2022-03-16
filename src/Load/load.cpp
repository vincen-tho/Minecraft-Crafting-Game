#include "load.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

void load_items(Crafting& c){
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

  // read item from config file
  ifstream itemConfigFile(itemConfigPath);
  
  string ID, name, variant, toolType;
  
  while(itemConfigFile >> ID >> name >> variant >> toolType){
    if(toolType == "NONTOOL") {
      // construct item yang telah dibaca
      c.addNonTool(name, 10, variant);
    }else if (toolType == "TOOL"){
      // construct item yang telah dibaca
      c.addTool(name, 10);
    }
  }
  itemConfigFile.close();
}

void load_recipes(Crafting& c) {
  string configPath = "./config";
  // read recipes
  for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe")) {

    // read from file and do something
    ifstream recipeConfigFile(entry.path());

    int dimension[2];
    string crafted_item;
    int crafted_item_q;
    string line;
    string **input;

    // baca dimension
    recipeConfigFile >> dimension[0] >> dimension[1];
    // cout << dimension[0] << endl;
    getline(recipeConfigFile, line);

    // baca susunan crafting
    input = new string *[dimension[0]];
    for (int i = 0; i < dimension[0]; i++) {
      input[i] = new string[dimension[1]];
      getline(recipeConfigFile, line);
      int j = 0;
      istringstream ss(line);
      while (ss >> input[i][j]) {
        j++;
      }
    }

    // baca crafted_item_name dan crafted_item_quantity
    recipeConfigFile >> crafted_item >> crafted_item_q;

    // construct resep nya
    c.addRecipe(dimension, input, crafted_item, crafted_item_q);
  }
}