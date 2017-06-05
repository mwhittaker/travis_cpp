CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_LIBRARY(reverse reverse.cc)

CREATE_NAMED_TEST(reverse_reverse_test reverse_test)
TARGET_LINK_LIBRARIES(reverse_reverse_test reverse glog)

CREATE_NAMED_BENCHMARK(reverse_reverse_bench reverse_bench)
TARGET_LINK_LIBRARIES(reverse_reverse_bench reverse glog)
