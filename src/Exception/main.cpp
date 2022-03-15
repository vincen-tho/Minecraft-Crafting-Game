#include "Exception.hpp"
#include <string>

int main(){
    string itemName;
    int itemQty;
    while(itemName != "END")
    try{
        cin >> itemName >> itemQty;
        if(itemQty <= 0 ){
            InvalidNumberException<int> *E = new InvalidNumberException<int>(itemQty);
            throw(E); 
        }
        else if( /*TODO: Verify if ITEM_NAME IS VALID*/ true){
            ItemNameException E(itemName);
            throw(&E); 
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