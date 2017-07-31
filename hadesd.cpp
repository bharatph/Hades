#define HADES_D "HADES DAEMON"
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

#include "clog.h"
#include "init.h"
#include "network_utils.h"

using namespace std;
using namespace cv;
using namespace cv::face;

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
		log_inf(HADES_D, "callback for sqlite3, executed the command");
		//TODO print executed command
	}
	return 0;
}

void *start_dvr(void *L){
	log_inf(HADES_D, "DVR started");
	VideoCapture cap;
	if(!cap.open(0)){
		log_err(HADES_D, "cannot open CAM");
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
	log_err(HADES_D, "First frame is given as sample for training");
	while(true){ 
		cap >> image;
		/*
		cv::imshow("Hades", image);
		try {
			cv::waitKey(100);
		} catch(...){
			log_err(HADES_D, "error in the code");
		}
		*/
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
				log_inf(HADES_D, "warn the user");
				//TODO alert through app
			}
		}	
		//log_inf(HADES_D, "predicted = %d", predicted);
	}
	return NULL;
}

sqlite3 *db;

void exit_operations(){
	printf("\n");
	log_inf(HADES_D, "writing to Database...please wait");
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
		log_fat(HADES_D, "cannot initialize sqlite3 library");
		return -1;
	}
	int ret = 0;
        // open connection to a DB
        if ((ret = sqlite3_open(pathToDB, &db)) != SQLITE_OK){ //FIXME directory work
		log_fat(HADES_D, "cannot create db, error code : %d", ret);
		return -1;
	}
	log_inf(HADES_D, "database is opened");
	return 0;
}
//returns 0 on success
//loads images, labels, suspects, suspectsl
int load_trained_data(){
	//retreive path form sql and push to stacks 
	return 0;
}

void modules_thread(void *opt){
	//while searching for available devices if device found, let them get seen by the user
	//if user desires, configure each devices
	//and save their id for future use until reset
	//if the id fails the devices is connecting for the first time or the device has been resetted
	//return -1;
}
	int clients[100] = {0}; //reserved first 'int' for localhost TODO needs dynamic sizing

void *start_reading(void *opt){
	static int thread_count;
	int client_id = thread_count++;
	int sockfd = *((int *)opt);
	char *buffer = (char *)malloc(BUFFER_SIZE);
	log_inf(HADES_D, "waiting @ socket %d", sockfd);
	while(1){
		if(read_data(sockfd, buffer, 1) == 0){
			log_inf(HADES_D, "Client[%d]: %s ", client_id, buffer);
		}
	}
}

int main(int argc, char *argv[]){
	init_hades();
	signal(SIGINT, exitHandler);
	if(open_hades_db("db.sqlite3")< 0) //TODO clean up return types **db_error
		return -1;
	log_inf(HADES_D, "Database loaded successfully");
	if(load_trained_data() != 0){ //no trained data
		//TODO train data
	}
	//capture from camera
	//process the frames
	pthread_t dvr_thread;
	pthread_t net_thread;
	pthread_create(&dvr_thread, NULL, start_dvr, NULL);
	
	log_inf(HADES_D, "Main thread continues");
	//if the stored person is in DB do not alert the home
	//else if check he is breaking in to the house the inform(folks) 
	enum folks folk = USER;
	while(inform(folk) == -1){}

	//async--> if there is a fire in the house. 
	//NOTE alloted for Dinesh Kumar , DHT22 :{}
	int i = 0;
	while(i++ != 100){
		if((clients[i] = start_server(argc < 2 ?DEFAULT_PORT:atoi(argv[1]))) < 0){//FIXME add a more withstanding checking
			printf("Server initialization failed\n");
		}
		pthread_create(&net_thread, NULL, start_reading, &clients[i]);
	}
	pthread_join(dvr_thread, NULL);
}

//TODO use with terminology of levels
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
