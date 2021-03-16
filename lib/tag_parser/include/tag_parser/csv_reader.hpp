#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <iostream>

#include "utils.hpp"
using namespace std;

class FileCSV{
public:
    FileCSV(string _path): path(_path), amount_of_tag(0) {
        CSVParser();
    };
    ~FileCSV () {};
    void CSVParser();
    
    int amount_of_tag;
    vector<string> header;
    unordered_map<string, vector<vector<string>>> contents;
private:
    string path;
};

