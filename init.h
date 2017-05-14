#ifndef INIT_H
#define INIT_H
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#elif _POSIX_
#include <unistd.h>
#endif
#include "config.h"
#include "constants.h"

void clear(){
  #ifdef _WIN32
  system("cls");
  #elif _POSIX_
  system("clear");
  #endif
}

void print_authors(){
  printf("developed by ");
  for(int i = 0; i < (signed int)(sizeof(authors)/sizeof(char *)); i++){
	  printf("%s, ", authors[i]);
   }
  printf("\n");
}
void init_hades(){
	std::ios_base::sync_with_stdio(false);
	printf("%s",program_logo);
	printf("%s v%d.%d-%s\n", PROGRAM_NAME, hades_VERSION_MAJOR, hades_VERSION_MINOR, build_type);
	print_authors();
}
#endif
