#include "TextFile.h"

TextFile::TextFile(const char *name, const char *content) : File(name) {
    strcpy(this->content, content);
}

void TextFile::printContent() const {
    std::cout << content << std::endl;
}

