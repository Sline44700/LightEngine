#ifndef WALL_H
#define WALL_H
#include "map.h"
#include "map.cpp"

class Wall : public MapObj {
public:
//  Wall(Map* map, Point coords) : MapObj(map, coords) {}
  using MapObj::MapObj;
//  Wall::Wall();
};

#endif // WALL_H
