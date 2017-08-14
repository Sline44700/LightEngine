#include "field.h"
#include <iostream>

Field::Field(Vector m_size) {
  size = m_size;
  data = new char*[size.x];
  for (auto x = 0; x <= size.x; x++) {
    data[x] = new char[size.y];
    for (auto y = 0; y <= size.y; y++)
      data[x][y] = ' ';
  }

  cfi.cbSize = sizeof(cfi);
  cfi.nFont = 0;
  cfi.dwFontSize.X = 16;
  cfi.dwFontSize.Y = 16;
  cfi.FontFamily = FF_DONTCARE;
  cfi.FontWeight = FW_NORMAL;
  std::wcscpy(cfi.FaceName, L"Courier New"); // Consolas
  SetCurrentConsoleFontEx(handle, FALSE, &cfi);
  info.dwSize = 1;
  info.bVisible = true;
  SetConsoleCursorInfo(handle, &info);
//  std::cout << "Object Field created" << std::endl;
}

Field::~Field() {
//  std::cout << "Field deconstructed" << std::endl;
  //
}

void Field::fill() {
  //
}

void Field::import(char** m_data, Vector m_size) {
  for (auto x = 0; x <= size.x; x++)
    for (auto y = 0; y <= size.y; y++)
      data[x][y] = m_data[x][y];
}

void Field::refresh() {
  setColor(HIGH_CYAN);
  printStr(strcat(strcpy(new char[32], "Light Engine v"), VERSION), Vector(0, 0));
  setColor(WHITE);

  for (auto x = 0; x <= size.x; x++)
    for (auto y = 0; y <= size.y; y++) {
      if (data[x][y] != '.') // kostyl
        print(data[x][y], Vector(x + 1, y + 2));
      else
        print(data[x][y], Vector(x + 1, y + 2), GRAY);
    }
}

void Field::setCursorPos(Vector pos) {
  cursorPos.X = pos.x;
  cursorPos.Y = pos.y;
  SetConsoleCursorPosition(handle, cursorPos);
}

void Field::setColor(int color) {
  SetConsoleTextAttribute(handle, color);
}

void Field::print(char symbol) {
  std::cout << symbol;
}

void Field::setCursorVisibility(bool visibility) {
  info.dwSize = 1;
  info.bVisible = visibility;
  SetConsoleCursorInfo(handle, &info);
}

void Field::setCursorThickness(int thickness) {
  info.dwSize = thickness;
  SetConsoleCursorInfo(handle, &info);
}

void Field::print(char symbol, Vector pos) {
  setCursorPos(pos);
  print(symbol);
}

void Field::print(char symbol, Vector pos, int color) {
  setColor(color);
  print(symbol, pos);
  setColor(WHITE);
}

void Field::print(char symbol, int color) {
  setColor(color);
  print(symbol);
  setColor(WHITE);
}

void Field::printStr(char* str) {
  std::cout << str;
}

void Field::printStr(char* str, Vector pos) {
  setCursorPos(pos);
  printStr(str);
}

void Field::printStr(char* str, Vector pos, int color) {
  setColor(color);
  printStr(str, pos);
  setColor(WHITE);
}

void Field::printStr(char* str, int color) {
  setColor(color);
  printStr(str);
  setColor(WHITE);
}

void Field::createWindow(Vector min, Vector max, char bg) {
  //
}

Window::Window(Vector min, Vector max) {
  //
}

Window::Window(Vector min, Vector max, char bg) {
  //
}

Window::~Window() {
  //
}
