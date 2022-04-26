#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "controller.h"
using namespace std;

controller::controller() {
	month = 5;
	day = 28;
	time = 0; // initially morning
}

// suppose our story only happens in May and June
void controller::dayPass() {
	day++;
	if (month == 5 && day == 32) {
		month++;
		day = 1;
	} else if (month == 6 && day == 31) {
		month++;
		day = 1;
	}
}