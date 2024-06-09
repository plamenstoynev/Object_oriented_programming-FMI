#pragma once
#include "File.h"
class TextFile : public File
{
    char content[1024];
public:
    TextFile(const char* name, const char* content);
    void printContent() const override;
};