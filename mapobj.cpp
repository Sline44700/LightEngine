#include "mapobj.h"
#include "map.h"

MapObj::MapObj(Map *m_map, Vector m_pos) {
  pos = m_pos;
  m_map->addObj(this, pos);
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
