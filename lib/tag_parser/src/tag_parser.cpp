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
        vector<string> s_date(3), s_time(3);
        double exp_time = 0;
        int last_index = -1;
        bool new_round = true;
        for (int k = 0; k < data.size(); k++) {
            vector<string> date, time;
            split_by_pos(d[k][0], date, "-"); // get YMD 
            split_by_pos(d[k][1], time, ":"); // get Hms
            if (new_round) {
                for(int i = 0; i < 3; i++) s_date[i] = date[i], s_time[i] = time[i];
                exp_time = getRefTime(date, time) + this->exp_hour*60*60;
                new_round = false;
            } else {
                if (getRefTime(date, time) >= exp_time) {
                    new_round = true;
                } else {

                }
            }
        }
    }
}

double TagParser::getRefTime(vs& date, vs&time) {
    int Y = stoi(date[0]), M = stoi(date[1]), D = stoi(date[2]);
    int s = stoi(time[2]), m = stoi(time[1]), h = stoi(time[0]);
    struct tm new_time = {
        s, m, h,
        D, M, Y
    };
    struct tm& ref_time = this->ref_time;

    time_t x = mktime(&ref_time), y = mktime(&new_time);
    double difference = difftime(y, x);
    return difference + this->exp_hour*60*60;
}