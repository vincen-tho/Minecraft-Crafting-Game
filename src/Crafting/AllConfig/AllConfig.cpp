#include "AllConfig.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

AllConfig::AllConfig() {}

AllConfig::~AllConfig() {
  for (int i = 0; i < this->items.end() - this->items.begin(); i++) {
    delete this->items[i];
  }
}

void AllConfig::addRecipe(int *dimension, string **input, string output,
                          int output_q) {
  this->recipes.push_back(Recipe(dimension, input, output, output_q));
}

void AllConfig::addTool(string name, int quantity) {
  this->items.push_back(new Tool(name, quantity));
}

void AllConfig::addNonTool(string name, int quantity, string variety) {
  this->items.push_back(new NonTool(name, quantity, variety));
}

bool operator==(Item *i, string name) { return i->get_name() == name; }

bool operator==(string name, Item *i) { return i == name; }

int AllConfig::search_item_idx(string name) const {
  return find(this->items.begin(), this->items.end(), name) -
         this->items.begin();
}

Item* AllConfig::search_item(string name) const {
  int idx = this->search_item_idx(name);
  if (idx == this->items.end() - items.begin()) {
    return new Item();
  } else {
    return this->items[idx];
  }
}

int AllConfig::search_recipe_idx(CraftState &cs) const {
  return find(this->recipes.begin(), this->recipes.end(), cs) -
         this->recipes.begin();
}

Item* AllConfig::search_recipe(CraftState &cs) const {
  int idx = this->search_recipe_idx(cs);
  if (idx == this->recipes.end() - recipes.begin()) {
    Item* not_found = new Item();
    not_found->set_name("-");
    return not_found;
  } else {
    Item* i = this->search_item(this->recipes[idx].get_output());
    i->set_quantity(this->recipes[idx].get_output_q());
    return i;
  }
}
