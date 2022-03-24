#include "Crafting.hpp"
#include "CraftState/CraftState.hpp"
#include <array>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

Item *child_cast(Item *it) {
  if (it->get_type() == "TOOL") {
    return new Tool(*dynamic_cast<Tool *>(it));
  } else if (it->get_type() == "NONTOOL") {
    return new NonTool(*dynamic_cast<NonTool *>(it));
  } else {
    /*   cout << "Not Recognized "<< it->get_type() << endl; */
    /* throw "TYPE NOT RECOGNIZED"; */
    return new Item();
  }
}

Crafting::Crafting() {
  this->output = make_pair(new Item(), 0);
  this->mul = 0;
}

Crafting::~Crafting() { delete this->output.first; }

void Crafting::addRecipe(int *dimension, string **input, string output,
                         int output_q) {
  this->ac.addRecipe(dimension, input, output, output_q);
}
void Crafting::addTool(int ID, string name) {
  this->ac.addTool(ID, name);
}

void Crafting::addNonTool(int ID, string name, string variety) {
  this->ac.addNonTool(ID, name,variety);
}

/* Item *Crafting::searchTool(string str) const { */
/*   Item *it = this->ac.search_item(str); */
/*   if (it->get_type() == "TOOL") { */
/*     return it; */
/*   } else { */
/*     BaseException *E = new ItemNotFound(); */
/*     throw(E); */
/*   } */
/* } */
/**/
/* Item *Crafting::searchNonTool(string str) const { */
/*   Item *it = this->ac.search_item(str); */
/*   if (it->get_type() == "NONTOOL") { */
/*     return it; */
/*   } else { */
/*     BaseException *E = new ItemNotFound(); */
/*     throw(E); */
/*   } */
/* } */

Item *Crafting::searchItem(string str) const {
  Item *it = this->ac.search_item(str);
  if (it->get_name() != "noname") {
    return it;
  } else {
    throw(new ItemNotFound());
  }
}

void Crafting::add_item(Item *it, int q, int loc) {
  Item *new_Item;
  if (it->get_type() == "TOOL") {
    new_Item = new Tool(*dynamic_cast<Tool *>(it));
    this->cs.add_item(new_Item, q, loc);
  } else if (it->get_type() == "NONTOOL") {
    new_Item = new NonTool(*dynamic_cast<NonTool *>(it));
    this->cs.add_item(new_Item, q, loc);
  } else {
    throw(new InvalidInputException<string>(it->get_type()));
  }
  this->refreshOutput();
}

pair<Item *, int> Crafting::ret_item(int q, int loc) {
  pair<Item *, int> ret = this->cs.return_item(q, loc);
  this->refreshOutput();
  return ret;
}

pair<Item *, int> Crafting::at(int loc) const { return this->cs.at(loc); }

bool Crafting::canCraft() { return this->mul > 0; }

pair<Item *, int> Crafting::CRAFT() {
  pair<Item *, int> ret = this->output;
  ret.second *= this->mul;
  this->refreshCraftState();
  return ret;
}

void Crafting::refreshOutput() {
  array<int, 2> ToolLoc = this->cs.dur_add_chk();
  if (ToolLoc == array<int, 2>{-1, -1}) {
    delete this->output.first;
    pair<Item *, int> rcp = this->ac.search_recipe(this->cs);
    this->output = make_pair(child_cast(rcp.first), rcp.second);
    if (this->output.second > 0) {
      this->mul = this->cs.get_min_used();
    } else {
      this->mul = 0;
    }
  } else {
    this->output = this->cs.add_dur(ToolLoc);
    this->mul = 1;
  }
}

void Crafting::refreshCraftState() {
  this->cs.clean(this->mul);
  this->output = make_pair(new Item(), 0);
}

void Crafting::show() const {
  this->cs.show();
  if (this->output.first->get_name() == "noname") {
    cout << "CAN CRAFT: - x" << output.second << endl;
  } else {
    int set_num = 9;
    cout << "CAN CRAFT: " << endl
         << setw(set_num) << "Name"
         << ": " << this->output.first->get_name() << endl
         << setw(set_num) << "Quantity"
         << ": " << this->output.second * this->mul << endl;
    if (this->output.first->get_type() == "TOOL") {
      cout << setw(set_num) << "Durability"
           << ": " << dynamic_cast<Tool *>(this->output.first)->get_durability()
           << endl;
    } else if (this->output.first->get_type() == "NONTOOL") {
      cout << setw(set_num) << "Variant"
           << ": " << dynamic_cast<NonTool *>(this->output.first)->get_variant()
           << endl;
    }
  }
}

string s_o_r(string str) {
  if (str == "noname") {
    return "-";
  } else {
    return str;
  }
}

bool array_check(string **recipe, const CraftState &cs, array<int, 2> item_dim,
                 array<int, 2> item_tl) {
  bool n_check = true; // Normal
  bool m_check = true; // Mirror
  string s = "-";
  Item *it;
  for (int i = 0; i < item_dim[0]; i++) {
    for (int j = 0; j < item_dim[1]; j++) {
      it = cs.get(item_tl[0] + i, item_tl[1] + j).first;
      if (it->get_type() == "NONTOOL") {
        s = dynamic_cast<NonTool *>(it)->get_variant();
      }
      if (s == "-") {
        s = "nonvar";
      }
      n_check = n_check &&
                (s_o_r(it->get_name()) == recipe[i][j] || s == recipe[i][j]);
      m_check =
          m_check && (s_o_r(it->get_name()) == recipe[i][item_dim[1] - j - 1] ||
                      s == recipe[i][item_dim[1] - j - 1]);
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
    bool same_dim = cs.get_dimensions()[0] == r.dimension[0] &&
                    cs.get_dimensions()[1] == r.dimension[1];
    if (same_dim) { // Dimensinya sama
      return array_check(r.input, cs, cs.get_dimensions(), cs.top_lft);
    } else {
      return false;
    }
  } else { // Resep 3x3
    return array_check(r.input, cs, {3, 3}, {0, 0});
  }
  return true;
}

bool operator==(const Recipe &r, const CraftState &cs) { return cs == r; }
