# Variadics in templates

We're trying to demistify this

```cpp
template <typename... Args>
void f(Args... args) {

}
```

Think of the `...` as defining a pack of what is to the left of it.
This way there are two packs in the above expression.

- a type pack => `typename...` => `Args = int, double, const char*`
- the actual arguments pack => `args` of type `Args...` => `args = 42, 2.5, "abc"`

## How do I use those types and args?

These "packs" are not a container in any way, you cannot index them. Here are
some of the ops that you an do with them

- get size => `sizeof...(Args)` or `sizeof...(args)` difference being you are
  counting the types vs the args, here ( and in general always ) both are same.

- using count or type based specialisations => if I have the same function f
  overloaded with different args / types, and I need to make a wrapper g on top of it,
  instead of repeating all those overloads I can do this "pack expansion"

```cpp
template <typename... Args>
void g(Args... args) {
    f(args...);
}
```

There's a bit of subtlety here

```cpp
f(k(args)...);  // expands to f(k(arg1), k(arg2), k(arg3))
Here, k takes one argument at a time.

f(k(args...));  // expands to f(k(arg1, arg2, arg3))
Here, k is called once with all arguments
```

- the actually useful one, processing every arg => fold expression

### Fold expression with args pack

| Fold form         | C++ syntax              | Expansion for `pack = a, b, c` | Example            |
| ----------------- | ----------------------- | ------------------------------ | ------------------ |
| Unary left fold   | `(... op pack)`         | `((a op b) op c)`              | `(... + args)`     |
| Unary right fold  | `(pack op ...)`         | `(a op (b op c))`              | `(args + ...)`     |
| Binary left fold  | `(init op ... op pack)` | `(((init op a) op b) op c)`    | `(0 + ... + args)` |
| Binary right fold | `(pack op ... op init)` | `(a op (b op (c op init)))`    | `(args + ... + 0)` |

An example

```cpp
void f(int x) {
    std::cout << x;
}

template <typename... Args>
void print(Args... args) {
    (f(args), ...);
}
```

This is the simplest unary left fold. The oprator here is `,` so what it does
is fold it right like `(f(arg0), (f(arg1), f(arg2)))`.

Note that comma is not part of the syntax, it's an opeartor in cpp which evaluates
all expressions left to right and returns the rightmost. This could very well
be a `+` operator.

`(args + ...)` => `(arg0 + (arg1 + arg2))`
note that you don't always need an f, only if you want to call some funtion on it.

```cpp
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args);
}
```

this is a init + left fold, with `<<` as the operator and `std::cout` as the init.
which makes `print(1, 2, 3);` => `((std::cout << 1) << 2) << 3;`

It starts to make a little bit of sense if you think of this as "text" manipulations
instead of actual code, otherwise I find it harder to reason about `std::cout` as init.

# Where side does the `...` go?

It's almost always to the right except in case of lambda init captures.
If cpp was consistent here, this would be a lot more nicer and easier.

| Syntax                                                                          | Meaning                                      |
| ------------------------------------------------------------------------------- | -------------------------------------------- |
| `template <typename... Args>`                                                   | Declare `Args` as a template type pack       |
| `void f(Args... args)` / `void f(Args&&... args)`                               | Declare `args` as a function parameter pack  |
| `[...stored_args = expr]`                                                       | Declare a lambda capture pack                |
| `args...` / `f(args)...` / `std::move(args)...` / `std::forward<Args>(args)...` | Expand a pack or a pattern containing a pack |
| `sizeof...(Args)` / `sizeof...(args)`                                           | Count elements in a pack                     |
