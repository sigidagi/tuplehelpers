/*
 * =====================================================================================
 *
 *       Filename:  make_indexes.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/31/2012 10:10:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#ifndef _MAKE_INDEXES_H
#define _MAKE_INDEXES_H


namespace tuple11 {
    namespace details {
        
        template<int...> struct index_tuple{}; 
        
        // ----- first method ----
        template<int I, typename IndexTuple, typename... Types> 
        struct make_indexes_impl; 

        template<int I, int... Indexes, typename T, typename ... Types> 
        struct make_indexes_impl<I, index_tuple<Indexes...>, T, Types...> 
        { 
            typedef typename make_indexes_impl<I + 1, index_tuple<Indexes..., I>, Types...>::type type; 
        }; 

        template<int I, int... Indexes> 
        struct make_indexes_impl<I, index_tuple<Indexes...> > 
        { 
            typedef index_tuple<Indexes...> type; 
        }; 

        template<typename ... Types> 
        struct make_indexes : make_indexes_impl<0, index_tuple<>, Types...> 
        {};

        
        // ---- another method to generate sequence/indexes from tuple arguments.
        template<int N, int... Indexes>
        struct make_indexes2 : make_indexes2<N-1, N-1, Indexes...> {};
        
        // template specialization - termination condition
        template<int... Indexes>
        struct make_indexes2<0, Indexes...> 
        {
          typedef index_tuple<Indexes...> type;
        };




    } // namspace details
} // namespace tuple11


#endif
