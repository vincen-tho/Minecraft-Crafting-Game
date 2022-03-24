#include "CraftState.hpp"
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
using namespace std;

CraftState::CraftState() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      this->table[i][j] = make_pair(new Item(), 0);
    }
  }
  this->bot_rht = {0, 0};
  this->top_lft = {2, 2};
}

CraftState::~CraftState() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      delete this->table[i][j].first;
    }
  }
}

void CraftState::add_item(Item *it, int q, int loc) {
  if (this->at(loc).second > 0) {
    // Namanya sama
    cout << "Nama" << endl;
    bool same_name = this->at(loc).first->get_name() == it->get_name();
    cout << same_name << endl;
    if (same_name && it->get_type() == "NONTOOL") {
      cout << "Tambah" << endl;
      this->at(loc).second += q;
    } else if (same_name && it->get_type() == "TOOL") {
      cout << "Tidak Bisa Stack Tool";
      throw "Tidak bisa stack Tool";
    } else {
      cout << "2 Tidak Bisa Stack Tool";
      throw "Sudah ada Item di slot ini";
    }
  } else {
    this->at(loc).first = it;
    this->at(loc).second = q;
  }
  update_boundary(loc);
}

pair<Item *, int> CraftState::return_item(int q, int loc) {
  Item *ret_cp;
  Item *ret = this->at(loc).first;

  // Check jumlah Item
  if (this->at(loc).second < q) {
    throw "Items gak cukup";
  }

  // Copy Item
  if (ret->get_type() == "TOOL") {
    ret_cp = new Tool(*dynamic_cast<Tool *>(ret));
  } else if (ret->get_type() == "NONTOOL") {
    ret_cp = new NonTool(*dynamic_cast<NonTool *>(ret));
  } else {
    throw "Type Error";
  }

  // Hapus Item kalau 0
  if (this->at(loc).second == q) {
    delete this->at(loc).first;
    this->at(loc).first = new Item();
  }

  // Kurangi jumlah
  this->at(loc).second -= q;

  // Reset batas
  this->reset_boundary();

  return make_pair(ret_cp, q);
}

pair<Item *, int> &CraftState::at(int loc) {
  int row = loc / 3;
  int col = loc % 3;
  return this->table[row][col];
}

pair<Item *, int> CraftState::get(int row, int col) const {
  return this->table[row][col];
}

pair<Item *, int> CraftState::at(int loc) const {
  int row = loc / 3;
  int col = loc % 3;
  return this->table[row][col];
}

void CraftState::update_boundary(int loc) {
  int row = loc / 3;
  int col = loc % 3;
  if (row < this->top_lft[0]) {
    this->top_lft[0] = row;
  }
  if (col < this->top_lft[1]) {
    this->top_lft[1] = col;
  }
  if (row > this->bot_rht[0]) {
    this->bot_rht[0] = row;
  }
  if (col > this->bot_rht[1]) {
    this->bot_rht[1] = col;
  }
}

void CraftState::reset_boundary() {
  this->bot_rht = {0, 0};
  this->top_lft = {2, 2};
  for (int i = 0; i < 9; i++) {
    if (this->at(i).second > 0) {
      this->update_boundary(i);
    }
  }
}

array<int, 2> CraftState::dur_add_chk() const {
  array<int, 2> ToolLoc;
  int ToolNum = 0;
  bool type_b;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      type_b = this->table[i][j].first->get_type() == "TOOL";
      if (type_b) {
        ToolNum++;
        ToolLoc[ToolNum % 2] = i * 3 + j;
      }
    }
  }

  if (ToolNum == 2 && (this->at(ToolLoc[0]).first->get_name() ==
                       this->at(ToolLoc[1]).first->get_name())) {
    return ToolLoc;
  } else {
    return {-1, -1};
  }
}

pair<Item *, int> CraftState::add_dur(array<int, 2> tool_loc) {
  Tool *T0 = dynamic_cast<Tool *>(this->at(tool_loc[0]).first);
  Tool *T1 = dynamic_cast<Tool *>(this->at(tool_loc[1]).first);
  int newDur = T0->get_durability() + T1->get_durability();
  if (newDur > 10) {
    newDur = 10;
  }

  Tool *T = new Tool(T0->get_name(), 1);
  T->set_durability(newDur);

  return make_pair(dynamic_cast<Item *>(T), 1);
}

int CraftState::get_min_used() const {
  int min = INT32_MAX;
  int q;
  for (int i = 0; i < 9; i++) {
    q = this->at(i).second;
    if (q > 0 && q < min) {
      min = q;
    }
  }
  return min;
}

array<int, 2> CraftState::get_dimensions() const {
  return {this->bot_rht[0] - this->top_lft[0] + 1,
          this->bot_rht[1] - this->top_lft[1] + 1};
}

void CraftState::clean(int q) {
  pair<Item *, int> tmp;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp = this->table[i][j];
      if (tmp.second == q) {
        delete this->table[i][j].first;
        this->table[i][j].first = new Item();
      }
      if (tmp.second >= q) {
        this->table[i][j].second -= q;
      }
    }
  }
}

string stripe_if_noname(string str) {
  if (str == "noname") {
    return "-";
  } else {
    return str;
  }
}

void CraftState::show() const {
  array<int, 3> bufn = {0, 0, 0};
  array<int, 3> bufq = {0, 0, 0};
  pair<Item *, int> tmp;
  int q = 0;
  int n = 0;
  /* cout << top_lft[0] << " " << top_lft[1] << endl; */
  /* cout << bot_rht[0] << " " << bot_rht[1] << endl; */
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp = this->table[i][j];
      q = stripe_if_noname(tmp.first->get_name()).length();
      n = floor(log10(tmp.second)) + 1;
      if (q > bufn[j]) {
        bufn[j] = q;
      }
      if (n > bufq[j]) {
        bufq[j] = n;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tmp = this->table[i][j];
      q = tmp.second;
      cout << "[ " << setw(bufn[j]) << left
           << stripe_if_noname(tmp.first->get_name()) << " x" << setw(bufq[j])
           << q << " ]" << fixed;
    }
    cout << endl;
  }
}
