#include "Crafting.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

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

int main() {
  Crafting Craft;
  load_recipes(Craft);
  Item STK = Item("STICK", "Non-Tool", 1);
  Item DIA = Item("DIAMOND", "Non-Tool", 1);
  Craft.add_item(DIA, 2);
  Craft.add_item(DIA, 1);
  Craft.add_item(DIA, 5);
  Craft.add_item(STK, 4);
  Craft.add_item(STK, 7);
  Craft.show();
  return 0;
}
