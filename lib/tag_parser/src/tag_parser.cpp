#include "tag_parser.hpp"
#include <iomanip>
#include <algorithm>

void TagParser::printTotalTag() {
    unordered_map<string, vector<vector<string>>>& contents = fileCSV.contents;

    for (auto it: contents) {
        cout.width(15); cout << std::left << it.first;
        cout << it.second.size() << endl;
    }
}

void TagParser::printTimeRange() {
    unordered_map<string, vector<vector<string>>>& contents = fileCSV.contents;

    for (auto it: contents) {
        string tag = it.first;
        vector<vector<string>>& data = it.second;
        sort(data.begin(), data.end(), [](auto a, auto b) ->bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        // Greedy
        int start_date = -1, start_time = -1;
        for (auto& d: data) {
            vector<string> date, time;
            split_by_pos(d[0], date, "-");
            split_by_pos(d[1], time, ":");
        }
    }
}