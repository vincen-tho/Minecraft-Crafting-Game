#ifndef __CRAFTSTATE_HPP__
#define __CRAFTSTATE_HPP__

#include "../../Item/Item.h"
#include "../../Exception/Exception.hpp"
#include <array>
#include <utility>

class AllConfig;
class Recipe;

class CraftState {
private:
  std::pair<Item *, int> table[3][3];
  array<int, 2> top_lft;
  array<int, 2> bot_rht;

public:
  CraftState();
  ~CraftState();

  // Menambahkan Item
  void add_item(Item *it, int q, int loc);

  // Mengambil Item dari slot
  std::pair<Item *, int> return_item(int q, int loc);

  // Mengembalikan elemen di loc, bisa diubah
  pair<Item *, int>& at(int loc);

  // Mengembalikan elemen di loc, tidak bisa diubah
  pair<Item *, int> at(int loc) const;

  // Mengembalikan elemen di [row, col], tidak bisa diubah
  pair<Item *, int> get(int row, int col) const;

  // Update top left dan bottom right
  void update_boundary(int loc);

  // Kayak update boundary, tapi nge-loop keseluruhnya
  void reset_boundary();

  // Check kasus penambahan durability item
  array<int, 2> dur_add_chk() const;

  // Menambahkan dua tool
  pair<Item*, int> add_dur(array<int, 2> tool_loc);

  int get_min_used() const;

  array<int, 2> get_dimensions() const;

  void clean(int q);

  // Print ke console
  void show() const;

  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

#endif
