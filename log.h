#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <cstring>
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"


int *writefd = new int(2);

 enum LOG_TYPE {
	 FATAL,
   ERROR,
   INFO
 };

 static char tag[64] = "";
 void TAG(const char *tag_name)
 {
   strcpy(tag, tag_name);
 }


 void print(const char *msg){
   printf( "%s\n", msg);
 }

 void print(const char *msg, const char * col){
     printf("%s", col);
     printf("%s%s\n",  msg, COLOR_RESET);
     //fprintf(stdout, "%s: %s%s", tag, msg, COLOR_RESET); //FIXME fix for log support
 }

 void log(const char *msg)
 {
   #ifdef DEBUGGING
   std::cout << tag << ": " << msg << std::endl;
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


void log(const char *msg, const char * col){
   #ifdef DEBUGGING
   print(msg, col);
   #endif
}



#endif
