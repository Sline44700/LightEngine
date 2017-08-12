#include <conio.h>
#include <string.h>
#include "defines.h"
#include "field.h"
#include "field.cpp"
#include "map.h"
#include "map.cpp"
#include "mapobj.cpp"
#include "wall.h"
#include "wall.cpp"
#include "controller.h"
#include "controller.cpp"
#include <windows.h>
#include <iostream>

//using namespace std;
// TODO: 1) load/save
//       2) Controller
//       3) Config
//       4) Console
//       5) Camera?

void Left(Controller* ctrl);
void Right(Controller* ctrl);
void Up(Controller* ctrl);
void Down(Controller* ctrl);
void Esc(Controller *ctrl);

Vector player(1, 1);
Map* map2 = new Map(strcpy(new char[32], "maps/easy.txt"));
Vector size = map2->getSize();
Field* field2 = new Field(size);

int main(int argc, char *argv[]) {
/*  Field* field = new Field(Vector(16, 16));
  Map* map = new Map(Vector(17, 17));

  for (auto x = 0; x <= 16; x++)
    for (auto y = 0; y <= 16; y++)
      if (x == 0 || y == 0 || x == 16 || y == 16)
        new Wall(map, Vector(x, y));

  field->import(map->build(Vector(0, 0), Vector(16, 16)), Vector(16, 16));
  field->refresh();
  field->print('@', Vector(2, 3), HIGH_MAGENTA);
  field->printStr(strcpy(new char, "VIXODA HET"), Vector(4, 10), HIGH_RED);
  field->setCursorPos(Vector(0, 20));

  getch();
//  delete map;
//  delete field;
  system("cls");*/

  field2->import(map2->build(Vector(0, 0), size), size);
  field2->refresh();
  field2->print('@', Vector(2, 3), HIGH_MAGENTA);
  field2->print('+', Vector(9, 10), HIGH_RED);
  field2->printStr(strcpy(new char, "arrows = moves"), Vector(0, 13));
  field2->printStr(strcpy(new char, "esc = quit"), Vector(0, 14));

  int constTab[] = {VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_ESCAPE};
  void (*funcTab[])(Controller*) = {Left, Right, Up, Down, Esc};
  Controller ctrl(constTab, funcTab, 5);
  ctrl.scan();

  getch();

  return 0;
}

void Left(Controller* ctrl) {
  if (!map2->existObj(Vector(player.x - 1, player.y))) {
    field2->print('.', Vector(player.x + 1, player.y + 2), GRAY);
    player.x--;
    field2->print('@', Vector(player.x + 1, player.y + 2), HIGH_MAGENTA);
  }
  if (player.x == 8 && player.y == 8) return;
  ctrl->scan();
}

void Right(Controller* ctrl) {
  if (!map2->existObj(Vector(player.x + 1, player.y))) {
    field2->print('.', Vector(player.x + 1, player.y + 2), GRAY);
    player.x++;
    field2->print('@', Vector(player.x + 1, player.y + 2), HIGH_MAGENTA);
  }
  if (player.x == 8 && player.y == 8) return;
  ctrl->scan();
}

void Up(Controller* ctrl) {
  if (!map2->existObj(Vector(player.x, player.y - 1))) {
    field2->print('.', Vector(player.x + 1, player.y + 2), GRAY);
    player.y--;
    field2->print('@', Vector(player.x + 1, player.y + 2), HIGH_MAGENTA);
  }
  if (player.x == 8 && player.y == 8) return;
  ctrl->scan();
}

void Down(Controller* ctrl) {
  if (!map2->existObj(Vector(player.x, player.y + 1))) {
    field2->print('.', Vector(player.x + 1, player.y + 2), GRAY);
    player.y++;
    field2->print('@', Vector(player.x + 1, player.y + 2), HIGH_MAGENTA);
  }
  if (player.x == 8 && player.y == 8) return;
  ctrl->scan();
}

void Esc(Controller* ctrl) {
  std::cout << "Esc" << std::endl;
}
