#include "reverse/reverse.h"

#include <string>

#include "benchmark/benchmark.h"
#include "glog/logging.h"

void ReverseBench(benchmark::State& state) {
  const std::string s = "abcdefghijklmnopqrstuvwxyz";
  while (state.KeepRunning()) {
    const std::string reversed = Reverse(std::string(s));
    benchmark::DoNotOptimize(reversed);
  }
}
BENCHMARK(ReverseBench);

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}
