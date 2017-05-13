#ifndef CONS_H
#define CONS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 256
#endif

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
  STABLE=5
};

int version[] = {0, 0, 4}; //format -> MAJOR_VISION, MINOR_VERSION, REVISION_NUMBER
const char *build_type = version[1] >= STABLE? "stable" : version[1] == ALPHA ? "alpha" : "beta";
#endif
