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
        if (str1[index1] != str2[index2]){
            ++diffChar;
            if (diffChar > 1)
                return false;
            if (len1 < len2)
                ++index2;
            else if (len2 < len1)
                ++index1;
            else{
                ++index1;
                ++index2;
            }
        }
        else {
            ++index1;
            ++index2;
        }
    }

    if (index1 < len1 || index2 < len2)
        ++diffChar;
    return diffChar == 1;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder[ladder_queue.size() - 1];
        for (string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return vector<string>();
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    for (string word; (in >> word);)
        word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder) {
    for (string word : ladder) {
        cout << word << " ";
    }
    cout << endl;
}

// void verify_word_ladder() {
//     set<string> word_list;
//     load_words(word_list, "words.txt");
//     my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
//     my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
//     my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
//     my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
//     my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
//     my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
// }