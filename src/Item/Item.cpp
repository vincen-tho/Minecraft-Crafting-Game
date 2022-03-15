#include "Item.h"
#include <iostream>

Item :: Item(){
    this-> ID = count++;
    this-> name = "noname";
    this-> type = "notype";
    this-> quantity = 0;
    this-> count++;
}

Item :: Item( string name, string type, int quantity){
    this-> ID = count++;
    this-> name = name;
    this-> type = type;
    this-> quantity = quantity;
    this-> count++;
}

void Item ::  set_name(string name){
    this-> name =  name;
}

string Item ::  get_name() const{
    return this-> name;
}

void Item :: set_type(string type){
    this-> type = type;
}

string Item :: get_type() const{
    return this-> type;
}

void  Item :: set_quantity(int quantity){
    this-> quantity =  quantity;
}

int Item :: get_quantity() const{
    return this-> quantity;
}

void Item :: displayInfo() const{
    std :: cout << "ID: " << this-> ID << std :: endl;
    std :: cout << "Name: " << this-> name << std :: endl;
    std :: cout << "Type: " << this-> type << std :: endl;
    std :: cout << "Quantity: " << this-> quantity << std :: endl;
}

Tool :: Tool(): Item(){
    this-> durability = 0;
}

Tool :: Tool( std :: string name, int quantity, int durability) : Item( name, "tools",quantity){
    this-> durability = durability;
}

void Tool :: set_durability(int durability){
    this-> durability = durability;
}
int Tool :: get_durability() const{
    return this-> durability;
}

void Tool :: displayInfo() const{
    Item :: displayInfo();
    std :: cout << "Durability: " << this-> durability << std :: endl;
}

NonTool :: NonTool() : Item (){
    this-> variant = "novariant";
}

NonTool :: NonTool(std :: string name, int quantity, std :: string variant) : Item(name,"nontools",quantity){
    this-> variant = variant;
}

void NonTool :: set_variant(std :: string variant){
    this-> variant = variant;
}

string NonTool :: get_variant() const{
    return this-> variant;
}

void NonTool :: displayInfo() const{
    Item :: displayInfo();
    std :: cout << "Variant: " << this-> variant << std :: endl;
}

void NonTool::operator=(const NonTool& nt){
    this->set_name(nt.get_name());
    this->set_quantity(nt.get_quantity());
    this->set_type(nt.get_type());
    this->set_variant(nt.get_variant());
}

void Tool::operator=(const Tool& t){
    this->set_name(t.get_name());
    this->set_quantity(t.get_quantity());
    this->set_type(t.get_type());
    this->set_durability(t.get_durability());
}
