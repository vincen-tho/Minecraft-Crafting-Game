#include "CraftState.hpp"
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
using namespace std;

CraftState::CraftState() {
  this->slot = new Item **[3];
  for (int i = 0; i < 3; i++) {
    this->slot[i] = new Item *[3];
    for (int j = 0; j < 3; j++) {
      this->slot[i][j] = new Item();
      this->slot[i][j]->set_name("-");
    }
  }

  this->top_left = {2, 2};
  this->bot_rght = {0, 0};
  this->dimension = {0, 0};
  /* this->dimension = new int[2]; */
  /* this->top_left = new int[2]; */
  /* this->top_left[0] = INT32_MAX; */
  /* this->top_left[1] = INT32_MAX; */
}

CraftState::~CraftState() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      delete this->slot[i][j];
    }
    delete[] this->slot[i];
  }
  delete[] this->slot;
  /* delete[] this->dimension; */
  /* delete[] this->top_left; */
}

array<int, 2> CraftState::loc_to_coor(int loc) const {
  return {loc / 3, loc % 3};
}

int CraftState::coor_to_loc(array<int, 2> coor) const {
  return coor[0] * 3 + coor[1];
}

void CraftState::update_dimension(int row, int col) {
  if (row < this->top_left[0]) {
    this->top_left[0] = row;
  }
  if (col < this->top_left[1]) {
    this->top_left[1] = col;
  }
  if (row > this->bot_rght[0]) {
    this->bot_rght[0] = row;
  }
  if (col > this->bot_rght[1]) {
    this->bot_rght[1] = col;
  }
  this->dimension = this->get_dimension();
}

void CraftState::addItem(Item *i, int lokasi) {
  array<int, 2> coor = this->loc_to_coor(lokasi);

  delete this->slot[coor[0]][coor[1]];
  this->slot[coor[0]][coor[1]] = i;

  this->update_dimension(coor[0], coor[1]);
}

Item *CraftState::returnItem(int lokasi) {
  array<int, 2> coor = this->loc_to_coor(lokasi);

  Item *it = this->slot[coor[0]][coor[1]];
  this->slot[coor[0]][coor[1]] = new NonTool();
  this->slot[coor[0]][coor[1]]->set_name("-");
  // Reset
  string name;
  this->top_left = {2, 2};
  this->bot_rght = {0, 0};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      name = this->slot[i][j]->get_name();
      if (name != "-" && name != "noname") {
        this->update_dimension(i, j);
      }
    }
  }
  return it;
}

array<int, 2> CraftState::dur_add_check() const {
  array<int, 2> ToolLoc;
  int ToolNum = 0;
  bool type_b;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      type_b = this->slot[i][j]->get_type() == "TOOL";
      if (type_b) {
        ToolNum++;
        ToolLoc[ToolNum % 2] = i * 3 + j;
      }
    }
  }
  if (ToolNum == 2) {
    return ToolLoc;
  } else {
    return {-1, -1};
  }
}

Item *CraftState::at(int lokasi) const {
  array<int, 2> coor = this->loc_to_coor(lokasi);
  return this->slot[coor[0]][coor[1]];
}

Item *CraftState::add_tool(array<int, 2> coor) const {
  Item *I = new Tool();
  I->set_name("-");
  Tool *T0 = dynamic_cast<Tool *>(this->at(coor[0]));
  Tool *T1 = dynamic_cast<Tool *>(this->at(coor[1]));
  if (T0->get_name() == T1->get_name()) {
    int newDur = T0->get_durability() + T1->get_durability();
    if (newDur > 10) {
      newDur = 10;
    }

    Tool *T = new Tool(T0->get_name(), 1);
    T->set_durability(newDur);

    return T;
  }
  return I;
}

array<int, 2> CraftState::get_dimension() const {
  return {this->bot_rght[0] - this->top_left[0] + 1,
          this->bot_rght[1] - this->top_left[1] + 1};
}

void CraftState::show() {
  /* cout << "Top Left : " */
  /*      << "[ " << this->top_left[0] << " " << this->top_left[1] << " ]" <<
   * endl; */
  /* cout << "Dimension : " */
  /*      << "[ " << this->dimension[0] << " " << this->dimension[1] << " ]" */
  /*      << endl; */
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << this->slot[i][j]->get_name() << " ]"
           << " ";
    }
    cout << endl;
  }
}
