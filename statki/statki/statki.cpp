#define _CRTDBG_MAP_ALLOC
#include<cstdlib>
#include<crtdbg.h>
#include"Game.h"



int main() {

	Game *g = new Game();
	g->runGame();
	delete g;

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;

}