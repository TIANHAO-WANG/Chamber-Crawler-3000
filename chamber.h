#ifndef __CHAMBER_H__
#define __CHAMBER_H__

#include <vector>
class Item;
class Enemy;
class Cell;

class Chamber{
   int size;
   std::vector <Cell *>cells;
   Cell *randCell();

   /*
    std::vector <item *>;
    std::vector <Potion *>;
    std::vector <Treasure *>;
    */

public:
   Chamber(int size);
   void addCell(Cell *);
   void addEnemy();
   void addPotion();
   void addGold();
};
#endif
