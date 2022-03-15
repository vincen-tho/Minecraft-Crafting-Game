#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <iostream>
using namespace std;

class BaseException {
public:
    // menuliskan pesan kesalahan ke stdout
    virtual void printMessage() = 0;
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
