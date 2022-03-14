#include "AllRecipe.hpp"
#include <algorithm>
#include <vector>

using namespace std;

AllRecipe::AllRecipe() {
  this->recipes = vector<Recipe>();
}

void AllRecipe::addRecipe(int *dimension, string **input, string output,
                          int output_q) {
    this->recipes.push_back(Recipe(dimension, input, output, output_q));
}

int AllRecipe::search_item(CraftState &cs) const{
    return find(this->recipes.begin(), this->recipes.end(), cs) - this->recipes.begin();
}
