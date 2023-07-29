#include "treasure.h"

Treasure::Treasure(int value): value{value} {}
Treasure::~Treasure() {}
int Treasure::getValue() {return value;}
void Treasure::setValue(int value) {value = value;}
