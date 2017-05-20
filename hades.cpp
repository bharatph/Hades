#define HADES_MAIN
#include <iostream>

#define ENABLE_LOG
#include "logc.h"

const char *TAG = "HADES";

void load_gui(){
	
}

int main(int argc, char *argv[]){
	log_inf(TAG, "starting Daemon");
	load_gui();
	return 0;
}
