#include "field.h"
#include <iostream>

Field::Field(Vector m_size) {
  size = m_size;
  tab = new char*[size.x];
  for (auto x = 0; x <= size.x; x++) {
    tab[x] = new char[size.y];
    for (auto y = 0; y <= size.y; y++)
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

void Field::import(char** m_tab, Vector m_size) {
  for (auto x = 0; x <= size.x; x++)
    for (auto y = 0; y <= size.y; y++)
      tab[x][y] = m_tab[x][y];
}

void Field::refresh() {
  char str[32];

  strcpy(str, "Light Engine v");
  printStr(strcat(str, VERSION), Vector(0, 0));

  for (auto x = 0; x <= size.x; x++) {
    for (auto y = 0; y <= size.y; y++)
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
