#include <cstdlib>
#include <iostream>
#include "subject.h"
#include "observer.h"
#define TD 0
using namespace std;

void Subject::notifyPlayerMove(){
    observers[TD]->displayPlayerMove();
}

void Subject::notifyPlayerAttack(int damage){
    observers[TD]->displayPlayerAtk(damage);
}

void Subject::notifyEnemyAttack(std::shared_ptr<Enemy> e, int damage){
	observers[TD]->displayEnemyAtk(e, damage);
}

void Subject::notifyMiss(){
	observers[TD]->displayMiss();
}

void Subject::notifyDead(){
    observers[TD]->displayDead();
}
 

void Subject::attach(std::shared_ptr<observer> o) { observers.emplace_back(o); }


/*
void Subject::notifyObservers(){
   for(auto ob:observers) ob->notify();
}










