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


    // old method - replaces by other shorter hack ---- see below
/*
 *    namespace details {
 * 
 *        template<typename Last>
 *        void print_impl(Last&& last)
 *        {
 *            std::cout << " " << last << std::endl;
 *        }
 *       
 *        template<typename Head, typename ... Tail>
 *        void print_impl(Head&& head, Tail&& ... tail)
 *        {
 *            std::cout << " " << head;
 *            print_impl(tail...);
 *        }
 *        
 *
 *        template<typename ... Args, int ... Indexes > 
 *        void tuple_print_impl( index_tuple< Indexes... >, tuple<Args...>&& tup) 
 *        { 
 *            print_impl( std::forward<Args>( std::get<Indexes>(tup))... ); 
 *        } 
 *
 *    } // namespace details 
 *
 *
 *    template<typename ... Args> 
 *    void print(const tuple<Args...>&  tup)
 *    {
 *        details::tuple_print_impl(typename details::make_indexes<Args...>::type(), tuple<Args...>(tup));
 *    }
 *
 *    template<typename ... Args> 
 *    void print(tuple<Args...>&&  tup)
 *    {
 *        details::tuple_print_impl(typename details::make_indexes<Args...>::type(), std::forward<tuple<Args...>>(tup));
 *    }
 */

    
    // ---------- another print method --------------
    template<typename T, int... Indexes>
    void print_impl2(const T& tup, tuple11::details::index_tuple<Indexes...> )
    {
        // hack 
        int garbage[] = { ((std::cout << std::get<Indexes>(tup) << " "), 0)... };
        (void)garbage; // just to supress warninig -Wunused-variable
        std::cout << std::endl;
       
    }

    template<typename... Args>
    void print_tuple(const std::tuple<Args...>& tup)
    {
        // just for log.
        // if you got an error message: incomplete type, because instantiating template function 'tup' variable is not known at compile - so the const expresion like
        // std::tuple_size<decltype(tup)>::value can't be evalueted at that time.
        //
        // two ways of generating index sequence.
        //typedef typename details::make_indexes2<sizeof... (Args)>::type sequence_type;  
        typedef typename details::make_indexes<Args...>::type sequence_type;  
        print_impl2(tup, sequence_type() );
    }

} // namespace tuple11


#endif
