# Ranges

## Level 1 : std algos to their ranges counterparts

for the large part
`std::ALGO(begin(range), end(range), args...)`
can be written as
`std::ranges::ALGO(range, args...)`

any_of, all_of, none_of => take a predicate
contains => exact check, no pred

count, count_if

find series

- find / find_end
- find_if / find_if_not
- adjacent_find
- first_first_of => in list 1 where it exists in list 2

`std::transform(from start, from end, to start, op)`

### Where ranges differs somewhat

find != end becomes contains

## Level 2 : views

Views are lazy ranges, they don't own the data and will just lazily apply
transformations on the data.

```cpp
v | std::views::algo
is the range adaptor syntax
internally it converts to
std::ranges::algo_view but that usage directly is a bit ugly
```

converting to vector
`std::ranges::to<std::vector>()` as the last chain.

> These view ops are for lazy reading and to is for new vec creation, using to modify
> existing vecs is less performant as you are making a new vec and then just assigning

## Level 3 : in place mutations

### The erase remove idiom from pre cpp20

```cpp
v.erase(
    std::remove_if(
        v.begin(),
        v.end(),
        [](int x) { return x % 2 != 0; }
    ),
    v.end()
);
```

Remove moved those elements to the end and returns the new end. It does not actually
delete so you needed to then wrap the whole thing in erase.

This is better in cpp20.

Note that this is NOT `v.erase`, rather `std::erase`, it also has range like semantics
somehow which is a bit inconsistent from an api perspective for me.

`v.erase` works with iterators only.

## Level 4 : Projections

The pointer to member variable syntax.

`int Persion::*` is a pnter to an int inside struct Person
`int (Person::*)() const` pointer to a const member function of struct Person taking no args and returning int

`int Person::* ptr = &Person::age;` this'll relate closely to projections

`std::invoke` uses templates/overloads to handle pointer to member types

at the ranges layer it just uses invoke with projection and the iterator and it all "just works"

| Common `std::invoke` use case    | Example                         | Equivalent idea |
| -------------------------------- | ------------------------------- | --------------- |
| Free function / lambda / functor | `std::invoke(f, x)`             | `f(x)`          |
| Member function                  | `std::invoke(&T::func, obj, x)` | `obj.func(x)`   |
| Data member                      | `std::invoke(&T::member, obj)`  | `obj.member`    |
| Member via pointer               | `std::invoke(&T::func, ptr)`    | `ptr->func()`   |

For most cases, you'll use it like -> the member variable projection
`std::ranges::sort(people, {}, &Person::age);`
`{}` = use default comparator

## Level 5 : Ops on maps

### What is pipeable?

```
#include<views> stuff
range adapter closure objects -> views stuff are pipeable

ranges headers are split across <ranges>, <algorithm>
and <numeric>
in general algos you can't pipe so contains etc you pass in the
lazy view as the first arg, not pipe

ranges::to you can pip
```

In general you can work with any stl container, and use the type as
it would map to in a range based loop => pair for maps

`std::views::keys` and `std::views::values` are handy

## Level 6 : More advanced compositions

Filtering and sorting? try not to do as one step, split it
though you can do a multiset conversion for a one liner.

Try not to chain filters, just compose them into one.
It should be a set of distinct ops if possible.

`std::ranges::fold_left` over accumulate

max vs max_element => first returns the val while second the iterator
which is dangling if the view is built inline
in fact the return type is `std::ranges::dangling` to avoid such cases
