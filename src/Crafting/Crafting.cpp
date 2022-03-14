#include "Crafting.hpp"
using namespace std;

bool operator==(const CraftState &cs, const Recipe &r) {
  if (cs.dimension[0] != r.dimension[0] || cs.dimension[1] != r.dimension[1]) {
    return false;
  } else { // Dimensi-nya sama
    for (int i = 0; i < r.dimension[0]; i++) {
      for (int j = 0; j < r.dimension[1]; j++) {
        if (cs.slot[cs.top_left[0] + i][cs.top_left[1] + j].get_name() != r.input[i][j]) {
          return false;
        }
      }
    }
  }
  return true;
}

bool operator==(const Recipe &r, const CraftState &cs) { return cs == r; }

Crafting::Crafting(){
    this->cs = new CraftState();
    this->output = "-";
}

void Crafting::show() const {
    this->cs->show();
}

void Crafting::add_item(Item i, int lokasi){
    this->cs->addItem(i, lokasi);
}

void Crafting::addRecipe(int *dimension, string **input,
        string output, int output_q){
    this->ar.addRecipe(dimension, input, output, output_q);
    this->output = this->ar.search_item(*this->cs);
}

/* Item Crafting::return_item(int lokasi){ */
/*     // Belum */
/* } */

/* Item craft(){ */
/**/
/* } */

void Crafting::refreshCraftState(){
    delete this->cs;
    this->cs = new CraftState();
    this->output = "-";
}
