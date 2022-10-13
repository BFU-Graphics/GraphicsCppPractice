#ifndef EIGENPRACTICE_UTILS_H
#define EIGENPRACTICE_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

auto random_float() -> float
{
    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_real_distribution<float> dist(1.0, 10.0);
    return dist(mt);
}

auto log_success(int index, long long t) -> void
{
    std::cout << ">> Test " << index << ": Passed in " << t << " ms" << std::endl;
}

auto log_error(int index, long long t) -> void
{
    std::cout << ">> Test " << index << ": Failed in " << t << " ms" << std::endl;
}

template<typename F>
auto measure_elapsed_time(F &&f) -> long long
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; ++i)
        f();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

template<typename F>
auto check_time(F &&f, long long max) -> void
{
    static int test_index = 1;
    long long t = measure_elapsed_time(std::forward<F &&>(f));
    if (t > max)
        log_error(test_index, t);
    else
        log_success(test_index, t);
}

#endif //EIGENPRACTICE_UTILS_H
