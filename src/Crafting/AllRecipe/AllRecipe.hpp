#ifndef __ALL_RECIPE_HPP__
#define __ALL_RECIPE_HPP__

#include "Recipe/Recipe.hpp"
#include <vector>
#include <string>
using namespace std;

class AllRecipe {
  // List Resep
private:
  vector<Recipe> recipes;

public:
  AllRecipe();

  // Menambahkan Recipe
  void addRecipe(int *dimension, string **input,
                 string output, int output_q);

  // Mencari item di recipes
  //
  // Input : Crafstate
  // Output: Lokasi resep di recipes, jika gak ada return -1
  int search_item_idx(CraftState &cs) const;

  string search_item(CraftState& cs) const;
};

#endif
