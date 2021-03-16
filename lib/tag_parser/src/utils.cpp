#include "utils.hpp"

void split_by_pos(const string &s, vector<string> &token, string delim /*= " "*/) {
    string::size_type last_pos = s.find_first_not_of(delim, 0); // find first non delim
    string::size_type pos = s.find_first_of(delim, last_pos);   // find delim

    while (last_pos != string::npos) {
        if (pos == string::npos) {
            token.push_back(s.substr(last_pos, s.size() - last_pos));
            break;
        }
        token.push_back(s.substr(last_pos, pos - last_pos));
        last_pos = s.find_first_not_of(delim, pos);
        pos = s.find_first_of(delim, last_pos);
    }
}