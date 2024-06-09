#include "Directory.h"

Directory::Directory(const char *name) : File(name) {
    files = new File *[50];
    fileCount = 0;
}

Directory::Directory(const Directory &other) : File(other) {
    copyFrom(other);
}

Directory &Directory::operator=(const Directory &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Directory::Directory(Directory &&other) noexcept : File(std::move(other)) {
    moveFrom(std::move(other));
}

Directory &Directory::operator=(Directory &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Directory::addFile(File *file) {
    files[fileCount++] = file;
}

File *Directory::getFile(const char *name) const {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i]->getName(), name) == 0) {
            return files[i];
        }
    }
    return nullptr;
}

void Directory::printContent() const {
    std::cout << "Directory: " << getName() << std::endl;
    for (int i = 0; i < fileCount; i++) {
        files[i]->printContent();
    }
}

void Directory::resize() {
    File **newFiles = new File *[fileCount * 2];
    for (int i = 0; i < fileCount; i++) {
        newFiles[i] = files[i];
    }
    delete[] files;
    files = newFiles;
}

void Directory::copyFrom(const Directory &other) {
    fileCount = other.fileCount;
    files = new File *[fileCount];
    for (int i = 0; i < fileCount; i++) {
        files[i] =  other.files[i];
    }
}

void Directory::moveFrom(Directory &&other) {
    fileCount = other.fileCount;
    files = other.files;
    other.files = nullptr;
}

void Directory::free() {
    for (int i = 0; i < fileCount; i++) {
        delete files[i];
    }
    delete[] files;
}