#include "Recipe.hpp"

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
