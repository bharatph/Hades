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
	//create gui via opencv through highgui

}
//int label = 0;

vector<Mat> images;
vector<Mat> label;

int addNewPersons(Mat person)
{
	//sqlite l = createDB();
	//l.query("insert values into ");
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	model->train(images, label);
}

	//identify the persons
	//store them for later purposes
int recognizePersons(Mat person){
	//verification part
	int predictLabel = -1;
	double confidence = 0.0;
	Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
	predictLabel = model -> predict(images);
	return predictLabel;
}

//this function is used to process frames
int proc_frame(Mat image){
	std::thread recog(recognizePersons, image);
	std::thread addPersons(addNewPersons, image);
	recog.join();
	addPersons.join();
}

cv::Mat capture_frame(){
	VideoCapture cap(0); //open camera
;
	Mat image;
	cap.read(image);
	return image;
}	

int start_dvr(){
	while(true){ //capture_frame != null
		proc_frame(capture_frame());
	}
}

int main(int argc, char *argv[]){

	//load_gui via opencv
//	load_gui();

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

