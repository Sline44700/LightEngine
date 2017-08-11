#include "field.h"
#include <iostream>

Field::Field() {
  tab = new char*[32];
  for (auto x = 0; x < 32; x++) {
    tab[x] = new char[32];
    for (auto y = 0; y < 32; y++)
      tab[x][y] = ' ';
  }
//  std::cout << "Object Field created" << std::endl;
}

Field::~Field() {
//  std::cout << "Field deconstructed" << std::endl;
  //
}

void Field::fill() {
  //
}

void Field::import(char** m_tab) {
  for (auto x = 0; x <= 16; x++)
    for (auto y = 0; y <= 16; y++)
      tab[x][y] = m_tab[x][y];
}

void Field::refresh() {
  for (auto x = 0; x <= 16; x++) {
    for (auto y = 0; y <= 16; y++)
      print(tab[x][y], Vector(x + 1, y + 2));
  }
}

void Field::setCursorPos(Vector pos) {
  cursorPos.X = pos.x;
  cursorPos.Y = pos.y;
  SetConsoleCursorPosition(handle, cursorPos);
}

void Field::print(char symbol, Vector coords) {
  setCursorPos(coords);
  std::cout << symbol;
}

void Field::printStr(const char* str, Vector coords) {
  setCursorPos(coords);
  std::cout << str;
}

void Field::createWindow(Vector min, Vector max, char bg) {
  //
}
