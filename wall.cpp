#include "wall.h"

Wall::Wall(Map* map, Vector coords) : MapObj(map, coords) {
  setSymbol('w');
//  MapObj::MapObj(map, coords);
}

