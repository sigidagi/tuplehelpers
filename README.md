
# C++11 tuple helpers 


This small C++11 library provides some additional functionality using tuples: iterate through all elements in a tuple
and apply a function(functor) to those elements, unpack tuple at the compile time and apply tupe elements to a function
as an arguments.

## Example 1
```c++
#include <iostream>
#include "unpack_tuple.hpp"

// -------- Free functions ------
void one(int i, double d)
{
    std::cout << "function one(" << i << ", " << d << ");\n";
}

int two(int i)
{
    std::cout << "function two(" << i << ");\n";
    return i;
}

int main()
{
    
    std::tuple<int, double> tup(23, 4.5);

    // unpack tuple and apply to the function
    tuple11::apply(one, tup);
    int d = tuple11::apply(two, std::make_tuple(2));    

    return 0;
}
```

## Example 2
```c++
#include <iostream>
#include "for_each.hpp"

// -------------- Example classes ------
struct Foo {
    
    void doSomething() const { std::cout << "Foo" << std::endl; }
};

struct Bar{
    
    void doSomething() const { std::cout << "Bar" << std::endl; } 
};

struct Beer{
    
    void doSomething() const { std::cout <<"Beer" << std::endl; }
};


// ---------- FUNCTOR ----------
struct Functor 
{
    template<typename T>
    void operator()(T& t) const { t.doSomething(); }
};
int main()
{
    
    // iterate through the tuple elements. 
    std::tuple<Foo, Bar, Beer>  foobarbeer = std::make_tuple(Foo(), Bar(), Beer());

    tuple11::for_each(foobarbeer, Functor() );

    return 0;
}
```
## License 
BSD

## How to install

The library is header only. Some tests are provided in 'test' directory. Tested with compilers g++ and clang++: 

    g++ test_for_each.cpp -std=c++11 -I../ where library header files exist.
