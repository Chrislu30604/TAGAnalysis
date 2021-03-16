#include "csv_reader.hpp"

void FileCSV::CSVParser() {
    ifstream file;
    string token;
    vector<string> line;
    file.exceptions(ifstream::badbit);
    try {
        file.open(this->path);
        // get the first header
        getline(file, token);
        split_by_pos(token, this->header);

        while (getline(file, token)) {
            istringstream ss(token);
            string value;
            while (ss >> value) line.push_back(value);            
            contents[line.back()].push_back(line);
            amount_of_tag++;
            line.clear();
        }
        file.close();
    } catch (ifstream::failure e) {
        cerr << "Exception opening/reading file : " << e.what() << endl;
    }
}