/*
 * =====================================================================================
 *
 *       Filename:  test_for_each.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:56:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#include <iostream>
#include <functional>
#include "for_each.hpp"
#include "unpack.hpp"



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


// -------- Free function ------
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
    
    // iterate through the tuple elements. 
    std::tuple<Foo, Bar, Beer>  foobarbeer = std::make_tuple(Foo(), Bar(), Beer());
    tuple11::for_each(foobarbeer, Functor() );

    
    // unpack tuple and apply to the function
    std::tuple<int, double> tup(23, 4.5);
    tuple11::apply(one, tup);

    int d = tuple11::apply(two, std::make_tuple(2));    
    (void)d; // just to supress warninig - unused-variable.


    return 0;
}
