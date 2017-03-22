#ifndef CONS_H
#define CONS_H

int CAM = 1; //secind camera

enum cams {
	ONE,
	TWO
};

enum folks {
  USER,
  POLICE,
  ALL
};
//char *program_name = "Project-GGDB"; //program name itself is 'Project GGDB'

const char *program_name = "Project GGDB";

//Below are for debugging purposes and to maintain builds only
enum build_type {
  ALPHA=0,
  BETA=1,
  FINAL=2
};

//int version[] = {ALPHA, 0, 1} //format -> build_type, MAJOR_VISION, MINOR_VERSION, REVISION_NUMBER
#endif
