#include "Exception.hpp"
#include <string>

int main(){
    string itemName;
    int itemQty;
    while(itemName != "END")
    try{
        cin >> itemName >> itemQty;
        if(itemQty <= 0 ){
            BaseException *E = new NotToolException(itemQty);
            throw(E);
        }
        else if( /*TODO: Verify if ITEM_NAME IS VALID*/ true){
            BaseException *E = new NoItemInventoryException(itemQty);
            throw(E);
        }
        else{
            cout << "bruh" <<endl;
        }
    }
    catch(BaseException* ex)
    {
        ex->printMessage();
    }

}