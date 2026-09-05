#include <algorithm>
#include <cassert>
#include <functional>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> v = {7, 2, 9, 4, 2, 8, 1, 6};

    // 1. Check whether v contains 9.
    auto res1 = std::find(v.begin(), v.end(), 9) != v.end();
    res1 = std::ranges::contains(v, 9);
    assert(res1 == true);

    // 2. Find the first value greater than 5.
    // NOT UPPER BOUND
    auto res2 = std::find_if(v.begin(), v.end(), [](auto& x) { return x > 5; });
    res2 = std::ranges::find_if(v, [](int x) { return x > 5; });
    assert(res2 != v.end());
    assert(*res2 == 7);

    // 3. Check whether any value is negative.
    auto res3 = std::any_of(v.begin(), v.end(), [](auto& x) { return x < 0; });
    res3 = std::ranges::any_of(v, [](int x) { return x < 0; });
    assert(res3 == false);

    // 4. Check whether all values are positive.
    auto res4 = std::all_of(v.begin(), v.end(), [](auto& x) { return x > 0; });
    res4 = std::ranges::all_of(v, [](int x) { return x > 0; });
    assert(res4 == true);

    // 5. Count how many values are even.
    auto res5 =
        std::count_if(v.begin(), v.end(), [](auto& x) { return x % 2 == 0; });
    res5 = std::ranges::count_if(v, [](int x) { return x % 2 == 0; });
    assert(res5 == 5);

    // 6. Find the minimum value.
    auto res6 = std::min_element(v.begin(), v.end());
    res6 = std::ranges::min_element(v);
    assert(res6 != v.end());
    assert(*res6 == 1);

    // 7. Find the maximum value.
    auto res7 = std::max_element(v.begin(), v.end());
    res7 = std::ranges::max_element(v);
    assert(res7 != v.end());
    assert(*res7 == 9);

    // 8. Sort v ascending.
    {
        auto copy = v;
        std::sort(copy.begin(), copy.end());
        std::ranges::sort(copy);
        assert((copy == std::vector<int>{1, 2, 2, 4, 6, 7, 8, 9}));
    }

    // 9. Sort v descending.
    {
        auto copy = v;
        std::sort(copy.begin(), copy.end(), std::greater<>());
        std::ranges::sort(copy, std::greater<>());
        assert((copy == std::vector<int>{9, 8, 7, 6, 4, 2, 2, 1}));
    }

    // 10. Reverse v.
    {
        auto copy = v;
        // std::reverse(copy.begin(), copy.end());
        std::ranges::reverse(copy);
        assert((copy == std::vector<int>{6, 1, 8, 2, 4, 9, 2, 7}));
    }
}
