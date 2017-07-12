#define HADES "HADES"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <thread>

#include "clog.h"
#include "shell.h"
#include "ui.h"
int help(int, char **);

//Fl_OpenCV *open_highgui;

job jobs[] = {
	{"help", "prints this help line", help}
};

int jlen =  sizeof(jobs)/sizeof(job);

int help(int count, char **args){
	sh_help(jobs, jlen);
	return 0;
}

int main(int argc, char *argv[]){
	std::ios_base::sync_with_stdio(false);
	log_inf(HADES, "Starting GUI");
	load_ui(jobs, jlen);
	return 0;
}
