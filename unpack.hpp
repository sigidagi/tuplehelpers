/*
 * =====================================================================================
 *
 *       Filename:  unpack_tuple.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 11:01:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#ifndef _UNPACK_TUPLE_H
#define _UNPACK_TUPLE_H

#include <tuple>
#include "details/make_indexes.hpp"

using std::tuple;
using std::forward;
using std::get;

namespace tuple11 {
    namespace details {

        template<class Ret, class... Args, int... Indexes > 
        Ret apply_helper( Ret (*pf)(Args...), index_tuple< Indexes... >, tuple<Args...>&& tup) 
        { 
            return pf( forward<Args>( get<Indexes>(tup))... ); 
        } 

    } // namespace tuple11


    template<class Ret, class ... Args> 
    Ret apply(Ret (*pf)(Args...), const tuple<Args...>&  tup)
    {
        return details::apply_helper(pf, typename details::make_indexes<Args...>::type(), tuple<Args...>(tup));
    }

    template<class Ret, class ... Args> 
    Ret apply(Ret (*pf)(Args...), tuple<Args...>&&  tup)
    {
        return details::apply_helper(pf, typename details::make_indexes<Args...>::type(), forward<tuple<Args...>>(tup));
    }

} // namespace tuple11


#endif
