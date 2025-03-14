#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Ladder, EditDistanceWithin) {
  EXPECT_TRUE(edit_distance_within("plane", "pane", 1));
  EXPECT_TRUE(edit_distance_within("chat", "cheat", 1));
  EXPECT_FALSE(edit_distance_within("test", "tents", 1));
}
