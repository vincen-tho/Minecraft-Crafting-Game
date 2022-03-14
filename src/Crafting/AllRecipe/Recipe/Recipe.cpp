#include "Recipe.hpp"
#include <cstddef>

void Recipe::arr_con(Recipe *r, int *dimension, string **input, string output,
                     int output_q) {
  r->dimension = new int[2];
  r->dimension[0] = dimension[0];
  r->dimension[1] = dimension[1];
  r->input = new string *[r->dimension[0]];
  for (int i = 0; i < r->dimension[0]; i++) {
    r->input[i] = new string[r->dimension[1]];
    for (int j = 0; j < r->dimension[1]; j++) {
      r->input[i][j] = input[i][j];
    }
  }
  r->output = output;
  r->output_q = output_q;
}

void Recipe::arr_del(Recipe *r) {
  for (int i = 0; i < r->dimension[0]; i++) {
    delete[] r->input[i];
  }
  delete[] r->input;
  delete[] r->dimension;
}

Recipe::Recipe() {
  this->dimension = NULL;
  this->input = NULL;
  this->output = "-";
  this->output_q = 0;
}

Recipe::Recipe(int *dimension, string **input, string output, int output_q) {
  arr_con(this, dimension, input, output, output_q);
}

Recipe::Recipe(const Recipe &r) {
  arr_con(this, r.dimension, r.input, r.output, r.output_q);
}

Recipe::~Recipe() { arr_del(this); }

void Recipe::operator=(const Recipe &r) {
  arr_del(this);
  arr_con(this, r.dimension, r.input, r.output, r.output_q);
}

string Recipe::get_output() const{
    return this->output;
}
