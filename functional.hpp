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
    class negate : public details::unary_function<Tuple, N, std::negate<Element<N, Tuple>>> {};

    template< std::size_t N, typename Tuple>
    class take : std::unary_function<Tuple, Element<N, Tuple>> 
    {
        public:
            Element<N, Tuple> operator()(const Tuple& tup) const {
                return std::get<N>(tup);
            }
    };


    // ------------- binary functors ---------- 
    template<std::size_t N, typename Tuple>
    class less : public details::binary_function<Tuple, N, std::less<Element<N, Tuple>>> {};
 
    template<std::size_t N, typename Tuple>
    class equal : public details::binary_function<Tuple, N, std::equal_to<Element<N, Tuple>>> {};

    template<std::size_t N, typename Tuple>
    class plus : public details::binary_function<Tuple, N, std::plus<Element<N, Tuple>>> {};
   
    template<std::size_t N, typename Tuple>
    class minus : public details::binary_function<Tuple, N, std::minus<Element<N, Tuple>>> {};

    template<std::size_t N, typename Tuple>
    class multiplies : public details::binary_function<Tuple, N, std::multiplies<Element<N, Tuple>>> {};



    // ----- some helper function - wrapers around functors.-----
    template<typename std::size_t N, typename Tuple>
    std::vector<Element<N, Tuple>> extract(const std::vector<Tuple>& tup)
    {
        std::vector<Element<N, Tuple>> out(tup.size());
        std::transform(tup.begin(), tup.end(), out.begin(), take<N, Tuple>());
        return std::move(out);
    }
    
        
} // namespace tuple11

#endif
