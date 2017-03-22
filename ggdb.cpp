#include <iostream>
#include <vector>
#include <thread>
#include <signal.h>
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sqlite3.h>
#include "constants.h"
#include "log.h"
//#include "init.h"

using namespace std;
using namespace cv;

#define DEBUGGING

int inform(enum folks folk);

int load_gui()
{
	log("initializing GUI", YELLOW);
	cv::namedWindow("GGDB", WINDOW_AUTOSIZE);
	//create gui via opencv through highgui
	return 0;

}
//int label = 0;

vector<Mat> images;
vector<int> labels;


vector<Mat> suspects;
int predictLabel = 0;

int i_n = 0;
char *zErrMsg = 0;
int sqlite_callback(void *NotUsed, int argc, char**argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		log("callback for sqlite3, executed the command");
		//TODO print executed command
	}
	return 0;
}

//this function is used to process frames
int proc_frame(Mat image){

	//verification part
	images.push_back(image);
	labels.push_back(i_n++);
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	log("FaceRecognizer class initialized...", GREEN);
	model -> train(images, labels);
	log("trained", GREEN);
	cv::Mat grayMat;
	cv::cvtColor(image, grayMat, cv::COLOR_BGR2GRAY);
	int predicted = -1;
	if( (predicted = model -> predict(grayMat)) == 0){
		//new member
		if(false){ //FIXME enter only if the detected member is a new member
		model->train(images, labels);
		}
		else {
			suspects.push_back(grayMat);
			cout << "warn the user";
			//TODO alert through app
		}
	}	
	cout << predictLabel << ",";
}

cv::Mat capture_frame(){
	VideoCapture cap;
	cv::Mat frame;
	if(!cap.open(0)){
		log("cannot open CAM", FATAL);
	}
	cap >> frame;
	if(frame.empty()){
		exit(0);
	}
	imshow("GGDB", frame);
	//imwrite("../loli.jpg", frame);
	return frame;
}	

int start_dvr(){
	while(true){ //capture_frame != null
		proc_frame(capture_frame());
	}
}

sqlite3 *db;
void exitHandler(int sig){
	log("writing to Database...please wait", YELLOW);
	sqlite3_exec(db, "select * from table1", sqlite_callback, 0 ,&zErrMsg);
	sqlite3_free(zErrMsg);
	sqlite3_close(db);
	//write suspect and persons to db and exit
	exit(0);
}


int init_db(){
	int rc = sqlite3_open("db/db.sqlite3",&db);
	if(rc){
		log("can't open database, try giving previleges to the file");
		return -1;
	}else{
		log("database is opened");
		return 0;
	}
}

int main(int argc, char *argv[]){
	signal(SIGINT, exitHandler);
	TAG("GGDB");//for logging library
	//load_gui via opencv
	if(init_db()<-1) //TODO clean up return types **db_error
		return -1;
	load_gui();

	//capture from camera
	//process the frames
	start_dvr();

	//if the stored person is in DB do not alert the home
	//else if check he is breaking in to the house the inform(folks) 
	enum folks folk = USER;
	while(inform(folk) == -1)
	{
		
	}
	//async--> if there is a fire in the house
}


// inform the folks in the home that there is a stranger
int inform(enum folks folk){
	if(folk == USER){
		//alert the user
		return 0;
	}
	else if(folk == POLICE){
		//aert the police and user
		return 0;
	}
	else if(folk == ALL){
		//alert user and police
	}
	else return -1; //TODO rather returning failure, try to inform the user using messgage like hike!
}

