#include <algorithm>
#include <cassert>
#include <functional>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> v = {7, 2, 9, 4, 2, 8, 1, 6};

    // 1. Check whether v contains 9.
    auto res1 = /* TODO */;
    assert(res1 == true);

    // 2. Find the first value greater than 5.
    auto res2 = /* TODO */;
    assert(res2 != v.end());
    assert(*res2 == 7);

    // 3. Check whether any value is negative.
    auto res3 = /* TODO */;
    assert(res3 == false);

    // 4. Check whether all values are positive.
    auto res4 = /* TODO */;
    assert(res4 == true);

    // 5. Count how many values are even.
    auto res5 = /* TODO */;
    assert(res5 == 5);

    // 6. Find the minimum value.
    auto res6 = /* TODO */;
    assert(res6 != v.end());
    assert(*res6 == 1);

    // 7. Find the maximum value.
    auto res7 = /* TODO */;
    assert(res7 != v.end());
    assert(*res7 == 9);

    // 8. Sort v ascending.
    {
        auto copy = v;
        /* TODO */
        assert((copy == std::vector<int>{1, 2, 2, 4, 6, 7, 8, 9}));
    }

    // 9. Sort v descending.
    {
        auto copy = v;
        /* TODO */
        assert((copy == std::vector<int>{9, 8, 7, 6, 4, 2, 2, 1}));
    }

    // 10. Reverse v.
    {
        auto copy = v;
        /* TODO */
        assert((copy == std::vector<int>{6, 1, 8, 2, 4, 9, 2, 7}));
    }
}
