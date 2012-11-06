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

using std::placeholders::_1;
using std::placeholders::_2;

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
    students.push_back( std::make_tuple("Jon", 1, 8.4f) );
    students.push_back( std::make_tuple("Ben", 2, 9.6f) );
    students.push_back( std::make_tuple("Dick", 3, 7.3f) );
    students.push_back( std::make_tuple("Sen", 4, 8.2f) );
    
    Student stud2 = std::make_tuple("Tita", 8, 5.6f); 

    auto it = std::max_element(students.begin(), students.end(), tuple11::compare<Student, STUDENT_GRADE>()); 
    std::cout << "Student with best grade: ";
    tuple11::print(*it);    
   
    std::vector<float> sum(students.size());
    std::transform(students.begin(), students.end(), sum.begin(), std::bind(tuple11::plus<Student, STUDENT_GRADE>(), _1, stud2));
    //std::transform(students.begin(), students.end(), sum.begin(), [](const Student& first){ return std::get<STUDENT_GRADE>(first); } );
    

    std::cout << "Student average: " << sum[0] << std::endl; 
    

    return 0;
}
