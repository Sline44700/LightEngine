#pragma comment(lib, "User32.lib")
#include "controller.h"
#include <windows.h>
#include <iostream>

Controller::Controller(int* m_constData, void (** m_funcData)(Controller*), int m_keys) {
  funcData = m_funcData;
  constData = m_constData;
  keys = m_keys;
  // проверка на правильность этих самых функций
  // например, они должны иметь равные размеры
}

Controller::~Controller() {
  //
}

void Controller::scan() {
  // if (!active), say that not active;
  // or call onExitFunc
  while (active) {
    for (auto i = 0; i < keys; i++)
      if (GetAsyncKeyState(constData[i]) & 1) {
        funcData[i](this);
      }
  }
}
