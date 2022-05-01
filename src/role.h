#ifndef _ROLE_H_
#define _ROLE_H_

class role{
private:
    int ID;
    int likeHero;
public:
    role(int ID, int likeHero = 20);
    ~role();
    //  likeHero += more, more = 1 by default
    void likechange(int more = 1);
};

class mainrole : public role{
private:
    int body;
    int IQ;
    int mood;
public:
    mainrole(int ID, int likeHero = 20, int body = 20, int IQ = 100);
    ~mainrole();
};
#endif