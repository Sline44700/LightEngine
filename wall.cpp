#include "wall.h"

Wall::Wall(Map* map, Point coords) : MapObj(map, coords) {
  setSymbol('w');
//  MapObj::MapObj(map, coords);
}

