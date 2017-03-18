#ifndef CONS_H
#define CONS_H

static enum folks {
  USER,
  POLICE,
  ALL
}

static const char * authors_name = {
  "Bharatvaj",
  "Dinesh Kumar",
  "Goutham",
  "Gowri Shankar"
}
static const char *program_name = "Project-GGDB"; //program name itself is 'Project GGDB'


//Below are for debugging purposes and to maintain builds only
static enum build_type {
  ALPHA,
  BETA,
  FINAL
}

static const int version[] = {ALPHA, 0, 1} //format -> build_type, MAJOR_VISION, MINOR_VERSION, REVISION_NUMBER
#endif
