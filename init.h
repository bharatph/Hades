#ifndef INIT_H
#define INIT_H

#include <stdio.h>
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
  
void print_authors(){
	//std::ios_base::sync_with_stdio(false);
  printf("Program developed by ");
  for(int i = 0; i < 4; i++){ //FIXME use dynamic sizing
	  printf("%s, ", authors[i]);
   }
  printf("\n");
}
void init_hades(){
	std::ios_base::sync_with_stdio(false);
	printf("%s",program_logo);
	printf("%s v%d.%d.%d\n", program_name, version[0], version[1], version[2]);
	print_authors();
}

#endif
