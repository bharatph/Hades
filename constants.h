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

const char *authors[] = {"Dinesh Kumar", "Goutham", "Gowri Shankar", "Bharatvaj", "Jothi Kumar"};

const char *program_name = "Hades"; //revolutionary IoT

const char *program_logo = " ██░ ██  ▄▄▄      ▓█████▄ ▓█████   ██████ \n▓██░ ██▒▒████▄    ▒██▀ ██▌▓█   ▀ ▒██    ▒ \n▒██▀▀██░▒██  ▀█▄  ░██   █▌▒███   ░ ▓██▄   \n░▓█ ░██ ░██▄▄▄▄██ ░▓█▄   ▌▒▓█  ▄   ▒   ██▒\n░▓█▒░██▓ ▓█   ▓██▒░▒████▓ ░▒████▒▒██████▒▒\n ▒ ░░▒░▒ ▒▒   ▓▒█░ ▒▒▓  ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░\n ▒ ░▒░ ░  ▒   ▒▒ ░ ░ ▒  ▒  ░ ░  ░░ ░▒  ░ ░\n ░  ░░ ░  ░   ▒    ░ ░  ░    ░   ░  ░  ░  \n ░  ░  ░      ░  ░   ░       ░  ░      ░  \n                   ░                      \n";

//Below are for debugging purposes and to maintain builds only
enum build_type {
  ALPHA=0,
  BETA=1,
  FINAL=2
};

int version[] = {0, 0, 4}; //format -> build_type, MAJOR_VISION, MINOR_VERSION, REVISION_NUMBER
#endif
