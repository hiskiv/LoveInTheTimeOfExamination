#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "drawer.h"

class controller {
private:
	int chapterID;
	int month, day;
	int time; // 0: morning, 1: afternoon, 2: evening, 3: midnight (occasionally use)
	int heroX, heroY, heroDir; // the coordinate and facing direction of the hero
	drawer Draw;
public:
	controller();
	void timePass();
	void plotting(int diaID);
	void game();
};

#endif