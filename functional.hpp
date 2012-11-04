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

    template<typename Tuple, std::size_t N>
    class compare : public details::tuple_action<Tuple, N, std::less<typename std::tuple_element<N, Tuple>::type>> {};
   
    
} // namespace code11

#endif
