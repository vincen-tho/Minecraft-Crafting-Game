#ifndef __CRAFTSTATE_HPP__
#define __CRAFTSTATE_HPP__

#include <string>
#include "../../Item/Item.h"
#include "../AllRecipe/AllRecipe.hpp"

using namespace std;

class CraftState {
  // Kelas ini merupakan array 3 x 3 di Crafting
private:
  string **slot; // Array 3 x 3
  int *top_left;
  int *dimension;

public:
  CraftState();
  ~CraftState();

  // Tambah Item
  void addItem(Item i, int lokasi);

  // Kembalikan Item
  void returnItem(int lokasi);

  // show
  void show();

  // Dobel supaya komutatif
  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

#endif
