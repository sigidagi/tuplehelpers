/*
 * =====================================================================================
 *
 *       Filename:  test_zip.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/10/2012 12:43:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include "print.hpp"
#include "zip.hpp"


int main()
{
    auto tup = std::make_tuple( std::string("quick fox"), 45.0f, '3', 12);
    
    // print test 
    tuple11::print_tuple(tup);    
    

    auto mypairs = tuple11::pairs(tup, make_tuple( std::string("lazy dog"), 12, 2, 'H'));
    std::cout << std::get<0>(mypairs).first << std::endl;
    std::cout << std::get<0>(mypairs).second << std::endl;

    return 0;
}
