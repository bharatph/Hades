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

const char *program_logo = " ██░ ██  ▄▄▄      ▓█████▄ ▓█████   ██████ \n▓██░ ██▒▒████▄    ▒██▀ ██▌▓█   ▀ ▒██    ▒ \n▒██▀▀██░▒██  ▀█▄  ░██   █▌▒███   ░ ▓██▄   \n░▓█ ░██ ░██▄▄▄▄██ ░▓█▄   ▌▒▓█  ▄   ▒   ██▒\n░▓█▒░██▓ ▓█   ▓██▒░▒████▓ ░▒████▒▒██████▒▒\n ▒ ░░▒░▒ ▒▒   ▓▒█░ ▒▒▓  ▒ ░░ ▒░ ░▒ ▒▓▒ ▒ ░\n ▒ ░▒░ ░  ▒   ▒▒ ░ ░ ▒  ▒  ░ ░  ░░ ░▒  ░ ░\n ░  ░░ ░  ░   ▒    ░ ░  ░    ░   ░  ░  ░  \n ░  ░  ░      ░  ░   ░       ░  ░      ░  \n                   ░                      \n";

//Below are for debugging purposes and to maintain builds only
enum build_type {
  ALPHA=0,
  BETA=1,
  STABLE=5
};

const char *build_type = hades_VERSION_MINOR >= STABLE? "stable" : hades_VERSION_MINOR == ALPHA ? "alpha" : "beta";
#endif
