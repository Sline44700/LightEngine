#pragma comment(lib, "User32.lib")
#include "controller.h"
#include <windows.h>
#include <iostream>

Controller::Controller(int* m_constTab, void (** m_funcTab)(Controller*), int m_keys) {
  funcTab = m_funcTab;
  constTab = m_constTab;
  keys = m_keys;
  // проверка на правильность этих самых функций
  // например, они должны иметь равные размеры
}

Controller::~Controller() {
  //
}

void Controller::scan() {
  // if (!active), say that not active;
  while (active) {
    for (auto i = 0; i < keys; i++)
      if (GetAsyncKeyState(constTab[i]) & 1) {
        funcTab[i](this);
        SetActivity(false);
      }
  }
}
