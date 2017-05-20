#define HADES_MAIN
#include <iostream>

#define LOG
#include "loggerc/logc.h"

const char *TAG = "HADES";

void load_gui(){
	
}

int main(int argc, char *argv[]){
	log_inf(TAG, "starting Daemon");
	load_gui();
	return 0;
}
