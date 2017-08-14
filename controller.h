#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
private:
  bool active = true;
  int keys = 0;
  void (**funcData)(Controller*);
  int *constData;
public:
  Controller(int* m_constData, void (**m_funcData)(Controller*), int m_keys);
  ~Controller();
  void scan();
  inline bool GetActivity() { return active; }
  inline void SetActivity(bool m_active) { active = m_active; }
};

#endif // CONTROLLER_H
