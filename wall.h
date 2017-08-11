#ifndef WALL_H
#define WALL_H
#include "map.h"

class Wall : public MapObj {
public:
//  using MapObj::MapObj;
//  Wall(Map* map, Point coords) : MapObj(map, coords) {}
  Wall(Map* map, Point coords);
//  Wall::Wall();
};

#endif // WALL_H
