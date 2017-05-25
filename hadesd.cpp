#define HADES_D
#include <iostream>
#include <vector>
#include <thread>
#ifdef _WIN32
#include <process.h>
#include <dir.h>
#else 
#include <fcntl.h>
#include <sys/stat.h>
#endif
#include <signal.h>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui.hpp>
#include <sqlite3.h>
#define ENABLE_LOG
#include "logc.h"
#include "init.h"

using namespace std;
using namespace cv;
using namespace cv::face;

const char *TAG = "HADES DAEMON";

int inform(enum folks folk);

//int label = 0;

vector<Mat> images;
vector<int> labels;
Ptr<FaceRecognizer> model;

vector<Mat> suspects;

int i_n = 0;
char *zErrMsg = 0;
int sqlite_callback(void *NotUsed, int argc, char**argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		log_inf(TAG, "callback for sqlite3, executed the command");
		//TODO print executed command
	}
	return 0;
}

int load_gui()
{
	log_inf(TAG, "initializing GUI");
	cv::namedWindow("Hades",WINDOW_AUTOSIZE);
	//create gui via opencv through highgui
	return 0;

}
void *start_dvr(void *L){
	log_inf(TAG, "DVR started");
	VideoCapture cap;
	if(!cap.open(0)){
		log_err(TAG, "cannot open CAM");
		return NULL;
	}
	cv::Mat image;
	model = createEigenFaceRecognizer();
	cv::Mat grayMat;
	//
	cap >> image;
	images.push_back(image);
	labels.push_back(i_n++);
	model -> train(images, labels);
	log_err(TAG, "First frame is given as sample for training");
	while(true){ 
		cap >> image;
		cv::imshow("Hades", image);
		try {
			cv::waitKey(100);
		} catch(...){
			log_err(TAG, "error in the code");
		}
		//this function is used to process frames
		//verification part
		cv::cvtColor(image, grayMat, cv::COLOR_BGR2GRAY);
		int predicted = -1;
		if( (predicted = model -> predict(grayMat)) == 0){
			//new member
			if(false){ //FIXME enter only if the detected member is a new member
				images.push_back(image);
				labels.push_back(i_n++);
				model->train(images, labels);
			}
			else {
				suspects.push_back(grayMat);
				log_inf(TAG, "warn the user");
				//TODO alert through app
			}
		}	
		//log_inf(TAG, "predicted = %d", predicted);
	}
	return NULL;
}

sqlite3 *db;

void exit_operations(){
	printf("\n");
	log_inf(TAG, "writing to Database...please wait");
	//sqlite3_exec(db, "select * from table1", sqlite_callback, 0 ,&zErrMsg);
	sqlite3_free(zErrMsg);
	sqlite3_close(db);
	//write suspect and persons to db and exit
	exit(0);
}

void exitHandler(int sig){
	exit_operations();
}


int open_hades_db(const char *pathToDB){
	if(sqlite3_initialize() != SQLITE_OK){
		log_fat(TAG, "cannot initialize sqlite3 library");
		return -1;
	}
	int ret = 0;
        // open connection to a DB
        if ((ret = sqlite3_open(pathToDB, &db)) != SQLITE_OK){ //FIXME directory work
		log_fat(TAG, "cannot create db, error code : %d", ret);
		return -1;
	}
	log_inf(TAG, "database is opened");
	return 0;
}
//returns 0 on success
//loads images, labels, suspects, suspectsl
int load_trained_data(){
	//retreive path form sql and push to stacks 
	return 0;
}

void *find_user(void * L){
	log_inf(TAG, "Finding user in the internet");
	return NULL;
}

int main(int argc, char *argv[]){
	init_hades();
	signal(SIGINT, exitHandler);
	//load_gui via opencv
	if(open_hades_db("db.sqlite3")< 0) //TODO clean up return types **db_error
		return -1;
	log_inf(TAG, "Database loaded successfully");
	load_gui();
	log_inf(TAG, "GUI successfully loaded");
	if(load_trained_data() != 0){ //no trained data
		//TODO train data
	}
	//capture from camera
	//process the frames
	pthread_t dvr_thread;
	pthread_create(&dvr_thread, NULL, start_dvr, NULL);
	
	pthread_t find_user_thread;
	pthread_create(&find_user_thread, NULL, find_user, NULL);

	log_inf(TAG, "Main thread continues");
	//if the stored person is in DB do not alert the home
	//else if check he is breaking in to the house the inform(folks) 
	enum folks folk = USER;
	while(inform(folk) == -1){}

	//async--> if there is a fire in the house. 
	//NOTE alloted for Dinesh Kumar , DHT22 :{}
	pthread_join(dvr_thread, NULL);
	pthread_join(find_user_thread, NULL);
}


// inform the folks in the home that there is a stranger
int inform(enum folks folk){
	if(folk == USER){
		//alert the user
		return 0;
	}
	else if(folk == POLICE){
		//alert the police and user
		return 0;
	}
	else if(folk == ALL){
		//alert user and police
		return 0;
	}
	else return -1; //TODO rather returning failure, try to inform the user using messgage like hike!
}
