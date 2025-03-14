#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Ladder, EditDistanceWithin) {
  EXPECT_TRUE(edit_distance_within("plane", "pane", 1));
  EXPECT_TRUE(edit_distance_within("chat", "cheat", 1));
  EXPECT_FALSE(edit_distance_within("test", "tents", 1));
}

TEST(Ladder, LoadWords){
  set<string> wordList;
  load_words(wordList, "src/words.txt");
  EXPECT_FALSE(wordList.empty());
}

TEST(Ladder, VerifyLadder) {
  verify_word_ladder();
}