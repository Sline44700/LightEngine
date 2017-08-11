#include "mapobj.h"
#include "map.h"

MapObj::MapObj(Map *m_map, Point m_coords) {
  m_map->addObj(this, coords);
  coords = m_coords;
}

MapObj::~MapObj() {
  delete map;
}

void MapObj::move(int side, int steps) {
  //
}

/*Floor::Floor() {
  symbol = ' ';
  impenetrable = false;
  MapObj();
}

Floor::~Floor() {
  ~MapObj();
}*/
