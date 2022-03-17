#ifndef __CRAFTSTATE_HPP__
#define __CRAFTSTATE_HPP__

#include <string>
#include <array>
#include "../../Item/Item.h"
#include "../AllConfig/AllConfig.hpp"

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
  void addItem(Item* i, int lokasi);

  // Kembalikan Item
  Item* returnItem(int lokasi);

  // show
  void show();

  array<int, 2> get_dimension() const;

  // Dobel supaya komutatif
  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

#endif
