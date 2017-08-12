#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
private:
  bool active = true;
  int keys = 0;
  void (**funcTab)(Controller*);
  int *constTab;
public:
  Controller(int* m_constTab, void (**m_funcTab)(Controller*), int m_keys);
  ~Controller();
  void scan();
  inline bool GetActivity() { return active; }
  inline void SetActivity(bool m_active) { active = m_active; }
};

#endif // CONTROLLER_H
