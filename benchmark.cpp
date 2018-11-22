#include "determinant.h"
#include <benchmark/benchmark.h>

const int n = 1000;

static void BM_1_thread(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(1, n, A, L, U);
    }
}

static void BM_2_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(2, n, A, L, U);
    }
}

static void BM_4_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(4, n, A, L, U);
    }
}

static void BM_4_threads_no_pause(benchmark::State& state) {
    for (auto _ : state){
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        LU_eval_threading(4, n, A, L, U);
    }
}

static void BM_8_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(8, n, A, L, U);
    }
}

static void BM_16_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(16, n, A, L, U);
    }
}

static void BM_64_thread(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(64, n, A, L, U);
    }
}

static void BM_5_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(5, n, A, L, U);
    }
}

static void BM_27_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(27, n, A, L, U);
    }
}

static void BM_71_threads(benchmark::State& state) {
    for (auto _ : state){
        state.PauseTiming();
        vector<vector<double>> A(n), L(n), U(n), L_U(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i].push_back(rand() % 20 - 10);
                L[i].push_back(0);
                U[i].push_back(0);
                L_U[i].push_back(0);
            }
        }
        state.ResumeTiming();
        LU_eval_threading(71, n, A, L, U);
    }
}

BENCHMARK(BM_1_thread);
BENCHMARK(BM_2_threads);
BENCHMARK(BM_4_threads);
BENCHMARK(BM_4_threads_no_pause);
BENCHMARK(BM_8_threads);
BENCHMARK(BM_16_threads);
BENCHMARK(BM_64_thread);
BENCHMARK(BM_5_threads);
BENCHMARK(BM_27_threads);
BENCHMARK(BM_71_threads);

BENCHMARK_MAIN();