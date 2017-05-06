#ifndef INIT_H
#define INIT_H

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#elif _POSIX_
#include <unistd.h>
#endif
#include "constants.h"

void clear(){
  #ifdef _WIN32
  system("cls");
  #elif _POSIX_
  system("clear");
  #endif
}
  

void init(){
  std::cout << program_name << " " << version[0] << "-" << version[1] << "." << version[2] << std::endl;
  std::cout << "Program developed by";
 for(int i = 0; i < 4; i++){ //FIXME use dynamic sizing
   printf("%s, ", authors[i]);
   }
	std::cout << "Goutham" << "Gowri Shankar" << "Dinesh Kumar" << "Bharatvaj";
}

#endif
