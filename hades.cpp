#define HADES_MAIN
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "Fl_OpenCV.H"
#include <thread>

#define ENABLE_LOG
#include "logc.h"

const char *TAG = "HADES";

Fl_Window *root = nullptr;
Fl_OpenCV *open_highgui;
pthread_t ui_thread;

int start_gui(){
	root -> show();
	return Fl::run();
}


void *load_gui(void *opt){
	root = new Fl_Window(0, 0, 256, 256, "Hades");
	open_highgui = new Fl_OpenCV(0,0, 128, 128);
	root->add(open_highgui);
	start_gui();
	return nullptr;
}

int main(int argc, char *argv[]){
	std::ios_base::sync_with_stdio(false);
	log_inf(TAG, "Starting GUI");
	//pthread_create(&ui_thread, NULL, load_gui, NULL);
	//pthread_join(ui_thread, NULL);
	load_gui(nullptr);
	log_inf(TAG, "lol");
	return 0;
}
