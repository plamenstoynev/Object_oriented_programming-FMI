#include "Table.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

bool Table::isInteger(const std::string& s) {
    if (s.empty()) return false;
    char* end;
    std::strtol(s.c_str(), &end, 10);
    return end == s.c_str() + s.size();
}

bool Table::isDouble(const std::string& s) {
    if (s.empty()) return false;
    char* end;
    std::strtod(s.c_str(), &end);
    return end == s.c_str() + s.size();
}

void Table::parseLine(const std::string& line, std::vector<std::string>& row) {
    std::stringstream ss(line);
    std::string cell;
    while (std::getline(ss, cell, ',')) {
        row.push_back(cell);
    }
}

void Table::load(const std::string& filename) {
    data.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        parseLine(line, row);
        data.push_back(row);
    }
    file.close();
}

void Table::save(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) file << ",";
            file << row[i];
        }
        file << std::endl;
    }
    file.close();
}

void Table::print() {
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (i > 0) std::cout << " | ";
            std::cout << row[i];
        }
        std::cout << std::endl;
    }
}

void Table::edit(size_t row, size_t col, const std::string& newValue) {
    if (row >= data.size() || col >= data[row].size()) {
        std::cerr << "Error: Invalid row or column index" << std::endl;
        return;
    }

    data[row][col] = newValue;
}