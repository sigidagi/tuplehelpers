/*
 * =====================================================================================
 *
 *       Filename:  for_each.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:11:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#ifndef _FOR_EACH_H
#define _FOR_EACH_H


#include <tuple>
#include "details/make_indexes.hpp"


namespace tuple11 {
    namespace details {
    
        template<typename Func, typename Last>
        void for_each_impl(Func&& f, Last&& last)
        {
            f(last);
        }

        template<typename Func, typename First, typename ... Rest>
        void for_each_impl(Func&& f, First&& first, Rest&&...rest) 
        {
            f(first);
            for_each_impl( std::forward<Func>(f), rest...);
        }

        template<typename Func, int ... Indexes, typename ... Args>
        void for_each_helper( Func&& f, index_tuple<Indexes...>, std::tuple<Args...>&& tup)
        {
            for_each_impl( std::forward<Func>(f), std::forward<Args>(std::get<Indexes>(tup))...);
        }
    
    } // namespace details 

    template<typename Func, typename ... Args>
    void for_each( std::tuple<Args...>& tup, Func&& f)
    {
       for_each_helper(std::forward<Func>(f), 
                       typename details::make_indexes<Args...>::type(), 
                       std::forward<std::tuple<Args...>>(tup) );
    }

    template<typename Func, typename ... Args>
    void for_each( std::tuple<Args...>&& tup, Func&& f)
    {
       for_each_helper(std::forward<Func>(f), 
                       typename details::make_indexes<Args...>::type(), 
                       std::forward<std::tuple<Args...>>(tup) );
    }

} // namespace code11


#endif
