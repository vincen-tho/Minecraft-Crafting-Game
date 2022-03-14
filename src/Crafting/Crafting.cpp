#include "Crafting.hpp"
#include "AllRecipe/Recipe/Recipe.hpp"
#include "CraftState/CraftState.hpp"
#include <array>
#include <iostream>
using namespace std;

bool arr_check(string **recipe, Item **arr_item, array<int, 2> item_dim,
               array<int, 2> item_tl) {
  bool n_check = true; // Normal
  bool m_check = true; // Mirror
  for (int i = 0; i < item_dim[0]; i++) {
    for (int j = 0; j < item_dim[1]; j++) {
      n_check =
          n_check &&
          arr_item[item_tl[0] + i][item_tl[1] + j].get_name() == recipe[i][j];
      m_check =
          m_check && arr_item[item_tl[0] + i][item_tl[1] + j].get_name() ==
                         recipe[i][item_dim[1] - j - 1];
      /* if (arr_item[item_tl[0] + i][item_tl[1] + j].get_name() !=
       * recipe[i][j]) { */
      /*   n_check = false; */
      /* } */
    }
  }
  return n_check || m_check;
}
// Yang perlu di cek
//  - Kalau resep 3x3, cek keseluruhan
//  - Kalau tidak, apabila dimensi sama, cek
//    - Kalau beda false
bool operator==(const CraftState &cs, const Recipe &r) {
  bool recipe_3x3 = r.dimension[0] == 3 && r.dimension[1] == 3;
  if (!recipe_3x3) { // Resep bukan 3x3
    bool same_dim =
        cs.dimension[0] == r.dimension[0] && cs.dimension[1] == r.dimension[1];
    if (same_dim) { // Dimensinya sama
      return arr_check(r.input, cs.slot, cs.dimension, cs.top_left);
      /* for (int i = 0; i < r.dimension[0]; i++) { */
      /*   for (int j = 0; j < r.dimension[1]; j++) { */
      /*     if (cs.slot[cs.top_left[0] + i][cs.top_left[1] + j].get_name() !=
       */
      /*         r.input[i][j]) { */
      /*       return false; */
      /*     } */
      /*   } */
      /* } */
    } else {
      return false;
    }
    return false;
  } else { // Resep 3x3
    return arr_check(r.input, cs.slot, { 3, 3 }, { 0, 0 });
    /* for (int i = 0; i < 3; i++) { */
    /*   for (int j = 0; j < 3; j++) { */
    /*     if (cs.slot[i][j].get_name() != r.input[i][j]) { */
    /*       return false; */
    /*     } */
    /*   } */
    /* } */
  }
  return true;
}

bool operator==(const Recipe &r, const CraftState &cs) { return cs == r; }

Crafting::Crafting() {
  this->cs = new CraftState();
  this->output = "-";
}

void Crafting::show() const {
  this->cs->show();
  cout << "CAN CRAFT: " << this->output << endl;
}

void Crafting::add_item(Item i, int lokasi) {
  this->cs->addItem(i, lokasi);
  this->output = this->ar.search_item(*this->cs);
}

void Crafting::addRecipe(int *dimension, string **input, string output,
                         int output_q) {
  this->ar.addRecipe(dimension, input, output, output_q);
  this->output = this->ar.search_item(*this->cs);
}

/* Item Crafting::return_item(int lokasi){ */
/*     // Belum */
/* } */

/* Item craft(){ */
/**/
/* } */

void Crafting::refreshCraftState() {
  delete this->cs;
  this->cs = new CraftState();
  this->output = "-";
}
