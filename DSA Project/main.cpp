#pragma once
#include"Tests.h"
#include<Windows.h>

int main() {
	Tests t;
	t.runTests();
	
	SortedMap sm;
	sm.init();
	Controller ctrl(sm, 20);
	UI ui(ctrl);
	ui.Run();
	system("pause");
	return 0;
	
}