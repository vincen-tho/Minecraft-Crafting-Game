#include <iostream>
#include <string.h>
using namespace std;

/* void SHOW(){ */
/*     //CRAFTING DISPLAY */
/*     for (int i = 0; i < count; i++){ */
/*         for (int J = 0; J < count; J++){ */
/*             cout << "[" << Object <<"] " <<end;  */
/*         } */
/*         cout << endl; */
/*     } */
/**/
/*     //INVENTORY DISPLAY */
/*     for (int i = 0; i < count; i++){ */
/*         for (int J = 0; J < count; J++){ */
/*             cout << "[" << Object <<"] " <<end;  */
/*         } */
/*         cout << endl; */
/*     } */
/* } */





void GIVE(){
    string reader,reader2;
    cin >> reader;
    if(reader == "GIVE"){
        cin >> reader; //ITEM_NAME
        cin >> reader2; //ITEM_QTY

        if(/*TODO: Verify if ITEM_NAME IS VALID*/ true){
            //TODO: IF VALID, ADD TO INVENTORY
        }
        else{
            cout << "Item Name not valid" <<endl; /* Maybe change with object exception */
        }
    }
}
