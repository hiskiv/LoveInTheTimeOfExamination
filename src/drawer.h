#ifndef _DRAWER_H_
#define _DRAWER_H_
#include "narrator.h"

class drawer{
private:
	int resolutionX, resolutionY;
public:
	drawer(int x = 1080, int y = 720);
    void texting(dialogue D, int x = 100, int y = 600);
	void drawSpeaker(int speaker);
	void drawDateTime(int month, int day, int time);
};

#endif