#include "CraftState.hpp"
#include <cmath>
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
  if (row > this->bot_rght[0]) {
    this->bot_rght[0] = row;
  }
  if (col > this->bot_rght[1]) {
    this->bot_rght[1] = col;
  }
  this->dimension = this->get_dimension();
}

Item CraftState::returnItem(int lokasi) {
  int row = lokasi / 3;
  int col = lokasi % 3;

  Item it = this->slot[row][col];
  this->slot[row][col] = Item();
  this->slot[row][col].set_name("-");
  // Reset
  string name;
  this->top_left = {2, 2};
  this->bot_rght = {0, 0};
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          name = this->slot[i][j].get_name();
          if(name != "-" && name != "noname"){
              if(this->top_left[0] > i){
                  this->top_left[0] = i;
              }
              if(this->top_left[1] > j){
                  this->top_left[1] = j;
              }
              if(this->bot_rght[0] < i){
                  this->bot_rght[0] = i;
              }
              if(this->bot_rght[1] < j){
                  this->bot_rght[1] = j;
              }
          }

      }
  }
  this->dimension = this->get_dimension();
  return it;
}

array<int, 2> CraftState::get_dimension() const {
  return {this->bot_rght[0] - this->top_left[0] + 1,
          this->bot_rght[1] - this->top_left[1] + 1};
}

void CraftState::show() {
  cout << "Top Left : "
       << "[ " << this->top_left[0] << " " << this->top_left[1] << " ]" << endl;
  cout << "Dimension : "
       << "[ " << this->dimension[0] << " " << this->dimension[1] << " ]"
       << endl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << "[ " << this->slot[i][j].get_name() << " ]"
           << " ";
    }
    cout << endl;
  }
}
