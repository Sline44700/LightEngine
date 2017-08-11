#ifndef FIELD_H
#define FIELD_H
#include "structures.h"
#include <iostream>

class Field {
private:
  char** tab;
  Vector size;
  void fill();

public:
  Field();
  ~Field();
  void import(char** m_tab);
  void refresh();
  void print(char symbol, Vector coords);
  void printStr(char* str, Vector coords);
  void createWindow(Vector min, Vector max, char bg);
};

#endif // FIELD_H
