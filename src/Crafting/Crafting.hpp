#ifndef __CRAFTING_H__
#define __CRAFTING_H__

#include "../Item/Item.h"
#include "../Exception/Exception.hpp"
#include "AllConfig/AllConfig.hpp"
#include "CraftState/CraftState.hpp"
#include <utility>

class Crafting {
private:
  AllConfig ac; // Berisi konfigurasi saat loading
  CraftState cs; // Tabel Crafting
  pair<Item *, int> output; // Output Crafting
  int mul; // Multiplier, berguna untuk MultiCrafting

public:
  Crafting();
  ~Crafting();

  /* Option Config */
  // Nambahin Resep
  void addRecipe(int *dimension, string **input, string output, int output_q);
  // Nambahin Tool
  void addTool(int ID, string name);
  // Nambahin NonTool
  void addNonTool(int ID, string name, string variety);
  // Mencari Tool yang namanya str
  /* Item *searchTool(string str) const; */
  // Mencari NonTool yang namanya str
  /* Item *searchNonTool(string str) const; */
  // Mencari Item
  Item* searchItem(string str) const;

  /* Option CraftState */
  // Nambah Item *it dengan kuantitas q di lokasi loc
  void add_item(Item *it, int q, int loc);
  // Mengembalikan Item dari lokasi loc sebanyak q
  pair<Item *, int> ret_item(int q, int loc);
  // Mengembalikan Item dan quantity di loc
  pair<Item *, int> at(int loc) const;

  /* Option Crafting */
  // True menandakan ada resep yang cocok
  bool canCraft();
  // Method Utama, mereturn Item dan Quantity
  pair<Item *, int> CRAFT();
  // Self-explanatory
  void refreshOutput();
  // Self-explanatory
  void refreshCraftState();
  // Men-display tabel Crafting dan apa yang bisa di-CRAFT
  void show() const;

};

#endif
