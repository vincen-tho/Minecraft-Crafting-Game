#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <sstream>

#include "lib.hpp"

using namespace std;

int main()
{
    string slotSrc, slotDest1, slotDest2,command;
    int idSlotSrc, idSlotDest;
    char typeSlotSrc, typeSlotDst;
    int slotQty;
    cin >> command ;
    cin >> slotSrc >> slotQty >> slotDest1 >> slotDest2;
    cout << command << endl;
    cout << slotDest1 << endl;
    cout << slotDest2 << endl;
}