#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include <vector>

struct Info;
class Observer;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach(Observer *o);  
  void notifyMove(Player* p, string dir);  //to move
  void notifyMove(Enemy* e);
  void notifyEnemy(Player* player, int dir);
  void notifyMiss();
  void notifyDead();
  virtual Info getInfo() const = 0;
  virtual ~Subject() = default;
};

#endif
