#include <algorithm>
#include <cassert>
#include <numeric>
#include <ranges>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
    std::vector<int> v = {8, 3, 1, 6, 9, 2, 7, 4};

    // 40. Get the first 3 even values.
    auto res40 = v | std::views::filter([](auto& x) { return x % 2 == 0; }) |
                 std::views::take(3);
    assert(std::ranges::equal(res40, std::vector{8, 6, 2}));

    // 41. Get the squares of the first 3 even values.
    auto res41 = v | std::views::filter([](auto x) { return x % 2 == 0; }) |
                 std::views::take(3) |
                 std::views::transform([](auto& x) { return x * x; });
    assert(std::ranges::equal(res41, std::vector{64, 36, 4}));

    // 42. Get all values in the inclusive range [3, 7].
    auto res42 =
        v | std::views::filter([](auto x) { return x >= 3 && x <= 7; });
    assert(std::ranges::equal(res42, std::vector{3, 6, 7, 4}));

    // 43. Get values in [3, 7], sorted ascending into a new vector.
    auto res43 = v |
                 std::views::filter([](auto x) { return x >= 3 && x <= 7; }) |
                 std::ranges::to<std::vector>();
    std::ranges::sort(res43);
    assert((res43 == std::vector<int>{3, 4, 6, 7}));

    // 44. Find the first even value greater than 5.
    auto res44 =
        std::ranges::find_if(v, [](auto& x) { return x % 2 == 0 && x > 5; });
    assert(res44 != v.end());
    assert(*res44 == 8);

    // 45. Sum all values.
    auto res45 = std::ranges::fold_left(v, 0, std::plus{});
    assert(res45 == 40);

    // 46. Sum only even values.
    auto res46 = std::ranges::fold_left(
        v | std::views::filter([](int x) { return x % 2 == 0; }), 0,
        std::plus{});
    assert(res46 == 20);

    // 47. Find the largest even value.
    auto res47 = std::ranges::max(
        v | std::views::filter([](int x) { return x % 2 == 0; }));
    assert(res47 == 8);

    // 48. Create/iterate tuples of (index, value).
    auto res48 = v | std::views::enumerate;
    auto it48 = res48.begin();
    assert(std::get<0>(*it48) == 0);
    assert(std::get<1>(*it48) == 8);

    // 49. Iterate two vectors element-by-element together.
    std::vector<int> a = {10, 20, 30, 40};
    std::vector<std::string> b = {"a", "b", "c", "d"};

    auto res49 = std::views::zip(a, b);
    auto it49 = res49.begin();
    assert(std::get<0>(*it49) == 10);
    assert(std::get<1>(*it49) == "a");

    // 50. Split the vector into chunks of 3.
    auto res50 = v | std::views::chunk(3);
    auto it50 = res50.begin();
    assert(std::ranges::equal(*it50, std::vector{8, 3, 1}));
}