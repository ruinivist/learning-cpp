#include <algorithm>
#include <cassert>
#include <vector>

int main() {
    // 21. Remove every 2.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        std::erase(v, 2);
        assert((v == std::vector<int>{1, 3, 4, 5}));
    }

    // 22. Remove every odd value.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        std::erase_if(v, [](int x) { return x & 1; });
        assert((v == std::vector<int>{2, 2, 4, 2}));
    }

    // 23. Replace every 2 with 20.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        std::ranges::replace(v, 2, 20);
        assert((v == std::vector<int>{1, 20, 3, 20, 4, 20, 5}));
    }

    // 24. Set every element to 0.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        std::ranges::fill(v, 0);
        assert((v == std::vector<int>{0, 0, 0, 0, 0, 0, 0}));
    }

    // 25. Remove consecutive duplicates.
    {
        std::vector<int> v = {1, 1, 2, 2, 2, 3, 4, 4};
        // ranges::unqiue returns a subrange with it's own begin and end
        // it is the subrange that should be erase so better looks is
        // to_del = unique
        // v.erase(to_del.begin(),to_del.end())
        v.erase(std::ranges::unique(v).begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4}));
    }

    // 26. Remove all duplicates, regardless of position.
    {
        std::vector<int> v = {4, 1, 2, 4, 2, 3, 1, 3};
        std::ranges::sort(v);
        v.erase(std::ranges::unique(v).begin(), v.end());
        assert((v == std::vector<int>{1, 2, 3, 4}));
    }
}
