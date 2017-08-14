#include "wall.h"

Wall::Wall(Map* map, Vector pos) : MapObj(map, pos) {
  setSymbol('|');
//  MapObj::MapObj(map, pos);
}

