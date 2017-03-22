/*
 uni_img.h

 Unicode Image
 All the unicode images are defined in here
 */

#ifndef PP_RES_H
#define PP_RES_H

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#ifdef PP_MAIN
const static char * pp_logo = "\x1b[32mPROJECT PERISCOPE\x1b[0m";
#endif

#endif
