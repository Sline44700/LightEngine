#ifndef FIELD_H
#define FIELD_H
#include "structures.h"
#include <iostream>

class Field {
private:
  char** tab;
  Point size;
  void fill();

public:
  Field();
  ~Field();
  void import(char** m_tab);
  void refresh();
  void print(char symbol, Point coords);
  void printStr(char* str, Point coords);
  void createWindow(Point min, Point max, char bg);
};

#endif // FIELD_H
