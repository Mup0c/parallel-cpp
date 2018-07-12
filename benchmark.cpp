#include "determinant.h"
#include <benchmark/benchmark.h>

static void BM_one_thread(benchmark::State& state) {
    for (auto _ : state)
        LU_eval_threading(1);
}
// Register the function as a benchmark
BENCHMARK(BM_one_thread);

// Define another benchmark
static void BM_two_threads(benchmark::State& state) {
    for (auto _ : state)
        LU_eval_threading(8);
}
// Register the function as a benchmark
BENCHMARK(BM_two_threads);

static void BM_eight_threads(benchmark::State& state) {
    for (auto _ : state)
        LU_eval_threading(100);
}
// Register the function as a benchmark
BENCHMARK(BM_eight_threads);

static void BM_16_threads(benchmark::State& state) {
    for (auto _ : state)
        LU_eval_threading(64);
}
// Register the function as a benchmark
BENCHMARK(BM_16_threads);

BENCHMARK_MAIN();