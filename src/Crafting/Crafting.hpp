#ifndef __CRAFTING_H__
#define __CRAFTING_H__

#include "../Item/Item.h"
#include <string>
#include <vector>

using namespace std;

#define RECIPE_MAX_SIZE 30

class Recipe; // Forward declaration

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

class Recipe {
  // Resep
private:
  int *dimension; // row x col
  string **input;
  string output; // Nama item output
  int output_q;  // Jumlah item output
public:
  // Bikin Resep
  //
  // Input :
  //  dimension : int[2]
  //  input     : string[dimension[0]][dimension[1]]
  //  output    : string
  //  output_q  : int
  Recipe();
  Recipe(int *dimension,  string **input,  string output,
          int output_q);
  Recipe(const Recipe& r);
  ~Recipe();

  void operator=(const Recipe &r);
  // Dobel supaya komutatif
  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

class AllRecipe {
  // List Resep
private:
  vector<Recipe> recipes;

public:
  AllRecipe();

  // Menambahkan Recipe
  void addRecipe(int *dimension, string **input,
                 string output, int output_q);

  // Mencari item di recipes
  //
  // Input : Crafstate
  // Output: Lokasi resep di recipes, jika gak ada return -1
  int search_item(CraftState &cs) const;
};

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
