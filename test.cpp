#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <windows.h>
#include <tchar.h>
#include "src/narrator.h"
#include "src/drawer.h"
using namespace std;

void string2tchar(string src, TCHAR* des) {
	for (int i = 0; i < src.size();i++) {
		des[i] = src[i];
	}
	des[src.size()] = 0;
}

void utf82unicode(string src, wchar_t* des);

int main(){
    SetConsoleOutputCP(65001);  //  encode
    narrator Nar;
	drawer Draw;
	Draw.drawDateTime(5, 7, 3);
    while(!Nar.endOfChap()){
        dialogue D = Nar.narrate();
		cout << D.text.size() << endl;
		if(D.speaker) Draw.drawSpeaker(D.speaker);
		Draw.texting(D, 100, 600);
        if(D.hasBranch){
            int move;
            scanf("%d", &move);
            Nar.branch(move-1);
        }else _getch();
    }
	closegraph();			// 关闭绘图窗口
    return 0;
}
