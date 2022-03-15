#include "item.h"
#include "item.cpp"
#include <iostream>

int main(){
    Tool *barang1 = new Tool("spear",1);
    barang1-> displayInfo();
    Tool *barang2 = new Tool("axe",1);
    barang2-> displayInfo();
    Tool *barang3 = new Tool("sword",1);
    barang3-> displayInfo();
}
