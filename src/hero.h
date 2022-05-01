#ifndef _HERO_H_
#define _HERO_H_
#include <string>
#include <map>
using namespace std;

class hero
{
private:
    int study, tiring, courage, appearance;
    int character;
	int x, y, dir; // the coordinates on the map and the facing direction
    static map<string, int> getchara;
public:
    hero(const string &schara = "内向");
    ~hero();
};

#endif