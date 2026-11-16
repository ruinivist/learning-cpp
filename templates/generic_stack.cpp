#include <array>
#include <cstddef>
#include <optional>
#include <stdexcept>
#include <utility>

template <typename T>
class Stack {
   private:
    // you can make a resizable array here but that's not the point of this
    // problem so an array with a FIXED internal and hidden size is fine
    static const int MAX_SIZE = 100;
    std::array<std::optional<T>, MAX_SIZE> arr{};
    std::size_t top_ = 0;

    void check_full() {
        if (top_ == MAX_SIZE) throw std::runtime_error("exceeded max size");
    }

    void check_empty() {
        if (top_ == 0) throw std::runtime_error("empty stack");
    }

   public:
    void push(const T& elem) {
        // if you get here, T needs to be copy constructible
        check_full();
        // why emplace? if you assing you would need to be copy assignable as
        // well, that'll be ONE more restriction
        arr[top_++].emplace(elem);
    }

    void push(T&& elem) {
        check_full();
        // elem is an lvalue now because it has a name
        arr[top_++].emplace(std::move(elem));
    }

    T pop() {
        check_empty();
        // return *arr[--top_];
        // ^ is wrong as if you return by value stuff which is move only
        // like unique pointers will break as this is what happens
        // std::unique_ptr<int>& ptr = *arr[index];
        // return ptr;  // ERROR: attempts to copy

        // things to consider
        // what I have below is NOT NRVO, had it been standard guarantees move
        // so I don't need to do the std::move when I return
        // optional reset ( can be skipped but good to do )

        return std::move(*arr[--top_]);

        // alternate
        // T result = std::move(*arr[top_ - 1]);
        // arr[top_ - 1].reset();
        // --top_;

        // return result; // NRVO here
    }
};