/* Creators: Alana Reyna and Cody Grimes
 * Project 1: Task 2
 */

#include "Task2.hpp"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// initialize default constructer with constant variable a
Task2::Task2(int x) : a(x){
}

// decrease by one algorithm:
int Task2::decreaseByOne(const int a, int n){
    if (n == 0){
        count++;
        return 1;
    }
    else if (n > 0){
        count++;
        // recursive call decreasing n by one and saving it to result variable
        decreaseByOneResult = a * decreaseByOne(a,n-1);
    }
    // add counter to number of operations vector
    DBO_num_op.push_back(count);
    count = 0;
    return decreaseByOneResult;
}

// decrease by constant algorithm:
int Task2::decreaseByConst(const int a, int n){
    if (n == 0){
        return 1;
    }
        // if n is an even number
    else if (n % 2 == 0){
        count++;
        // take the power of 2 of recursive call with using n/2 and store it in result variable
        decreaseByConstResult = pow(decreaseByConst(a, n/2), 2);
    }
        // if n is odd
    else {
        count++;
        // take the power of 2 to the recursive call using n-1/2, multiply by a, and store it in result variable
        decreaseByConstResult = a * pow(decreaseByConst(a,(n-1)/2), 2);
    }
    DBC_num_op.push_back(count);
    count = 0;
    return decreaseByConstResult;
}

// divide and conquer algorithm:
int Task2::divideAndConquer(const int a, int n) {
    if (n == 0){
        count++;
        return 1;
    }
        // if n is even
    else if (n % 2 == 0) {
        count++;
        // multiply two recursive calls and store it in result variable
        divideAndConquerResult = divideAndConquer(a, n/2) * divideAndConquer(a, n/2);
    }
        // if n is odd
    else {
        count++;
        // two recursive calls with n-1/2, multiply those and a, and store in result variable
        divideAndConquerResult = a * divideAndConquer(a, (n-1)/2) * divideAndConquer(a, (n-1)/2);
    }
    DAC_num_op.push_back(count);
    count = 0;
    return divideAndConquerResult;
}