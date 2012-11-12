/*
 * =====================================================================================
 *
 *       Filename:  zip.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2012 11:36:23 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#include "details/make_indexes.hpp"
#include <utility>
#include <tuple>

using std::tuple;

namespace tuple11 {

    namespace details {
    
        template<std::size_t N, typename T1, typename T2>
        using pair_type = std::pair<typename std::tuple_element<N, T1>::type, typename std::tuple_element<N, T2>::type>;

        template<std::size_t N, typename T1, typename T2> 
        pair_type<N, T1, T2> pair(const T1& tup1, const T2& tup2)
        {
            //
            return std::make_pair( std::get<N>(tup1), std::get<N>(tup2) ); 
        }

        template<int... Indexes, typename T1, typename T2>
        auto pairs_helper( index_tuple<Indexes...>, const T1& tup1, const T2& tup2) -> decltype( std::make_tuple( pair<Indexes>(tup1, tup2)... ) )       
        {
            return std::make_tuple( pair<Indexes>(tup1, tup2)... );
        }

    } // namespace details
    
    using details::make_indexes;

   template<typename... Args1, typename... Args2>
   auto pairs(const tuple<Args1...>& tup1, const tuple<Args2...>& tup2) -> decltype( details::pairs_helper(typename make_indexes<Args1...>::type(), tup1, tup2) )
   {
        static_assert(sizeof... (Args1) == sizeof... (Args2), "tuples should be the same size.");          
        return details::pairs_helper( typename make_indexes<Args1...>::type(), tup1, tup2 );
   }



} // namespace tuple11



