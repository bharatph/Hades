#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include "constants.h"
#include <pthread.h>

using namespace std;
using namespace cv;

enum folks {
	USER,
	POLICE,
	ALL
};

int inform(enum folks folk);

//TODO gtk+ 2.00
int load_gui(){
	//create gui via opencv through highgui
}

int label = 0;



int addNewPersons(Mat person){
	sqlite l = createDB();
	l.query("insert values into ");
	Ptr<FaceRecognizer> model = new createEigenFaceRecognizer();
	model->train(image, label);
	
}

	//identify the persons
	//store them for later purposes
int recognizePersons(Mat person){
	//verification part
	int predictLabel = -1;
	double confidence = 0.0;
	predictLabel = model -> predict(image);
	return predictLabel;
}

//this function is used to process frames
int proc_frames(Mat image){
	std::thread recog(recognizePersons, image);
	std::thread addPersons(addNewPersons, image);
	recog.join();
	addPersons.join();
}

int capture_frame(){
	VideoCapture cap(CAM);
	
	Mat image;
	cap.read(image);
	proc_frames(image);
}	

int start_dvr(){
	while(capture_frame() < 0){
		proc_frames();
	}
}

int main(int argc, char *argv[]){
	//load_gui via opencv
	load_gui();

	//capture from camera
	//process the frames
	start_dvr();

	//if the stored person is in DB do not alert the home
	//else if check he is breaking in to the house the inform(folks) 
	enum folks folk = USER;
	while(inform(folk) == -1){
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

