#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"
#include "narrator.h"
using namespace std;
using json = nlohmann::json;

narrator::narrator() {
	chapterID = 1;
	plotPos = 0;
	openChapter(1);
}

narrator::narrator(int chapID){
    chapterID = chapID;
    plotPos = 0;
    openChapter(chapID);
}

//judge if current chapter has come to an end
int narrator::endOfChap(){
    if(currentJson["dialogue"].size() == plotPos) return 1;
    else return 0;
}

// moving forward by one dialogue
// if pos is not -1, then begin from the position specified
dialogue narrator::narrate(int pos){
	if (pos != -1) plotPos = pos;
    json dia = currentJson["dialogue"][plotPos];
    dialogue res;
    res.text = dia.at("content");
    // cout << "DDD: " << dia.at("content") << endl;
    res.speaker = dia.at("speaker");
	res.isfinish = dia.at("finish");
    res.branches.clear();
    res.hasBranch = 0;
    for(int i=0;i<dia.at("branch").size();i++){
        res.hasBranch = 1;
        res.branches.push_back(dia.at("branch")[i].at("condition"));
    }
	if (dia.at("jump") != -1) plotPos = dia.at("jump");
	else plotPos++;
    return res;
}

// open a chapter from corresponding json file
void narrator::openChapter(int chapID){
    chapterID = chapID;
    char filename[25];
    sprintf(filename, "./plots/chap%d.json", chapID);
    ifstream jfile(filename);
    jfile >> currentJson;
}

// branch if there are choices
// here branch should have another parameter of class player,
// specifying whether the player can choose some of choices
void narrator::branch(int choice){
    // because we increase it before in narrate
    json dia = currentJson["dialogue"][plotPos-1];
    plotPos = dia["branch"][choice].at("branchPos");
}