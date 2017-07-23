#include "header.h"
using namespace std;

Treasure::Treasure(std::string type, int value)
	: type{type}, value{value} {}

string Treasure::getType() const { return type; }

int Treasure::getValue() const { return value; }

bool Treasure::isTreasure() { return true;}

char Treasure::symbol(){ return 'G';};

void Treasure::setDragon(){}

bool Treasure::canPickUp(){ return true;}

Treasure::~Treasure() {}
