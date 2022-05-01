#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <graphics.h>
#include <conio.h>
#include "controller.h"
#include "narrator.h"
using namespace std;

controller::controller() {
	chapterID = 1;
	month = 5;
	day = 28;
	time = 0; // initially morning
}

// suppose our story only happens in May and June
void controller::timePass() {
	time++;
	if (time == 4) {
		day++;
		if (month == 5 && day == 32) {
			month++;
			day = 1;
		} else if (month == 6 && day == 31) {
			month++;
			day = 1;
		}
	}
}

// proceeds a piece of plots
// during this process, the player can only read the plots and make their choices
// they can't move their charater around the map surrounding
void controller::plotting(int diaID) {
	narrator Nar(chapterID);
	bool flag = 1;
	while (1) {
		dialogue D;
		if(flag) D = Nar.narrate(diaID), flag = 0;
		else D = Nar.narrate();
		Draw.drawSpeaker(D.speaker);
		Draw.texting(D, 100, 600);
		if (D.hasBranch) {
			char move = _getch();
			while (move < '0' || move > '9') move = _getch();
			int sel = move - '0';
			Nar.branch(sel - 1);
		}
		else {
			while (1) {
				char val = _getch();
				if (val == 13) break;
			}
		}
		if (D.isfinish || Nar.endOfChap()) break;
	}
	Draw.drawSpeaker(0);
	Draw.clearTexting();
}

void controller::game() {
	Draw.drawDateTime(month, day, time);
	Draw.drawMap(0);
	heroX = 3, heroY = 6, heroDir = 0;
	Draw.drawModel(0, heroDir, heroX, heroY);
	plotting(0);
}