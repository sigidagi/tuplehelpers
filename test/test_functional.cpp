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
#include <numeric>

#include "functional.hpp"
#include "print.hpp"

// --- Student type containing name, id and grade ----
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
    students.push_back( std::make_tuple("Pen", 5, 7.8f) );
    
    // find studend with a best grade.
    auto it = std::max_element(students.begin(), students.end(), tuple11::less<STUDENT_GRADE, Student>()); 
    std::cout << "Student with best grade: ";
    tuple11::print(*it);    
   
    // extract 'comlumn' grades and save into vector. 
    auto grades = tuple11::extract<STUDENT_GRADE>(students);
    // 
    float sum = std::accumulate(grades.begin(), grades.end(), 0.0f, std::plus<float>());

    // average of students grades.
    std::cout << "Average grade: " << sum/grades.size() << std::endl;



    return 0;
}
