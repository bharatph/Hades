#ifndef HADES_D
#define HADES_D

#include <iostream>

#define LOG
#include "log.h"

int main(int argc, char *argv[]){
	TAG("Hades Daemon")(LOG_INIT | LOG_COLOR);
	logger("starting Daemon")(INFO);
	return 0;
}
#endif
