#include "FileSystem.h"

int main () {
    FileSystem fs;

    fs.createFile("file1", "content1");
    fs.createFile("file2", "content2");

    fs.createDirectory("dir1");
    fs.createFile("dir1/file3", "content3");

    fs.printFile("file1");
    fs.printFile("dir1/file3");

    return 0;
}