#ifndef __CRAFTING_H__
#define __CRAFTING_H__

#include "../Item/Item.h"
#include "AllConfig/AllConfig.hpp"
#include "CraftState/CraftState.hpp"
using namespace std;

class Crafting {
  // Main class untuk fitur Crafting
private:
  CraftState *cs; // Array 3 x 3
  AllConfig ac;   // Kumpulan Resep
  Item* output;  // Nama item yang akan dihasilkan
public:
  // Konstruktor Biasa
  Crafting();

  // Mendisplay CraftState dan Output
  void show() const;

  // Menambahkan item ke lokasi
  // row = lokasi `div` 3
  // col = lokasi `mod` 3
  void add_item(NonTool i, int lokasi);
  void add_item(Tool t, int lokasi);
  void refreshOutput();

  // Menambahkan resep ke ar
  // dimension dan input akan di hard copy
  void addRecipe(int *dimension, string **input,
                 string output, int output_q);

  // Menambahkan Tool ke ar
  void addTool(string name, int quantity);
  
  // Menambahkan Non-Tool ke ar
  void addNonTool(string name, int quantity, string variety);

  // Mengembalikan item di lokasi
  // row = lokasi `div` 3
  // col = lokasi `mod` 3
  Item* return_item(int lokasi);

  // Jika bisa ngecraft
  //    return Item
  //    kosongin CraftState
  //    kosongin Output
  // Else
  //    Do Nothing
  Item* craft();

  // Mengosongkan CraftState dan Output
  void refreshCraftState();
};

#endif
