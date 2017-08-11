#ifndef WALL_H
#define WALL_H
#include "map.h"
#include "structures.h"

class Wall : public MapObj {
public:
//  using MapObj::MapObj;
//  Wall(Map* map, Vector coords) : MapObj(map, coords) {}
  Wall(Map* map, Vector coords);
//  Wall::Wall();
};

#endif // WALL_H
