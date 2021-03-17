#pragma once
#include "csv_reader.hpp"

#include <ctime>

using vi = vector<int>;
using vs = vector<string>;
// Find the keypoints from CSV
class TagParser {
public:
    TagParser(string _path, int _hour) : path(_path), fileCSV(_path), exp_hour(_hour) {};
    ~TagParser() {};
    int getAmountOfTag() {return fileCSV.amount_of_tag;}
    void printTotalTag();
    void printTimeRange();

private:
    double getRefTime(vs&, vs&);
    int exp_hour = 0;
    string path;
    struct tm ref_time = {0, 0, 0, 1, 1, 0};
    FileCSV fileCSV;
};