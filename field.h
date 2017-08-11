#ifndef FIELD_H
#define FIELD_H
#include "structures.h"
#include <iostream>
#include <windows.h>

class Field {
private:
  char** tab;
  Vector size;
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  void fill();

public:
  Field();
  ~Field();
  void import(char** m_tab);
  void refresh();
  void setCursorPos(Vector pos);
  void print(char symbol, Vector coords);
  void printStr(const char* str, Vector coords);
  void createWindow(Vector min, Vector max, char bg);
};

#endif // FIELD_H
