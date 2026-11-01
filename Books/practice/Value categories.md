# C++ Value Categories

## Problem 1 — Identify the Value Category

Classify each expression as:

- **L** — lvalue
- **X** — xvalue
- **P** — prvalue

```cpp
int x = 1, y = 2;
int&& rr = 3;
int* p = &x;

int&  getL();
int&& getR();
int   getV();
```

| #   | Expression       | Category |
| --- | ---------------- | -------- |
| A   | `x`              | ?        |
| B   | `rr`             | ?        |
| C   | `std::move(x)`   | ?        |
| D   | `*p`             | ?        |
| E   | `++x`            | ?        |
| F   | `x++`            | ?        |
| G   | `getL()`         | ?        |
| H   | `getR()`         | ?        |
| I   | `getV()`         | ?        |
| J   | `(true ? x : y)` | ?        |
| K   | `(true ? x : 0)` | ?        |

**Questions:**

1. Why does the declared type of `rr` not determine
   the value category of the expression `rr`?
2. Why do `++x` and `x++` have different categories?
3. Why do J and K have different categories?

---

## Problem 2 — Reference Binding

Which declarations compile?

Treat each line independently.

```cpp
int x = 1;

int&       a = 5;
const int& b = 5;
int&&      c = x;
int&&      d = std::move(x);
int&&      e = 5;
```

**Tasks:**

1. Mark each declaration VALID or INVALID.
2. Explain the binding rules.
3. For every valid reference, identify what
   object it refers to.
4. Identify where temporary lifetime extension occurs.

---

## Problem 3 — auto, decltype, and References

Determine the exact declared type of every variable.

Include `const`, `&`, and `&&` where appropriate.

```cpp
int x = 1;
const int cx = 2;

auto a = (x);
auto& b = cx;

auto&& c = x;
auto&& d = 7;

decltype(x) e = 0;
decltype((x)) f = x;

decltype(auto) g = (x);
decltype(auto) h = std::move(x);
```

| Variable | Exact type |
| -------- | ---------- |
| `a`      | ?          |
| `b`      | ?          |
| `c`      | ?          |
| `d`      | ?          |
| `e`      | ?          |
| `f`      | ?          |
| `g`      | ?          |
| `h`      | ?          |

**Questions:**

1. What is the difference between `decltype(x)`
   and `decltype((x))`?
2. Why can `auto&&` deduce an lvalue reference?
3. How does `decltype(auto)` differ from plain `auto`?

---

## Problem 4 — Overloading and Perfect Forwarding

Predict the **exact output**.

```cpp
void f(int&) {
    std::cout << "L";
}

void f(const int&) {
    std::cout << "C";
}

void f(int&&) {
    std::cout << "R";
}

template<class T>
void relay(T&& v) {
    f(v);
    f(std::forward<T>(v));
}

int x = 0;
const int cx = 0;
int&& rr = 1;

f(x);
f(cx);
f(7);
f(rr);
f(std::move(rr));
f(std::move(cx));

std::cout << " | ";

relay(x);

std::cout << " | ";

relay(7);
```

**Tasks:**

1. Write the exact output.
2. Explain the selected overload for each call.
3. Determine the deduced `T` for `relay(x)` and
   `relay(7)`.
4. Explain why `v` and `std::forward<T>(v)`
   can select different overloads.
5. Explain why `std::move(cx)` does not bind
   to `int&&`.

---

## Problem 5 — Does a Move Actually Happen?

Predict the exact output in C++17 or later.

```cpp
struct Box {
    Box() = default;

    Box(const Box&) {
        std::cout << "C";
    }

    Box(Box&&) {
        std::cout << "M";
    }
};

Box make() {
    return Box{};
}

Box a = make();
Box b = a;
Box c = std::move(a);

const Box d;
Box e = std::move(d);
```

**Tasks:**

1. Write the exact output.
2. For each initialization, classify it as:
   - Copy construction
   - Move construction
   - Neither
3. Explain guaranteed copy elision.
4. Explain what `std::move` actually does.
5. Why does `std::move(d)` behave differently
   from `std::move(a)`?

---

## Problem 6 — Temporaries and Lifetime

Consider:

```cpp
const std::string& a =
    std::string("ok");

std::string&& b =
    std::string("ok");

const std::string& c =
    std::move(std::string("oops"));

std::string_view d =
    std::string("oops");
```

**Tasks:**

1. Which variables can safely be used on the
   following statement?
2. Which variables refer to or view objects
   that have already been destroyed?
3. Identify exactly when each temporary is destroyed.
4. Explain why reference binding does not always
   extend an object's lifetime.
5. Explain why `std::string_view` introduces
   an additional lifetime risk.

---

## Completion Criteria

You have mastered the essentials when you can:

- [ ] Distinguish lvalue, xvalue, and prvalue expressions.
- [ ] Separate types from expression value categories.
- [ ] Predict reference binding correctly.
- [ ] Apply reference collapsing rules.
- [ ] Understand `auto`, `auto&&`, and `decltype(auto)`.
- [ ] Predict overload resolution involving references.
- [ ] Explain `std::move` and `std::forward`.
- [ ] Distinguish moves from copies and copy elision.
- [ ] Identify dangling references and lifetime bugs.
