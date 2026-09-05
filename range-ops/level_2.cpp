#include <algorithm>
#include <cassert>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> v = {-3, 4, -1, 8, 5, 2, -6};

    // 11. Produce a lazy range containing only positive values.
    auto res11 = v | std::views::filter([](int x) { return x > 0; });
    // res11 = std::views::filter(v, [](int x) { return x > 0; });
    // These above are identical except each lambda is a unqiue type so won't
    // compile if I keep both and use the same auto type
    assert(std::ranges::equal(res11, std::vector{4, 8, 5, 2}));

    // 12. Produce a lazy range containing only even values.
    auto res12 = v | std::views::filter([](int x) { return x % 2 == 0; });
    assert(std::ranges::equal(res12, std::vector{4, 8, 2, -6}));

    // 13. Produce a lazy range containing the square of every value.
    auto res13 = v | std::views::transform([](int x) { return x * x; });
    assert(std::ranges::equal(res13, std::vector{9, 16, 1, 64, 25, 4, 36}));

    // 14. Produce squares of only the positive values.
    // auto res14 = v | std::views::filter([](int x) { return x > 0; });
    // filter_view is the actual underlying sitting below the | based range
    // adaptor syntax
    auto res14 = std::ranges::filter_view(v, [](int x) { return x > 0; }) |
                 std::views::transform([](int x) { return x * x; });
    assert(std::ranges::equal(res14, std::vector{16, 64, 25, 4}));

    // 15. Keep only values greater than 3, then double them.
    auto res15 = v | std::views::filter([](int x) { return x > 3; }) |
                 std::views::transform([](int x) { return 2 * x; });
    assert(std::ranges::equal(res15, std::vector{8, 16, 10}));

    // 16. Take the first 3 values.
    auto res16 = v | std::views::take(3);
    assert(std::ranges::equal(res16, std::vector{-3, 4, -1}));

    // 17. Skip the first 2 values.
    auto res17 = v | std::views::drop(2);
    assert(std::ranges::equal(res17, std::vector{-1, 8, 5, 2, -6}));

    // 18. Take the first 2 positive values.
    auto res18 = v | std::views::filter([](int x) { return x > 0; }) |
                 std::views::take(2);
    assert(std::ranges::equal(res18, std::vector{4, 8}));

    // 19. Create a new vector containing only positive values.
    auto res19 = v | std::views::filter([](int x) { return x > 0; }) |
                 std::ranges::to<std::vector<int>>();
    assert((res19 == std::vector<int>{4, 8, 5, 2}));

    // 20. Create a new vector containing doubled even values.
    auto res20 = v | std::views::filter([](int x) { return x % 2 == 0; }) |
                 std::views::transform([](int x) { return 2 * x; }) |
                 std::ranges::to<std::vector>();
    assert((res20 == std::vector<int>{8, 16, 4, -12}));
}
