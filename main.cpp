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
// TODO: 1) load/save +
//       2) Controller +
//       2.5) Menu (посмотреть, как можно передать аргументы)
//       2.75) Player
//       3) Config
//       4) Console() ->
//          char data[CONSOLE_WIDTH][CONSONE_DEPTH];
//          char errors?
//          можно хранить в кодах
//          вызывается по нажатию `
//          char** GetData();
//       5) Camera?
//       cords => pos; tab => data +

void Move(Controller* ctrl, int x, int y);
void Left(Controller* ctrl) { Move(ctrl, -1, 0); }
void Right(Controller* ctrl) { Move(ctrl, 1, 0); }
void Up(Controller* ctrl) { Move(ctrl, 0, -1); }
void Down(Controller* ctrl)  { Move(ctrl, 0, 1); }
void Esc(Controller *ctrl) { ctrl->SetActivity(false); }

Vector player(1, 1);
Map* map2 = new Map(strcpy(new char[16], "maps/easy.txt"));
Vector size = map2->getSize();
Field* field2 = new Field(size);
int steps = 0;

void Easy(Controller *ctrl) { /*map2->load(strcpy(new char[16], "maps/easy.txt"));*/ ctrl->SetActivity(false); }
void Medium(Controller *ctrl) { map2->load(strcpy(new char[16], "maps/medium.txt")); ctrl->SetActivity(false); }
void Hard(Controller *ctrl) { map2->load(strcpy(new char[16], "maps/hard.txt")); ctrl->SetActivity(false); }

int main(int argc, char *argv[]) {
/*  Field* field = new Field(Vector(17, 17));
  Map* map = new Map(Vector(17, 17));

  for (auto x = 0; x <= 16; x++)
    for (auto y = 0; y <= 16; y++)
      if (x == 0 || y == 0 || x == 16 || y == 16)
        new Wall(map, Vector(x, y));

  field->import(map->build(Vector(0, 0), Vector(16, 16)), Vector(16, 16));
  field->refresh();
  field->print('@', Vector(2, 3), HIGH_MAGENTA);
  field->printStr(strcpy(new char[16], "VIXODA HET"), Vector(4, 10), HIGH_RED);
  field->setCursorPos(Vector(0, 20));

  getch();
//  delete map;
//  delete field;
  system("cls");*/

  field2->printStr(strcpy(new char[16], "1 = easy"), Vector(0, 0));
  field2->printStr(strcpy(new char[16], "2 = medium"), Vector(0, 1));
  field2->printStr(strcpy(new char[16], "3 = hard"), Vector(0, 2));
  getch();

  int menu_constData[] = {VK_HELP + 2, VK_HELP + 3, VK_HELP + 4};
  void (*menu_funcData[])(Controller*) = {Easy, Medium, Hard};
  Controller ctrl_menu(menu_constData, menu_funcData, 3);
  ctrl_menu.scan();
  system("cls");

  field2->setCursorVisibility(false);
  field2->import(map2->build(Vector(0, 0), size), size);
  field2->refresh();
  field2->print('@', Vector(2, 3), HIGH_MAGENTA);
  field2->print('+', Vector(size.x - 1, size.y - 1 + 1), HIGH_RED);
  field2->printStr(strcpy(new char[16], "arrows = moves"), Vector(0, size.y + 2 + 2));
  field2->printStr(strcpy(new char[16], "esc = quit"), Vector(0, size.y + 3 + 2));
  field2->printStr(strcpy(new char[16], "steps = "), Vector(0, size.y + 4 + 2));
  field2->printStr(strcpy(new char[16], itoa(steps, new char[5], 10)), Vector(8, size.y + 4 + 2));
//  field2->printStr(strcpy(new char[16], itoa(steps, new char[5], 10)), Vector(8, size.y + 4 + 2));

  int constData[] = {VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_ESCAPE};
  void (*funcData[])(Controller*) = {Left, Right, Up, Down, Esc};
  Controller ctrl(constData, funcData, 5);
  ctrl.scan();

  getch();
  std::cout << "Why is this not displayed?";
  getch();

  return 0;
}

void Move(Controller* ctrl, int x, int y) {
  if (!map2->existObj(Vector(player.x + x, player.y + y))) {
    field2->print('.', Vector(player.x + 1, player.y + 2), GRAY);
    player.x += x;
    player.y += y;
    steps++;
    field2->printStr(strcpy(new char[16], itoa(steps, new char[5], 10)), Vector(8, size.y + 4 + 2));
    field2->print('@', Vector(player.x + 1, player.y + 2), HIGH_MAGENTA);
  }
  if (player.x == size.x - 2 && player.y == size.y - 2) ctrl->SetActivity(false);
}
