#include "role.h"

role::role(int ID, int likeHero) {
    this->ID = ID;
    this->likeHero = likeHero;
}

void role::likechange(int more) {
    likeHero += more;
}

role::~role() {}

mainrole::mainrole(int ID, int likeHero, int body, int IQ) 
: role(likeHero) {
    this->body = body;
    this->IQ = IQ;
}

mainrole::~mainrole() {}