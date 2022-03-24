#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item {
    private:
        int ID;
        std :: string name;
        std :: string type;
    public:
        Item();
        Item(int ID, std :: string name, std :: string type);
        void set_name(std :: string name);
        std :: string get_name() const;
        void set_type(std :: string type);
        std :: string get_type() const;
        int get_ID() const;
        virtual int get_durability() const;
        virtual void set_durability(int durability);
        virtual std :: string get_variant() const;
        virtual void set_variant(std :: string variant);
};

class Tool : public Item{
    private: 
        int durability;
    public:
        Tool();
        Tool(int ID, std :: string name);
        void set_durability(int durability);
        int get_durability() const;
        void operator=(const Tool &t);
};

class NonTool : public Item{
    private:
        std :: string variant;
    public:
        NonTool();
        NonTool(int ID, std :: string name, std :: string variant);
        void set_variant(std :: string variant);
        std :: string get_variant() const;
        void operator=(const NonTool &nt);
};
#endif
