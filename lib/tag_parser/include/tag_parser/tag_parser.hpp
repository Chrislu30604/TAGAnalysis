#pragma once
#include "csv_reader.hpp"

// Find the keypoints from CSV
class TagParser {
public:
    TagParser(string _path) : path(_path), fileCSV(_path) {};
    ~TagParser() {};
    int getAmountOfTag() {return fileCSV.amount_of_tag;}
    void printTotalTag();
    void printTimeRange();

private:
    string path;
    FileCSV fileCSV;
};