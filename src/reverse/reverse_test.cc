#include "reverse/reverse.h"

#include <string>

#include "glog/logging.h"
#include "gtest/gtest.h"

TEST(Reverse, EmptyString) { EXPECT_EQ("", Reverse("")); }

TEST(Reverse, NonEmptyString) { EXPECT_EQ("cba", Reverse("abc")); }

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
