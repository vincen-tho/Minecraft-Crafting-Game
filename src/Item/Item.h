#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
    private:
        static int ID;
        std :: string name;
        std :: string type;
        int quantity;
        int count;
    public:
        Item();
        Item(std :: string name, std :: string type, int quantity);
        void set_name(std :: string name);
        std :: string get_name() const;
        void set_type(std :: string type);
        std :: string get_type() const;
        void set_quantity(int quantity);
        int get_quantity() const;
        virtual void displayInfo() const;
};

class Tool : public Item{
    private: 
        int durability;
    public:
        Tool();
        Tool( std :: string name, int quantity);
        void set_durability(int durability);
        int get_durability() const;
        void displayInfo() const;
        void operator=(const Tool &t);
};

class NonTool : public Item{
    private:
        std :: string variant;
    public:
        NonTool();
        NonTool(std :: string name, int quantity, std :: string variant);
        void set_variant(std :: string variant);
        std :: string get_variant() const;
        void displayInfo() const;
        void operator=(const NonTool &nt);
};
#endif
