#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "narrator.h"

class controller {
private:
	int month, day;
	int time; // 0: morning, 1: afternoon, 2: evening, 3: midnight (occasionally use)
	narrator Nar;
public:
	controller();
	void dayPass();

};

#endif