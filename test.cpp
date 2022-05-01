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
#include "src/controller.h"
using namespace std;

int main(){
    SetConsoleOutputCP(65001);  //  encode
    narrator Nar;
	controller ctrl;
	ctrl.game();
    return 0;
}
