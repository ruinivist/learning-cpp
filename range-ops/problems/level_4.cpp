#include <algorithm>
#include <cassert>
#include <ranges>
#include <string>
#include <vector>

struct Item
{
    int id;
    std::string name;
    int value;

    bool operator==(const Item&) const = default;
};

int main()
{
    std::vector<Item> v = {
        {10, "delta", 75},
        {3, "alpha", 120},
        {7, "echo", 0},
        {1, "bravo", 240},
        {15, "charlie", 30},
        {8, "foxtrot", 150},
    };

    // 27. Find the item whose id == 10.
    auto res27 = /* TODO */;
    assert(res27 != v.end());
    assert(res27->name == "delta");

    // 28. Sort items by id.
    {
        auto copy = v;
        /* TODO */
        assert(copy.front().id == 1);
        assert(copy.back().id == 15);
    }

    // 29. Sort items by name.
    {
        auto copy = v;
        /* TODO */
        assert(copy.front().name == "alpha");
        assert(copy.back().name == "foxtrot");
    }

    // 30. Find the item with the largest value.
    auto res30 = /* TODO */;
    assert(res30 != v.end());
    assert(res30->id == 1);

    // 31. Check whether any item has value == 0.
    auto res31 = /* TODO */;
    assert(res31 == true);

    // 32. Count items whose value > 100.
    auto res32 = /* TODO */;
    assert(res32 == 3);

    // 33. Create a lazy view containing only the names.
    auto res33 = /* TODO */;
    assert(std::ranges::equal(
        res33,
        std::vector<std::string>{"delta", "alpha", "echo", "bravo", "charlie", "foxtrot"}
    ));

    // 34. Create a vector of names whose value > 100.
    auto res34 = /* TODO */;
    assert((res34 == std::vector<std::string>{"alpha", "bravo", "foxtrot"}));
}
