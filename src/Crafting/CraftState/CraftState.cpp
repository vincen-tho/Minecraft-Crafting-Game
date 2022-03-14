#include "CraftState.hpp"
#include <iostream>
using namespace std;

CraftState::CraftState() {
  this->slot = new Item *[3];
  for (int i = 0; i < 3; i++) {
    this->slot[i] = new Item[3];
  }

  this->dimension = new int[2];
  this->top_left = new int[2];
}

CraftState::~CraftState() {
  for (int i = 0; i < 3; i++) {
    delete[] this->slot[i];
  }
  delete[] this->slot;
  delete[] this->dimension;
  delete[] this->top_left;
}

void CraftState::addItem(Item i, int lokasi) {
  int row = lokasi / 3;
  int col = lokasi % 3;

  this->slot[row][col] = i;
}

void CraftState::returnItem(int lokasi) {
  // Belum diimplementasikan
  // Perlu cara untuk ngidentifikasi tipe dari item
  // (string -> Item)
}

void CraftState::show() {
  for (int i = 0; i < 3; i++) {
    for (int j; j < 3; j++) {
      cout << "[ " << this->slot << " ]"
           << " ";
    }
    cout << endl;
  }
}
