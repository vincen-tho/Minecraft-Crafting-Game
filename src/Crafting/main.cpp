#include "../lib.hpp"
#include <iostream>

using namespace std;

int main() {
  Crafting Craft;
  load_recipes(Craft);
  load_items(Craft);
  Tool T1("Tool 1", 4);
  Tool T2("Tool 1", 4);
  Craft.show();
  Craft.add_item(T1, 0);
  Craft.add_item(T2, 1);
  Craft.show();
  return 0;
}
