#include "Item.h"
#include <iostream>

int Item :: ID = 0;
Item :: Item(){
    this-> ID = ID+ 1;
    this-> name = "noname";
    this-> type = "notype";
    this-> quantity = 0;
}

Item :: Item( string name, string type, int quantity){
    this-> ID = ID+1;
    this-> name = name;
    this-> type = type;
    this-> quantity = quantity;
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

int Item::get_ID() const {
    return this->ID;
}

int Item::get_durability() const{
    return 0;
}
void Item::set_durability(int durability){

}
std :: string Item::get_variant() const{
    return NULL;
}
void Item::set_variant(std :: string variant){

}

//default durability = 10
Tool :: Tool(): Item(){
    this-> durability = 10;
}

Tool :: Tool( std :: string name, int quantity) : Item( name, "TOOL",quantity){
    this-> durability = 10;
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

NonTool :: NonTool(std :: string name, int quantity, std :: string variant) : Item(name,"NONTOOL",quantity){
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
