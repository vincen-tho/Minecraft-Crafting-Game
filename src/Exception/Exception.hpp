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
class InvalidNumberException : public BaseException {
private:
    T number;
public:
    InvalidNumberException(T number) {
        this->number = number;
    }
    void printMessage() {
        cout << "Bilangan " << number << " tidak valid" << endl;
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
        cout << "INVENTORY SLOT ID: " << SLOT_ID << " bukan tool" << endl;
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


// class TransactionFailedException : public BaseException {
// private:
//     BaseException* exc;
// public:
//     TransactionFailedException(BaseException* exc) {
//         this->exc = exc;
//     }
//     void printMessage() {
//         cout << "Transaksi gagal dengan pesan kesalahan: ";
//         exc->printMessage();
//     }
// };

// class AccountNotFoundException : public BaseException {
// private:
//     string number;
// public:
//     AccountNotFoundException(string number) {
//         this->number = number;
//     }
//     void printMessage() {
//         cout << "Tidak ditemukan rekening dengan nomor " << number << endl;
//     }
// };

#endif
