#ifndef __RECIPE_HPP__
#define __RECIPE_HPP__

#include <string>
using namespace std;

#include "../../CraftState/CraftState.hpp"

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

  static void arr_con(Recipe* r, int* dimension, string** input, string output, int output_q);
  static void arr_del(Recipe* r);
  string get_output() const;
  int get_output_q() const;
  void operator=(const Recipe &r);
  // Dobel supaya komutatif
  friend bool operator==(const CraftState &cs, const Recipe &r);
  friend bool operator==(const Recipe &r, const CraftState &cs);
};

#endif
