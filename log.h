#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstring>
#include "res.h"
#include <unistd.h>

int *writefd = new int(2);

 enum LOG_TYPE {
	 FATAL,
   ERROR,
   INFO
 };

 char tag[64] = "";
 void TAG(const char *tag_name)
 {
   strcpy(tag, tag_name);
 }



 enum COLOR {
   RED,
   GREEN,
   YELLOW,
   BLUE,
   MAGENTA,
   CYAN
 };


 void print(const char *msg){
   printf( "%s\n", msg);
 }

 void print(const char *msg, enum COLOR color){
    if(color == RED)
     printf("%s", COLOR_RED);
    else if (color == GREEN)
     printf("%s", COLOR_GREEN);
    else if (color == YELLOW)
     printf("%s", COLOR_YELLOW);
    else if (color == BLUE)
     printf("%s", COLOR_BLUE);
    else if (color == MAGENTA)
     printf("%s", COLOR_MAGENTA);
    else if (color == CYAN)
     printf("%s", COLOR_CYAN);
    else{}
     printf("%s%s\n",  msg, COLOR_RESET);
     //fprintf(stdout, "%s: %s%s", tag, msg, COLOR_RESET); //FIXME fix for log support
 }

 void log(const char *msg)
 {
   #ifdef DEBUGGING
   printf("%s: %s\n", tag, msg);
   #endif
 }


 void log(const char *msg, enum LOG_TYPE log_type){
   #ifdef DEBUGGING
   if(log_type == FATAL){
     write (*writefd, strcat(strcat(tag, "FATAL: "),msg), BUFFER);
     std::exit(-1);
   }
   else if(log_type == ERROR)
     fprintf(stderr, "%s: %s\n", tag, msg);
   else if (log_type == INFO)
     log(msg);
   #endif
 }


void log(const char *msg, enum COLOR color){
   #ifdef DEBUGGING
   print(msg, color);
   #endif
}



#endif
