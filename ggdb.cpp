#include <iostream>
#include <vector>
#include <thread>
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "constants.h"
//#include "init.h"

using namespace std;
using namespace cv;


int inform(enum folks folk);

//TODO gtk+ 2.00
int load_gui()
{
	cv::namedWindow("GGDB", WINDOW_AUTOSIZE);
	//create gui via opencv through highgui
	return 0;

}
//int label = 0;

vector<Mat> images;
vector<Mat> label;

int addNewPersons(Mat person)
{
	while(1){
	//sqlite l = createDB();
	//l.query("insert values into ");
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	model->train(images, label);
	
	}
}


vector<Mat> suspects;
int predictLabel = 0;
	//identify the persons
	//store them for later purposes
int recognizePersons(Mat person){
	while(1){
	//verification part
	images.push_back(person);
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	if( (predictLabel = model -> predict(images)) == 0){
		//new member
		if(false){ //FIXME enter only if the detected member is a new member
			
		}
		else {
			suspects.push_back(person);
			cout << "warn the user";
			//TODO alert through app
		}
	}	
	cout << predictLabel << ",";
	}
}

//this function is used to process frames
int proc_frame(Mat image){
	std::thread recog(recognizePersons, image);
	std::thread addPersons(addNewPersons, image);
	recog.join();
	addPersons.join();
}

cv::Mat capture_frame(){
	VideoCapture cap;
	cv::Mat frame;
	if(!cap.open(0)){
		cout << "cannot open CAM" << endl;
		exit(0);
	}
	cap >> frame;
	if(frame.empty()){
		exit(0);
	}
	imshow("GGDB", frame);
	return frame;
}	

int start_dvr(){
	while(true){ //capture_frame != null
		proc_frame(capture_frame());
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

