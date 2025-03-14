#include "ladder.h"

void error(string word1, string word2, string msg) {
    cout << word1 + " -> " + word2 + " - " + msg << endl; 
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (abs(len1 - len2) > 1)
        return false;

    int diffChar = 0;
    int index1 = 0, index2 = 0;
    while (index1 < len1 && index2 < len2){
        if (str1[index1] != str2[index2])
            ++diffChar;
        if (diffChar > 1)
            return false;
        ++index1;
        ++index2;
    }

    if (index1 < len1 || index2 < len2)
        ++diffChar;
    return diffChar == 1;
}
