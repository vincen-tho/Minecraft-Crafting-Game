#include "Crafting.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

CraftState::CraftState() {
  this->slot = new string *[3];
  for (int i = 0; i < 3; i++) {
    this->slot[i] = new string[3];
    for (int j = 0; j < 3; j++) {
      this->slot[i][j] = "-";
    }
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

  this->slot[row][col] = i.get_name();
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

bool operator==(const CraftState &cs, const Recipe &r) {
  if (cs.dimension[0] != r.dimension[0] || cs.dimension[1] != r.dimension[1]) {
    return false;
  } else { // Dimensi-nya sama
    for (int i = 0; i < r.dimension[0]; i++) {
      for (int j = 0; j < r.dimension[1]; j++) {
        if (cs.slot[cs.top_left[0] + i][cs.top_left[1] + j] != r.input[i][j]) {
          return false;
        }
      }
    }
  }
  return true;
}
bool operator==(const Recipe &r, const CraftState &cs) { return cs == r; }

Recipe::Recipe() {
  this->dimension = NULL;
  this->input = NULL;
  this->output = "-";
  this->output_q = 0;
}

Recipe::Recipe(int *dimension, string **input, string output, int output_q) {
  this->dimension = new int[2];
  this->dimension[0] = dimension[0];
  this->dimension[1] = dimension[1];
  this->input = new string *[this->dimension[0]];
  for (int i = 0; i < this->dimension[0]; i++) {
    this->input[i] = new string[this->dimension[1]];
    for (int j = 0; j < this->dimension[1]; j++) {
      this->input[i][j] = input[i][j];
    }
  }
  this->output = output;
  this->output_q = output_q;
}

Recipe::Recipe(const Recipe& r){
  this->dimension = new int[2];
  this->dimension[0] = r.dimension[0];
  this->dimension[1] = r.dimension[1];
  this->input = new string*[this->dimension[0]];
  for (int i = 0; i < this->dimension[0]; i++) {
    this->input[i] = new string[this->dimension[1]];
    for (int j = 0; j < this->dimension[1]; j++) {
        this->input[i][j] = r.input[i][j];
    }
  }
  this->output = r.output;
  this->output_q = r.output_q;
}

Recipe::~Recipe() {
  for (int i = 0; i < this->dimension[1]; i++) {
    delete[] this->input[i];
  }
  delete[] this->input;
  delete[] this->dimension;
}
/* Recipe::Recipe(const Recipe& r){ */
/*   this->dimension = new int[2]; */
/*   this->dimension[0] = r.dimension[0]; */
/*   this->dimension[1] = r.dimension[1]; */
/*   this->input = new string*[this->dimension[0]]; */
/*   for (int i = 0; i < this->dimension[0]; i++) { */
/*     this->input[i] = new string[this->dimension[1]]; */
/*     for (int j = 0; j < this->dimension[1]; j++) { */
/*         this->input[i][j] = r.input[i][j]; */
/*     } */
/*   } */
/*   this->output = r.output; */
/*   this->output_q = r.output_q; */
/**/
/* } */

void Recipe::operator=(const Recipe &r) {
  for (int i = 0; i < this->dimension[0]; i++) {
      delete [] this->input[i];
  }
  delete [] this->input;
  this->dimension[0] = r.dimension[0];
  this->dimension[1] = r.dimension[1];
  this->input = new string*[this->dimension[0]];
  for (int i = 0; i < this->dimension[0]; i++) {
    this->input[i] = new string[this->dimension[1]];
    for (int j = 0; j < this->dimension[1]; j++) {
        this->input[i][j] = r.input[i][j];
    }
  }
  this->output = r.output;
  this->output_q = r.output_q;
}

AllRecipe::AllRecipe() {
  this->recipes = std::vector<Recipe>();
}

void AllRecipe::addRecipe(int *dimension, string **input, string output,
                          int output_q) {
    this->recipes.push_back(Recipe(dimension, input, output, output_q));
}

int AllRecipe::search_item(CraftState &cs) const{
    return find(this->recipes.begin(), this->recipes.end(), cs) - this->recipes.begin();
}

Crafting::Crafting(){
    this->cs = new CraftState();
    this->output = "-";
}

void Crafting::show() const {
    this->cs->show();
}

void Crafting::add_item(Item i, int lokasi){
    this->cs->addItem(i, lokasi);
}

void Crafting::addRecipe(int *dimension, string **input,
        string output, int output_q){
    this->ar.addRecipe(dimension, input, output, output_q);
    this->output = this->ar.search_item(*this->cs);
}

/* Item Crafting::return_item(int lokasi){ */
/*     // Belum */
/* } */

/* Item craft(){ */
/**/
/* } */

void Crafting::refreshCraftState(){
    delete this->cs;
    this->cs = new CraftState();
    this->output = "-";
}
