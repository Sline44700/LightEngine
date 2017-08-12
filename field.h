#ifndef FIELD_H
#define FIELD_H
#include "structures.h"
#include <iostream>
#include <cwchar>
#include <windows.h>

class Field {
private:
  char** tab;
  Vector size;
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  CONSOLE_FONT_INFOEX cfi;
  void fill();

public:
  Field(Vector m_size);
  ~Field();
  void import(char** m_tab, Vector m_size);
  void refresh();
  void setCursorPos(Vector pos);
  void setColor(int color);
  void setFont(Vector size);
  void print(char symbol, Vector coords);
  void print(char symbol, Vector coords, int color);
  void printStr(const char* str, Vector coords);
  void printStr(const char* str, Vector coords, int color);
  void createWindow(Vector min, Vector max, char bg);
};

#endif // FIELD_H
