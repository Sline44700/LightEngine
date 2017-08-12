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

  cfi.cbSize = sizeof(cfi);
  cfi.nFont = 0;
  cfi.dwFontSize.X = 14;
  cfi.dwFontSize.Y = 14;
  cfi.FontFamily = FF_DONTCARE;
  cfi.FontWeight = FW_NORMAL;
  std::wcscpy(cfi.FaceName, L"Courier New"); // Consolas
  SetCurrentConsoleFontEx(handle, FALSE, &cfi);
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
  setColor(HIGH_CYAN);
  printStr(strcat(strcpy(new char[32], "Light Engine v"), VERSION), Vector(0, 0));
  setColor(WHITE);

  for (auto x = 0; x <= size.x; x++)
    for (auto y = 0; y <= size.y; y++)
      print(tab[x][y], Vector(x + 1, y + 2));
}

void Field::setCursorPos(Vector pos) {
  cursorPos.X = pos.x;
  cursorPos.Y = pos.y;
  SetConsoleCursorPosition(handle, cursorPos);
}

void Field::setColor(int color) {
  SetConsoleTextAttribute(handle, color);
}

void Field::print(char symbol, Vector coords) {
  setCursorPos(coords);
  std::cout << symbol;
}

void Field::print(char symbol, Vector coords, int color) {
  setColor(color);
  print(symbol, coords);
  setColor(WHITE);
}

void Field::printStr(const char* str, Vector coords) {
  setCursorPos(coords);
  std::cout << str;
}

void Field::printStr(const char* str, Vector coords, int color) {
  setColor(color);
  printStr(str, coords);
  setColor(WHITE);
}

void Field::createWindow(Vector min, Vector max, char bg) {
  //
}
