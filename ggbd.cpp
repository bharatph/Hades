#include <opencv2/core/core.hpp>
//#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

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

}

//this function is used to process frames
int proc_frames(Mat image){
	int label = 0;
	Ptr<FaceRecognizer> model = new createEigenFaceRecognizer();
	model->train(image, label);
	int predictLabel = -1;
	double confidence = 0.0;
	predictLabel = model -> predict(image);
	if(predictLabel != -1){
		return predictLabel;
	}
}

int main(int argc, char *argv[]){
	//load_gui
	load_gui();

	//capture from camera
	//process the frames
	Mat image;
	proc_frames(image);
	
	//identify the persons
	//store them for later purposes
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

