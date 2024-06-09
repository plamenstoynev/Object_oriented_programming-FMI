#include "FileSystem.h"

FileSystem::FileSystem(){
    root = new Directory("root");
}

FileSystem::FileSystem(const FileSystem& other){
    copyFrom(other);
}

FileSystem& FileSystem::operator=(const FileSystem& other){
    if(this != &other){
        free();
        copyFrom(other);
    }
    return *this;
}

FileSystem::FileSystem(FileSystem&& other) noexcept{
    moveFrom(std::move(other));
}

FileSystem& FileSystem::operator=(FileSystem&& other) noexcept{
    if(this != &other){
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void FileSystem::createFile(const char* name, const char* content){
    this->root->addFile(new TextFile(name, content));
}

void FileSystem::createDirectory(const char* location){
    this->root->addFile(new Directory(location));
}

File* FileSystem::getFile(const char* location) const{
    return root->getFile(location);
}

void FileSystem::printFile(const char* location) const{
    File* file = getFile(location);
    if(file != nullptr){
        file->printContent();
    }
}

FileSystem::~FileSystem(){
    free();
}

void FileSystem::copyFrom(const FileSystem& other){
    root = new Directory(*other.root);
}

void FileSystem::moveFrom(FileSystem&& other){
    root = other.root;
    other.root = nullptr;
}

void FileSystem::free() {
    delete root;
}