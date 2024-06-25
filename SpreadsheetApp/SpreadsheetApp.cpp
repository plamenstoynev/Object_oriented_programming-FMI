#include "SpreadsheetApp.h"
#include <iostream>
#include <sstream>

void SpreadsheetApp::run() {
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (command == "exit") break;
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;
        if (cmd == "load") {
            std::string filename;
            iss >> filename;
            table.load(filename);
        } else if (cmd == "save") {
            std::string filename;
            iss >> filename;
            table.save(filename);
        } else if (cmd == "print") {
            table.print();
        } else if (cmd == "edit") {
            size_t row, col;
            std::string newValue;
            iss >> row >> col;
            std::getline(iss, newValue);
            newValue = newValue.substr(1); // Remove leading space
            table.edit(row - 1, col - 1, newValue); // Convert to 0-based index
        } else {
            std::cerr << "Unknown command: " << cmd << std::endl;
        }
    }
}