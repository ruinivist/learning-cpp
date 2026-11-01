# Cpp Brain Teasers

1. Initialisation on member initializer list vs ctor body vs class body.

Class level ones run first unless you define something in mem initializer list.
Then ctor body.

> initialising at class level is same as initialising in member initializer list
> later is used when you want something different per ctor rather than common

2. overload resolution rules

viable function -> best viable based on closest mach
standard coversions take priority over user defined ones ( ctors )

3. Using unitialised is UB but if you match the stacks perfecly it'll work

a note on sanitizers as well that catch such cases but they are runtime ones.
For the super trivial case here, just `-Wuninitialized` is enough.

4. Cost of static init and why garbage values are even a thing

the cost of static init being 0 due to OS level memory safety rules is a good idea to know of.

5. Destrouctors, subobjects and dynamic dispatch

First I read of "subobjects".

6. Order of operations in initialiser list

is irrelevant, we only look at the order in which they are define at class level.

This out of order init causes UB since if one of the members uses another at a time it's not
constructed yet.

7. static vs local static for user defined objects

when are globals created? before main ( actually before any functions in the same TU ). C runtime
calls `__libc_start_main` which does the inits and then calls main.
Such types are "dynamically init" as static init is just not possible.

SIOF = order of inits in different TUs is unknown.
