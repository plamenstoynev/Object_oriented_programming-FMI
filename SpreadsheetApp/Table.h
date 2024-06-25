#pragma once
#include <vector>
#include <string>
class Table {
private:
    std::vector<std::vector<std::string>> data;

    bool isInteger(const std::string& s);
    bool isDouble(const std::string& s);
    void parseLine(const std::string& line, std::vector<std::string>& row);

public:
    void load(const std::string& filename);
    void save(const std::string& filename);
    void print();
    void edit(size_t row, size_t col, const std::string& newValue);
};