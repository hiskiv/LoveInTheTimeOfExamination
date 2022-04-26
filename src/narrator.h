#ifndef _NARRATOR_H_
#define _NARRATOR_H_
#include "nlohmann/json.hpp"

struct dialogue{
    int speaker;
    int hasBranch;
    std::string text;
    std::vector<std::string> branches;
};

class narrator{
private:
    int chapterID;
    int plotPos;
    nlohmann::json currentJson;
public:
    narrator();
    int endOfChap();
    dialogue narrate();
    void openChapter(int chapID);
    void branch(int choice);
};
#endif
