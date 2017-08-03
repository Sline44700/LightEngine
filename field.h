#ifndef FIELD_H
#define FIELD_H
#include "structures.h"

class Field {
private:
  char** tab;
  Point size;
  void fill();

public:
  Field();
  void print(char symbol, Point coords);
  void printStr(char* str, Point coords);
  void createWindow(Point min, Point max, char bg);
};

#endif // FIELD_H
