#ifndef FIELD_H
#define FIELD_H
#include "structures.h"
#include <iostream>
#include <cwchar>
#include <windows.h>

class Field {
private:
  char** data;
  Vector size;
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD cursorPos;
  CONSOLE_FONT_INFOEX cfi;
  CONSOLE_CURSOR_INFO info;
  void fill();

public:
  Field(Vector m_size);
  ~Field();
  void import(char** m_data, Vector m_size);
  void refresh();
  void setCursorPos(Vector pos);
  void setColor(int color);
  void setFont(Vector size);
  void setCursorVisibility(bool visibility);
  void setCursorThickness(int thickness) ;
  void print(char symbol);
  void print(char symbol, Vector pos);
  void print(char symbol, Vector pos, int color);
  void print(char symbol, int color);
  void printStr(char* str);
  void printStr(char* str, Vector pos);
  void printStr(char* str, Vector pos, int color);
  void printStr(char* str, int color);
  void createWindow(Vector min, Vector max, char bg);
};

class Window {
private:
  Field* field;
  Vector min;
  Vector max;
  char bg;
public:
  Window(Vector min, Vector max);
  Window(Vector min, Vector max, char bg);
  ~Window();
  //
};

#endif // FIELD_H
