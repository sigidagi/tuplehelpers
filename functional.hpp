/*
 * =====================================================================================
 *
 *       Filename:  functional_tuple.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2012 12:52:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#ifndef _FUNCTIONAL_TUPLE_H
#define _FUNCTIONAL_TUPLE_H


#include "details/tuple_action.hpp"

namespace tuple11 {
    
    // ------------ unary functions -----------
    template<typename Tuple, std::size_t N>
    class negate : public details::unary_function<Tuple, N, std::negate<typename std::tuple_element<N, Tuple>::type>>{};


    // ------------- binary functions ---------- 
    template<typename Tuple, std::size_t N>
    class compare : public details::binary_function<Tuple, N, std::less<typename std::tuple_element<N, Tuple>::type>> {};
 
    template<typename Tuple, std::size_t N>
    class equal : public details::binary_function<Tuple, N, std::equal_to<typename std::tuple_element<N, Tuple>::type>> {};

    template<typename Tuple, std::size_t N>
    class plus : public details::binary_function<Tuple, N, std::plus<typename std::tuple_element<N, Tuple>::type>> {};
   
    template<typename Tuple, std::size_t N>
    class minus : public details::binary_function<Tuple, N, std::minus<typename std::tuple_element<N, Tuple>::type>> {};

    template<typename Tuple, std::size_t N>
    class multiplies : public details::binary_function<Tuple, N, std::multiplies<typename std::tuple_element<N, Tuple>::type>> {};


        
} // namespace code11

#endif
