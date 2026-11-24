# Creational patterns in C++

The Pluralsight coffee-kiosk lab, with the completed solutions and a small demo. Run this from the directory containing the Makefile with Make and a C++14 compiler.

```sh
make run
```

## Where to look

| Pattern | What to look for |
| --- | --- |
| Singleton | `MachineConfig::instance()` gives the kiosk access to the same settings object on each call. A function-local static creates it on first use, and the class blocks construction and copying from outside. [`machine_config.cpp`](src/machine_config.cpp) |
| Builder | Each setter keeps its option and returns the builder so you can chain the next setter. `build()` assembles the accumulated options into a `CoffeeDrink`. [`coffee_drink_builder.cpp`](src/coffee_drink_builder.cpp) |
| Prototype | The registry keeps a signature recipe. Each order for that recipe gets an independent copy through `clone()`. [`drink_prototype_registry.cpp`](src/drink_prototype_registry.cpp) |
| Drink factory | `createDrink(OrderType)` is a simple factory. Its switch selects a builder recipe for the standard menu drinks or asks the registry for a signature drink. [`drink_factory.cpp`](src/drink_factory.cpp) |
| Abstract Factory | Choose the regular or decaf factory once and use the same interface to get both the coffee base and its matching milk. [`ingredient_factory.h`](src/ingredient_factory.h) |

In [`main.cpp`](src/main.cpp), the kiosk constructs the heater, grinder, and logger and passes them to `CoffeeMachine`. That's constructor injection. Checkout uses the same approach with a payment processor that approves the demo charge.
