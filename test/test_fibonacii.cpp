/*
 * =====================================================================================
 *
 *       Filename:  test_fibonacii.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:59:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#include <tuple>   
#include <iostream>

template<int N>
struct Fib
{
    enum { value = Fib<N-1>::value + Fib<N-2>::value };
};

template<>
struct Fib<1>
{
    enum { value = 1 };
};

template<>
struct Fib<0>
{
    enum { value = 0 };
};


// ----------------------
template<int N, typename Tuple, typename ... Types>
struct make_fibtuple_impl;

template<int N, typename ... Types>
struct make_fibtuple_impl<N, std::tuple<Types...> >
{
    typedef typename make_fibtuple_impl<N-1, std::tuple<Fib<N>, Types... > >::type type;
};

template<typename ... Types>
struct make_fibtuple_impl<0, std::tuple<Types...> >
{
    typedef std::tuple<Fib<0>, Types... > type;
};

template<int N>
struct make_fibtuple : make_fibtuple_impl<N, std::tuple<> >
{};


int main()
{
   auto tup = typename make_fibtuple<25>::type();
   std::cout << std::get<20>(tup).value;  
   std::cout << std::endl; 

   return 0;
}
