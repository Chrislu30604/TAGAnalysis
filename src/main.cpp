#include <iostream>
#include <string>
#include <tag_parser/tag_parser.hpp>

#define CSV_PATH "../data/data.csv"

using namespace std;

int main() {
    TagParser *tag_parser = new TagParser(CSV_PATH);
    cout << "[Total Amount of Data Tag]" << endl;
    cout << tag_parser->getAmountOfTag() << endl;
    cout << "----------------------------------" << endl;
    cout << "[Total Tag of each CELL_XX]" << endl;
    tag_parser->printTotalTag();
    cout << "----------------------------------" << endl;
    cout << "[Time Range of each Tag]" << endl;
    tag_parser->printTimeRange();
}