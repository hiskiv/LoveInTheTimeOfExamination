#include <string>
#include <map>
#include "hero.h"
using namespace std;

hero::hero(const string &schara) {
    study = 20;
    tiring = 0;
    courage = 0;
    appearance = 20;
    character = getchara[schara];
}

hero::~hero() {}

map<string, int>hero::getchara = {
    {"内向", 0}, {"外向", 1}
};