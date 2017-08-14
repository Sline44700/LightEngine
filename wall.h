#ifndef WALL_H
#define WALL_H
#include "map.h"
#include "structures.h"

class Wall : public MapObj {
public:
//  using MapObj::MapObj;
//  Wall(Map* map, Vector pos) : MapObj(map, pos) {}
  Wall(Map* map, Vector pos);
//  Wall::Wall();
};

#endif // WALL_H
