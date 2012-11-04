/*
 * =====================================================================================
 *
 *       Filename:  tuple_print.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2012 10:00:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */
#ifndef _TUPLE_PRINT_H
#define _TUPLE_PRINT_H

#include "details/make_indexes.hpp"
#include <tuple>

using std::tuple;


namespace tuple11 {
    namespace details {
 
        template<typename Last>
        void print_impl(Last&& last)
        {
            std::cout << " " << last << std::endl;
        }
       
        template<typename Head, typename ... Tail>
        void print_impl(Head&& head, Tail&& ... tail)
        {
            std::cout << " " << head;
            print_impl(tail...);
        }
        

        template<typename ... Args, int ... Indexes > 
        void tuple_print_impl( index_tuple< Indexes... >, tuple<Args...>&& tup) 
        { 
            print_impl( std::forward<Args>( std::get<Indexes>(tup))... ); 
        } 

    } // namespace details 


    template<typename ... Args> 
    void print(const tuple<Args...>&  tup)
    {
        details::tuple_print_impl(typename details::make_indexes<Args...>::type(), tuple<Args...>(tup));
    }

    template<typename ... Args> 
    void print(tuple<Args...>&&  tup)
    {
        details::tuple_print_impl(typename details::make_indexes<Args...>::type(), std::forward<tuple<Args...>>(tup));
    }

} // namespace tuple11


#endif
