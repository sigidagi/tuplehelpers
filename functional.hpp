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
    
    // ------------ template alias -----------
    template<typename std::size_t N, typename Tuple>
    using Element = typename std::tuple_element<N, Tuple>::type;


    // ------------ unary functors-----------
    template<std::size_t N, typename Tuple>
    class negate : public details::unary_function<Tuple, N, std::negate<typename std::tuple_element<N, Tuple>::type>>{};

    template< std::size_t N, typename Tuple>
    class take : std::unary_function<Tuple, typename std::tuple_element<N, Tuple>::type> 
    {
        public:
            typename std::tuple_element<N, Tuple>::type operator()(const Tuple& tup) const {
                return std::get<N>(tup);
            }
    };


    // ------------- binary functors ---------- 
    template<std::size_t N, typename Tuple>
    class less : public details::binary_function<Tuple, N, std::less<typename std::tuple_element<N, Tuple>::type>> {};
 
    template<std::size_t N, typename Tuple>
    class equal : public details::binary_function<Tuple, N, std::equal_to<typename std::tuple_element<N, Tuple>::type>> {};

    template<std::size_t N, typename Tuple>
    class plus : public details::binary_function<Tuple, N, std::plus<typename std::tuple_element<N, Tuple>::type>> {};
   
    template<std::size_t N, typename Tuple>
    class minus : public details::binary_function<Tuple, N, std::minus<typename std::tuple_element<N, Tuple>::type>> {};

    template<std::size_t N, typename Tuple>
    class multiplies : public details::binary_function<Tuple, N, std::multiplies<typename std::tuple_element<N, Tuple>::type>> {};



    // ----- some helper function - wrapers around functors.-----
    template<typename std::size_t N, typename Tuple>
    std::vector<Element<N, Tuple>> extract(const std::vector<Tuple>& tup)
    {
        std::vector<Element<N, Tuple>> out(tup.size());
        std::transform(tup.begin(), tup.end(), out.begin(), take<N, Tuple>());
        return std::move(out);
    }
    

        
} // namespace code11

#endif
