#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
using namespace std;

class BaseException {
public:
    // menuliskan pesan kesalahan ke stdout
    virtual void printMessage() = 0;
};


class NoRecipe : public BaseException {
public:
    void printMessage() {
        cout << "Tidak ada Recipe yang valid" << endl;
    }
};

template<class T>
class InvalidInputException : public BaseException {
private:
    T Input;
public:
    InvalidInputException(T Input) {
        this->Input = Input;
    }
    virtual void printMessage(){
        cout << "Input " << Input << " tidak valid" << endl;
    }
};

class InvalidNumberException : public BaseException {
private:
    int number;
public:
    InvalidNumberException(int number) {
        this->number = number;
    }
    void printMessage() {
        cout << "Bilangan " << number << " tidak valid" << endl;
    }
};

class InputGreaterException : public BaseException {
private:
    int Input,Available;
public:
    InputGreaterException(int Input,int Available) {
        this->Input = Input;
        this->Available = Available;
    }
    void printMessage() {
        cout << "Input " << Input << " lebih besar daripada "<< Available << " yang tersedia." << endl;
        
    }
};

class ItemNameException : public BaseException {
private:
    string itemName;
public:
    ItemNameException(string itemName) {
        this->itemName = itemName;
    }
    void printMessage() {
        cout << "Item Name: " << itemName << " tidak valid" << endl;
    }
};
class DifferentItemStackException : public BaseException {
private:
    string ItemName1,ItemName2;
public:
    DifferentItemStackException(string ItemName1, string ItemName2) {
        this->ItemName1 = ItemName1;
        this->ItemName2 = ItemName2;
    }
    void printMessage() {
        cout << "Tidak bisa stack item " << ItemName1 << " dan " << ItemName2 << endl;
    }
};
class ToolStackingException : public BaseException {
    public:
    virtual void printMessage(){
        cout << "Tidak Bisa Melakukan Stacking pada Tool." <<endl;
    };
};
class SlotIdException : public BaseException {
protected:
    int SLOT_ID;
public:
    SlotIdException(int SLOT_ID) {
        this->SLOT_ID = SLOT_ID;
    }
    virtual void printMessage() = 0;
};

class NotToolException : public SlotIdException {
public:
    NotToolException(int SLOT_ID) : SlotIdException(SLOT_ID) {}
    void printMessage() {
        cout << "INVENTORY SLOT ID: " << SLOT_ID << " bukan Tool" << endl;
    }
};
class NotNonToolException : public SlotIdException {
public:
    NotNonToolException(int SLOT_ID) : SlotIdException(SLOT_ID) {}
    void printMessage() {
        cout << "INVENTORY SLOT ID: " << SLOT_ID << " bukan Non-Tool" << endl;
    }
};

class NoItemInventoryException : public SlotIdException {
public:
    NoItemInventoryException(int SLOT_ID) : SlotIdException(SLOT_ID) {}
    void printMessage() {
        cout << "INVENTORY SLOT ID: " << SLOT_ID << " tidak mengandung item" << endl;
    }
};

class NoItemCraftingException : public SlotIdException {
public:
    NoItemCraftingException(int SLOT_ID) : SlotIdException(SLOT_ID) {}
    void printMessage() {
        cout << "CRAFTING SLOT ID: " << SLOT_ID << " tidak mengandung item" << endl;
    }
};


#endif
