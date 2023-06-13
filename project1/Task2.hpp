/* Creators: Alana Reyna and Cody Grimes
 * Project 1: Task 2
 */

#ifndef PROJECT1_TASK2_HPP
#define PROJECT1_TASK2_HPP
#include <iostream>
#include <vector>

class Task2 {
public:
    //default constructor
    Task2(int x);

    // decrease by one function
    int decreaseByOne(const int, int);

    // decrease by constant function
    int decreaseByConst(const int, int);

    // divide and conquer function
    int divideAndConquer(const int, int);

private:
    // constant variable for our input value
    const int a;

    int count;

    // vector to store the number of basic operations performed for decrease by one
    vector <int> DBO_num_op;

    // int variable to store decrease by one result
    int decreaseByOneResult;

    // vector to store the number of basic operations performed for decrease by constant
    vector <int> DBC_num_op;

    // int variable to store decrease by constant result
    int decreaseByConstResult;

    // vector to store the number of basic operations performed for divide and conquer
    vector <int> DAC_num_op;

    // int variable to store divide and conquer result
    int divideAndConquerResult;
};


#endif //PROJECT1_TASK2_HPP
