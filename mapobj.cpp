#include "mapobj.h"
#include "map.h"

MapObj::MapObj(Map *m_map, Vector m_coords) {
  coords = m_coords;
  m_map->addObj(this, coords);
}

MapObj::~MapObj() {
//  delete map;
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
