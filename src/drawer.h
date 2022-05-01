#ifndef _DRAWER_H_
#define _DRAWER_H_
#include "narrator.h"

class drawer{
private:
	const int blockSize = 50;
	int offsetX, offsetY;
	int resolutionX, resolutionY;
public:
	drawer(int x = 1080, int y = 720);
	~drawer();
    void texting(dialogue D, int x = 100, int y = 600);
	void clearTexting(int x = 100, int y = 600);
	void drawSpeaker(int speaker);
	void drawDateTime(int month, int day, int time);
	void drawMap(int mapID);
	void drawModel(int speaker, int dir, int x, int y); // here x and y are coordinates of the map
};

#endif