#ifndef __CRAFTING_H__
#define __CRAFTING_H__

#include "../Item/Item.h"
#include "AllRecipe/AllRecipe.hpp"
#include "CraftState/CraftState.hpp"
using namespace std;

class Crafting {
  // Main class untuk fitur Crafting
private:
  CraftState *cs; // Array 3 x 3
  AllRecipe ar;   // Kumpulan Resep
  string output;  // Nama item yang akan dihasilkan
public:
  Crafting();

  // Mendisplay CraftState dan Output
  void show() const;

  // Menambahkan item ke lokasi
  // row = lokasi `div` 3
  // col = lokasi `mod` 3
  void add_item(Item i, int lokasi);

  // Menambahkan resep ke ar
  // dimension dan input akan di hard copy
  void addRecipe(int *dimension, string **input,
                 string output, int output_q);

  // Mengembalikan item di lokasi
  // row = lokasi `div` 3
  // col = lokasi `mod` 3
  Item return_item(int lokasi);

  // Jika bisa ngecraft
  //    return Item
  //    kosongin CraftState
  //    kosongin Output
  // Else
  //    Do Nothing
  Item craft();

  // Mengosongkan CraftState dan Output
  void refreshCraftState();
};

#endif