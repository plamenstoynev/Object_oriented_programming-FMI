#pragma once
#include "File.h"
class Directory : public File {
    File** files;
    int fileCount;
public:
    Directory(const char *name);

    Directory(const Directory& other);
    Directory& operator=(const Directory& other);
    Directory(Directory&& other) noexcept;
    Directory& operator=(Directory&& other) noexcept;

    void addFile(File *file);

    File *getFile(const char *name) const;

    void printContent() const override;
private:
    void resize();
    void copyFrom(const Directory& other);
    void moveFrom(Directory&& other);
    void free();
};