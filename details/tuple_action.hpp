/*
 * =====================================================================================
 *
 *       Filename:  tuple_action.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2012 12:39:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */


#ifndef _TUPLE_ACTION_H
#define _TUPLE_ACTION_H

#include <functional>

namespace tuple11 {
    namespace details {
        
        template<typename Tuple, std::size_t N, typename Action>
        class tuple_action : public std::binary_function<Tuple, Tuple, bool>
        {
            public:
                bool operator()(const Tuple& first, const Tuple& second) const {
                    return action_( std::get<N>(first), std::get<N>(second) );
                }
            private:
                Action action_ = Action{};
        };
        

    }// namespace details

} // namespace code11


#endif
