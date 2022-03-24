#include "../lib.hpp"
#include "Crafting.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

void CASE_1(Crafting &Craft, Inventory &Inv) {
  cout << "CASE 1: OAK_LOG -> OAK_PLANK" << endl;

  cout << " 1. Cari OAK_LOG" << endl;
  Item *OAK_LOG = Craft.searchNonTool("OAK_LOG");

  cout << " 2. Tambah OAK_LOG ke Crafting lokasi 0" << endl;
  Craft.add_item(OAK_LOG, 3, 1);
  Craft.show();
  pair<Item *, int> ret_OAK_LOG = Craft.ret_item(3, 1);
  Craft.show();
  Craft.add_item(OAK_LOG, 3, 2);

  cout << " 3. SHOW" << endl;
  Craft.show();

  cout << " 4. CRAFT" << endl;
  pair<Item *, int> result = Craft.CRAFT();

  cout << " 5. ADD TO INVENTORY" << endl;
  Inv.add_item(result.first, result.second);

  cout << " 6. SHOW ALL" << endl;
  Craft.show();
  Inv.display_inventory();

  cout << "END CASE 1" << endl;
}

void CASE_2(Crafting &Craft, Inventory &Inv) {
  cout << "CASE 2: ADD DI LOKASI YANG SAMA" << endl;

  cout << " 1. Cari OAK_LOG" << endl;
  Item *OAK_LOG = Craft.searchNonTool("OAK_LOG");

  cout << " 2. Tambah 3 OAK_LOG ke Crafting lokasi 0" << endl;
  Craft.add_item(OAK_LOG, 3, 0);
  Craft.show();

  cout << " 3. Tambah 3 OAK_LOG lagi ke Crafting lokasi 0" << endl;
  Craft.add_item(OAK_LOG, 3, 0);

  cout << " 4. SHOW ALL" << endl;
  Craft.show();
  Inv.display_inventory();

  cout << "END CASE 2" << endl;
}

void CASE_3(Crafting &Craft, Inventory &Inv) {
  cout << "CASE 3: PARTIAL RETURN" << endl;

  cout << " 1. Siapkan Items" << endl;
  Item *OAK_LOG = Craft.searchNonTool("OAK_LOG");

  cout << " 2. Tambah 3 OAK_LOG ke Crafting lokasi 0" << endl;
  Craft.add_item(OAK_LOG, 3, 0);
  Craft.show();

  pair<Item *, int> ret_OAK_LOG = Craft.ret_item(2, 0);

  cout << " 4. SHOW ALL" << endl;
  Craft.show();
  Inv.display_inventory();

  cout << "END CASE 3" << endl;
}

void CASE_4(Crafting &Craft, Inventory &Inv) {
  cout << "CASE 4: BIKIN DIAMOND_PICKAXE" << endl;

  cout << " 1. Siapkan Items" << endl;
  Item *DIA = Craft.searchNonTool("DIAMOND");
  Item *STK = Craft.searchNonTool("STICK");

  cout << " 2. Siapkan Konfigurasi" << endl;
  Craft.add_item(DIA, 2, 2);
  Craft.add_item(DIA, 3, 1);
  Craft.add_item(DIA, 2, 5);
  Craft.add_item(DIA, 2, 0);
  Craft.add_item(STK, 7, 4);
  Craft.add_item(STK, 8, 7);

  cout << " 4. SHOW" << endl;
  Craft.show();

  cout << " 5. CRAFT" << endl;
  pair<Item *, int> result = Craft.CRAFT();

  cout << " 6. SHOW ALL" << endl;
  Craft.show();
  Inv.display_inventory();

  cout << "END CASE 3" << endl;
}

void CASE_5(Crafting& Craft){
    Item* DIA = Craft.searchNonTool("DIAMOND");
    Item* OAK_LOG = Craft.searchNonTool("OAK_LOG");
    Item* OAK_PL = Craft.searchNonTool("OAK_PLANK");
    DIA->displayInfo();
    OAK_LOG->displayInfo();
    OAK_PL->displayInfo();
}

int main() {

  Crafting Craft;
  Inventory Inv;

  load_recipes(Craft);
  load_items(Craft);

  /* try { */
  /*   CASE_5(Craft); */
  /* } catch (const char *err) { */
  /*   cout << err << endl; */
  /* } */
  Item* I0 = new Item(); // ID Item = 62
  I0->displayInfo();
  Item* I1 = new Item(); // ID Item = 63
  I1->displayInfo();

  return 0;
}
