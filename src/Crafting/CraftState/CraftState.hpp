#ifndef __CRAFTSTATE_HPP__
#define __CRAFTSTATE_HPP__

#include "../../Item/Item.h"
#include "../AllConfig/AllConfig.hpp"
#include <array>
#include <string>

using namespace std;

class CraftState {
  // Kelas ini merupakan array 3 x 3 di Crafting
private:
  Item ***slot; // Array 3 x 3
  array<int, 2> top_left;
  array<int, 2> bot_rght;
  array<int, 2> dimension;
  /* int *top_left; */
  /* int *dimension; */

public:
  CraftState();
  ~CraftState();

  // Tambah Item
  void addItem(Item *i, int lokasi);

  // Kembalikan Item
  Item *returnItem(int lokasi);

  // show
  void show();

  array<int, 2> loc_to_coor(int loc) const;
  int coor_to_loc(array<int, 2> coor) const;
  void update_dimension(int row, int col);
  array<int, 2> get_dimension() const;
  array<int, 2> dur_add_check() const;
  Item *add_tool(array<int, 2> coor) const;
  int get_min_used() const;

  Item *at(int lokasi) const;
  void clean(int items_used);

  // Dobel supaya komutatif
  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

#endif
