#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "../enemy.h"

class DragonHoard;
//does 50% more damage to goblins
class Dragon: public Enemy{
	std::shared_ptr<DragonHoard> hoard;
public:
	Dragon(std::shared_ptr<DragonHoard> hoard);
};

#endif
