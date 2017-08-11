#include "wall.h"

Wall::Wall(Map* map, Vector coords) : MapObj(map, coords) {
  setSymbol('|');
//  MapObj::MapObj(map, coords);
}

