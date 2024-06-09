#pragma once
#include "File.h"
#include "Directory.h"
#include "TextFile.h"

class FileSystem{
private:
    Directory* root;
public:
    FileSystem();

    FileSystem(const FileSystem& other);
    FileSystem& operator=(const FileSystem& other);
    FileSystem(FileSystem&& other) noexcept;
    FileSystem& operator=(FileSystem&& other) noexcept;

    void createFile(const char* name, const char* content);
    void createDirectory(const char* location);
    File* getFile(const char* location) const;
    void printFile(const char* location) const;

    ~FileSystem();

private:
    void copyFrom(const FileSystem& other);
    void moveFrom(FileSystem&& other);
    void free();
};