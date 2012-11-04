/*
 * =====================================================================================
 *
 *       Filename:  test_functional.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/03/2012 01:10:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sigitas Dagilis (), sigidagi@gmail.com
 *
 * =====================================================================================
 */
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "functional.hpp"
#include "print.hpp"

using tuple11::compare;

// Student type which contain name, id and average grade.
// CSV file or database can contain such collection of students
// Loaded and parsed data can be hold in vector container.
//  
// Task 
//
using Student = std::tuple<std::string, int, float>;
enum StudentIndex 
{
    STUDENT_NAME,
    STUDENT_ID,
    STUDENT_GRADE
};


int main()
{
    std::vector<Student> students;
    students.push_back( std::make_tuple("Jon", 1, 8.4) );
    students.push_back( std::make_tuple("Ben", 2, 9.6) );
    students.push_back( std::make_tuple("Dick", 3, 7.3) );
    students.push_back( std::make_tuple("Sen", 4, 8.2) );

    auto it = std::max_element(students.begin(), students.end(), compare<Student, STUDENT_GRADE>()); 
    tuple11::print(*it);    
    
    

    return 0;
}
