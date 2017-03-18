#ifndef INIT_H
#define INIT_H

void init(){
  std::cout << program_name << " " << version[0] << "-" << version[1] << "." << version[2] << std::endl;
  std::cout << "Program developed by";
  for(int i = 0; i < 4; i++){ //FIXME use dynamic sizing
    std::cout << authors_name[i] << std::endl;
    }
}

#endif
