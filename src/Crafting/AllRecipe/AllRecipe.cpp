#include "AllRecipe.hpp"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

AllRecipe::AllRecipe() {
  this->recipes = vector<Recipe>();
}

void AllRecipe::addRecipe(int *dimension, string **input, string output,
                          int output_q) {
    cout << "Adding Recipe for " << output << endl;
    this->recipes.push_back(Recipe(dimension, input, output, output_q));
}

int AllRecipe::search_item_idx(CraftState &cs) const{
    return find(this->recipes.begin(), this->recipes.end(), cs) - this->recipes.begin();
}

string AllRecipe::search_item(CraftState &cs) const {
    int idx = this->search_item_idx(cs);
    if(idx == this->recipes.end() - recipes.begin()){
        return "-";
    } else {
        return this->recipes[idx].get_output();
    }
}
