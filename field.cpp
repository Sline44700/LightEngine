#include "field.h"
#include <iostream>

Field::Field() {
  tab = new char*[32];
  for (auto x = 0; x < 32; x++) {
    tab[x] = new char[32];
    for (auto y = 0; y < 32; y++)
      tab[x][y] = ' ';
  }
  std::cout << "Object Field created" << std::endl;
}

Field::~Field() {
  std::cout << "Field deconstructed" << std::endl;
  //
}

void Field::fill() {
  //
}

void Field::import(char** m_tab) {
  for (auto x = 0; x < 32; x++)
    for (auto y = 0; y < 32; y++)
      tab[x][y] = m_tab[x][y];
}

void Field::refresh() {
  for (auto x = 0; x < 16; x++) {
    for (auto y = 0; y < 32; y++)
      std::cout << tab[x][y];
    std::cout << std::endl;
  }
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
