#include "bootpack.h"

void HariMain(void)
{
	int i, timer;
	timer = api_alloctimer();
	api_inittimer(timer, 128);
	int music[30] = {C,0,C,0,G,0,G,0,A,0,A,0,G,G,0,0,F,0,F,0,E,0,E,0,D,0,D,0,C,C};
	for (i = 0; i <= 30; i++) {
		api_beep(music[i]);
		api_settimer(timer, 30);	
		if (api_getkey(1) != 128) {
			break;
		}
	}
	api_beep(0);
	api_end();
}
