#include <algorithm>
#include <cassert>
#include <vector>

int main()
{
    // 21. Remove every 2.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        /* TODO */
        assert((v == std::vector<int>{1, 3, 4, 5}));
    }

    // 22. Remove every odd value.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        /* TODO */
        assert((v == std::vector<int>{2, 2, 4, 2}));
    }

    // 23. Replace every 2 with 20.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        /* TODO */
        assert((v == std::vector<int>{1, 20, 3, 20, 4, 20, 5}));
    }

    // 24. Set every element to 0.
    {
        std::vector<int> v = {1, 2, 3, 2, 4, 2, 5};
        /* TODO */
        assert((v == std::vector<int>{0, 0, 0, 0, 0, 0, 0}));
    }

    // 25. Remove consecutive duplicates.
    {
        std::vector<int> v = {1, 1, 2, 2, 2, 3, 4, 4};
        /* TODO */
        assert((v == std::vector<int>{1, 2, 3, 4}));
    }

    // 26. Remove all duplicates, regardless of position.
    {
        std::vector<int> v = {4, 1, 2, 4, 2, 3, 1, 3};
        /* TODO */
        assert((v == std::vector<int>{1, 2, 3, 4}));
    }
}
