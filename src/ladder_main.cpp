#include "ladder.h"

int main () {
    set<string> wordList;
    load_words(wordList, "src/words.txt");
    for (string word : wordList)
        cout << word << " ";
    cout << endl;
}