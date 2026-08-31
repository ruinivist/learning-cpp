#include <algorithm>
#include <cassert>
#include <map>
#include <ranges>
#include <string>
#include <vector>

int main()
{
    std::map<std::string, int> m = {
        {"a", 4},
        {"b", 9},
        {"c", 2},
    };

    // 35. Produce a lazy range containing only the keys.
    auto res35 = /* TODO */;
    assert(std::ranges::equal(res35, std::vector<std::string>{"a", "b", "c"}));

    // 36. Produce a lazy range containing only the values.
    auto res36 = /* TODO */;
    assert(std::ranges::equal(res36, std::vector{4, 9, 2}));

    // 37. Check whether any mapped value is greater than 5.
    auto res37 = /* TODO */;
    assert(res37 == true);

    // 38. Produce a lazy range of mapped values multiplied by 10.
    auto res38 = /* TODO */;
    assert(std::ranges::equal(res38, std::vector{40, 90, 20}));

    // 39. Produce a lazy range of keys whose associated value is greater than 3.
    auto res39 = /* TODO */;
    assert(std::ranges::equal(res39, std::vector<std::string>{"a", "b"}));
}
