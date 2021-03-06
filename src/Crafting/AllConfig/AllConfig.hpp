#ifndef __ALL_RECIPE_HPP__
#define __ALL_RECIPE_HPP__

#include "Recipe/Recipe.hpp"
#include "../../Item/Item.h"
#include <utility>
#include <vector>
#include <string>
using namespace std;

class AllConfig {
  // List Resep
private:
  vector<Recipe> recipes;
  vector<Item*> items;

public:
  AllConfig();
  ~AllConfig();

  // Menambahkan Recipe
  void addRecipe(int *dimension, string **input,
                 string output, int output_q);

  void addTool(int ID, string name);
  void addNonTool(int ID, string name, string variety);
  int search_item_idx(string name) const;
  Item* search_item(string name) const;

  // Mencari item di recipes
  //
  // Input : Crafstate
  // Output: Lokasi resep di recipes, jika gak ada return -1
  int search_recipe_idx(CraftState &cs) const;

  pair<Item*, int> search_recipe(CraftState& cs) const;
};

#endif
