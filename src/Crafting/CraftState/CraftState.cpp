#include "CraftState.hpp"
#include <cstdint>
#include <iostream>
using namespace std;

CraftState::CraftState() {
  this->slot = new Item *[3];
  for (int i = 0; i < 3; i++) {
    this->slot[i] = new Item[3];
    for (int j = 0; j < 3; j++) {
      this->slot[i][j].set_name("-");
    }
  }

  this->top_left= {INT32_MAX, INT32_MAX};
  /* this->dimension = new int[2]; */
  /* this->top_left = new int[2]; */
  /* this->top_left[0] = INT32_MAX; */
  /* this->top_left[1] = INT32_MAX; */
}

CraftState::~CraftState() {
  for (int i = 0; i < 3; i++) {
    delete[] this->slot[i];
  }
  delete[] this->slot;
  /* delete[] this->dimension; */
  /* delete[] this->top_left; */
}

void CraftState::addItem(Item i, int lokasi) {
  int row = lokasi / 3;
  int col = lokasi % 3;

  this->slot[row][col] = i;
  if (row < this->top_left[0]) {
    this->top_left[0] = row;
  }
  if (col < this->top_left[1]) {
    this->top_left[1] = col;
  }
  if (this->top_left[0] + this->dimension[0] - 1 < row) {
    this->dimension[0] = row - this->top_left[0] + 1;
  }

  if (this->top_left[1] + this->dimension[1] - 1 < col) {
    this->dimension[1] = col - this->top_left[1] + 1;
  }
}

void CraftState::returnItem(int lokasi) {
  // Belum diimplementasikan
  // Perlu cara untuk ngidentifikasi tipe dari item
  // (string -> Item)
}

void CraftState::show() {
  cout << "Top Left : "
       << "[ " << this->top_left[0] << " " << this->top_left[1] << " ]" << endl;
  cout << "Dimension : "
       << "[ " << this->dimension[0] << " " << this->dimension[1] << " ]" << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << this->slot[i][j].get_name() << " ]"
           << " ";
    }
    cout << endl;
  }
}
