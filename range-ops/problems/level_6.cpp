#include <algorithm>
#include <cassert>
#include <numeric>
#include <ranges>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main()
{
    std::vector<int> v = {8, 3, 1, 6, 9, 2, 7, 4};

    // 40. Get the first 3 even values.
    auto res40 = /* TODO */;
    assert(std::ranges::equal(res40, std::vector{8, 6, 2}));

    // 41. Get the squares of the first 3 even values.
    auto res41 = /* TODO */;
    assert(std::ranges::equal(res41, std::vector{64, 36, 4}));

    // 42. Get all values in the inclusive range [3, 7].
    auto res42 = /* TODO */;
    assert(std::ranges::equal(res42, std::vector{3, 6, 7, 4}));

    // 43. Get values in [3, 7], sorted ascending into a new vector.
    auto res43 = /* TODO */;
    assert((res43 == std::vector<int>{3, 4, 6, 7}));

    // 44. Find the first even value greater than 5.
    auto res44 = /* TODO */;
    assert(res44 != v.end());
    assert(*res44 == 8);

    // 45. Sum all values.
    auto res45 = /* TODO */;
    assert(res45 == 40);

    // 46. Sum only even values.
    auto res46 = /* TODO */;
    assert(res46 == 20);

    // 47. Find the largest even value.
    auto res47 = /* TODO */;
    assert(res47 == 8);

    // 48. Create/iterate pairs of (index, value).
    auto res48 = /* TODO */;
    auto it48 = res48.begin();
    assert(std::get<0>(*it48) == 0);
    assert(std::get<1>(*it48) == 8);

    // 49. Iterate two vectors element-by-element together.
    std::vector<int> a = {10, 20, 30, 40};
    std::vector<std::string> b = {"a", "b", "c", "d"};

    auto res49 = /* TODO */;
    auto it49 = res49.begin();
    assert(std::get<0>(*it49) == 10);
    assert(std::get<1>(*it49) == "a");

    // 50. Split the vector into chunks of 3.
    auto res50 = /* TODO */;
    auto it50 = res50.begin();
    assert(std::ranges::equal(*it50, std::vector{8, 3, 1}));
}
