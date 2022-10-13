#include "utils.h"
#include "Eigen/Eigen"

std::vector<float> data;

long long row = 10e3;
long long col = 10e3;

auto init() -> void
{
    data.resize(row * col);
    std::generate(data.begin(), data.end(), random_float);
}

auto task01() -> void
{
    Eigen::Map<Eigen::MatrixXf> map(data.data(), row, col);
}

auto task02() -> void
{
    Eigen::MatrixXf res = Eigen::Map<Eigen::MatrixXf>(data.data(), row, col);
}

auto task03() -> void
{
    float *ptr = &data[0];
    Eigen::Map<Eigen::MatrixXf> map(ptr, row, col);
}

auto main() -> int
{
    init();

    check_time(task01, 2LL);
    check_time(task02, 2LL);
    check_time(task03, 2LL);

    return 0;
}