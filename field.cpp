#include "field.h"
#include <iostream>

Field::Field() {
  std::cout << "Object Field created" << std::endl;
}

Field::~Field() {
  //
}

void Field::import(char** tab) {
  this->tab = tab;
}

void Field::print(char symbol, Point coords) {
  //
}

void Field::printStr(char* str, Point coords) {
  //
}

void Field::createWindow(Point min, Point max, char bg) {
  //
}
