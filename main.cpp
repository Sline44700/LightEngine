#include <iostream>
#include "defines.h"
#include "field.h"
#include "field.cpp"
#include "map.h"
#include "map.cpp"
#include "mapobj.cpp"
//#include "wall.h"
//#include "wall.cpp"

using namespace std;

int main(void) {
  Field field;
  Point start = {0, 0};
  Point end = {32, 32};
  Map map(end);
//  Wall w(&map, start);

  cout << "Light Engine v" << VERSION << endl;
//  field->import(map->build(start, end));

  return 0;
}

