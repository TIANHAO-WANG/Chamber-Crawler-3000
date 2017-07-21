#include <cmath>
#include "player.h"
#include "character.h"
using namespace std;

Player::Player(int HP, int atk, int def, int maxHP, Floor* f, std::string race)
: Character{HP, atk, def}, maxHP{maxHP}, atkEffect{0}, defEffect{0}, f{f},
score{0}, race{race} {}

int Player::getMaxHP() const { return maxHP; }

void Player::addHp(int hpEffect) {
  HP = (getHP() + hpEffect > maxHP) ? maxHP : getHP() + hpEffect;
}



// Basic Implementation
void Player::usePotion(Potion* p){
   string type = p->getType();
   int effect =p->getEffect();
  if (type == "Hp") addHp(effect);
  else if (type == "Atk") atkEffect += (effect);
  else if (type == "Def") defEffect += (effect);
}

void Player::moveTo(Dir dir){
    Character::moveTo(dir);
    getPos()->notifyPlayerMove(dir);
}




int Player::realAtk(){
  return (getAtk() + atkEffect < 0) ? 0 : getAtk() + atkEffect;
}

int Player::realDef(){
  return (getDef() + defEffect < 0) ? 0 : getDef() + defEffect;
}

int Player::calcDamage(Enemy* defender){
    return ceil((100/(100+defender->getDef())) * this->realAtk());
}


void Player::attack(Enemy* enemy){
	int damage = calcDamage(enemy);
	enemy->getHurt(damage);
	getPosition()->notifyPlayerAttack(damage);
}

void Player::attack(Halfling* h){
	int notMiss = rand() % 2;  
	if (notMiss){
		int damage = calcDamage(h);
		h->getHurt(damage);
		getPosition()->notifyPlayerAttack(damage);
	}
	else{
		getPosition()->notyfyMiss();
	}
}


void Player::beAtkBy(Enemy* enemy){
	enemy->attack(this);
}




int showScore(){ return score; }

void incScore(int value){ score += value; }

void Player::PickGold(Treasure* gold){
	intScore(gold->getValue());
}

void Player::roundChange(){}

Player::~Player() {}
