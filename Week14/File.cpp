#include "File.h"

File::File(const char *name){
    strcpy(this->name, name);
}

const char *File::getName() const {
    return name;
}
