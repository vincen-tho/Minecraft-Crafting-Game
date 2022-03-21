#include "Crafting.hpp"
#include "AllConfig/Recipe/Recipe.hpp"
#include "CraftState/CraftState.hpp"
#include <array>
#include <iostream>
using namespace std;

bool arr_check(string **recipe, Item ***arr_item, array<int, 2> item_dim,
               array<int, 2> item_tl) {
  bool n_check = true; // Normal
  bool m_check = true; // Mirror
  for (int i = 0; i < item_dim[0]; i++) {
    for (int j = 0; j < item_dim[1]; j++) {
      n_check =
          n_check &&
          arr_item[item_tl[0] + i][item_tl[1] + j]->get_name() == recipe[i][j];
      m_check =
          m_check && arr_item[item_tl[0] + i][item_tl[1] + j]->get_name() ==
                         recipe[i][item_dim[1] - j - 1];
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
    } else {
      return false;
    }
    return false;
  } else { // Resep 3x3
    return arr_check(r.input, cs.slot, {3, 3}, {0, 0});
  }
  return true;
}

bool operator==(const Recipe &r, const CraftState &cs) { return cs == r; }

Crafting::Crafting() {
  this->cs = new CraftState();
  this->output = new Item();
  this->output->set_name("-");
}

void Crafting::show() const {
  this->cs->show();
  if (this->output->get_name() == "-") {
    cout << "CAN CRAFT: " << output->get_name() << " x"
         << output->get_quantity() << endl;
  } else {
    cout << "CAN CRAFT: " << endl;
    this->output->displayInfo();
  }
}

void Crafting::refreshOutput() {
  array<int, 2> ToolLoc = this->cs->dur_add_check();
  if (ToolLoc == array<int, 2>{-1, -1}) {
    this->output = this->ac.search_recipe(*this->cs);
  } else {
    this->output = this->cs->add_tool(ToolLoc);
  }
}

void Crafting::add_item(NonTool i, int lokasi) {
  Item *nt = new NonTool(i);
  this->cs->addItem(nt, lokasi);
  this->refreshOutput();
}

void Crafting::add_item(Tool i, int lokasi) {
  Item *t = new Tool(i);
  this->cs->addItem(t, lokasi);
  this->refreshOutput();
}

void Crafting::add_item(Item* i, int lokasi) {
    if(i->get_type() == "TOOL"){
        this->add_item(*dynamic_cast<Tool*>(i), lokasi);
    } else if(i->get_type() == "NONTOOL"){
        this->add_item(*dynamic_cast<NonTool*>(i), lokasi);
    }
}


void Crafting::addRecipe(int *dimension, string **input, string output,
                         int output_q) {
  this->ac.addRecipe(dimension, input, output, output_q);
}
void Crafting::addTool(string name, int quantity) {
  this->ac.addTool(name, quantity);
}

void Crafting::addNonTool(string name, int quantity, string variety) {
  this->ac.addNonTool(name, quantity, variety);
}

Item *Crafting::return_item(int lokasi) {
  Item *it = this->cs->returnItem(lokasi);
  this->refreshOutput();
  return it;
}

Item *Crafting::craft() {
  Item *it = this->output;
  /* this->show(); */
  /* cout << "Craft ? (y/n): "; */
  this->refreshCraftState();
  return it;
}

void Crafting::refreshCraftState() {
  delete this->cs;
  this->cs = new CraftState();
  this->output = new Item();
  this->output->set_name("-");
}
