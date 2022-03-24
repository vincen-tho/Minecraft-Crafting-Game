#include "Item.h"
#include <iostream>


Item :: Item(){
    this-> ID = 0;
    this-> name = "noname";
    this-> type = "notype";
}

Item :: Item(int ID, string name, string type){
    this-> ID = ID;
    this-> name = name;
    this-> type = type;
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

Tool :: Tool(int ID, std :: string name) : Item(ID , name, "TOOL"){
    this-> durability = 10;
}

void Tool :: set_durability(int durability){
    this-> durability = durability;
}
int Tool :: get_durability() const{
    return this-> durability;
}

NonTool :: NonTool() : Item (){
    this-> variant = "novariant";
}

NonTool :: NonTool(int ID, std :: string name, std :: string variant) : Item(ID, name,"NONTOOL"){
    this-> variant = variant;
}

void NonTool :: set_variant(std :: string variant){
    this-> variant = variant;
}

string NonTool :: get_variant() const{
    return this-> variant;
}

void NonTool::operator=(const NonTool& nt){
    this->set_name(nt.get_name());
    this->set_type(nt.get_type());
    this->set_variant(nt.get_variant());
}

void Tool::operator=(const Tool& t){
    this->set_name(t.get_name());
    this->set_type(t.get_type());
    this->set_durability(t.get_durability());
}
