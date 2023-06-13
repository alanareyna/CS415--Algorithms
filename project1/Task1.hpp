/* Creators: Alana Reyna and Cody Grimes
 * Project 1: Task 1a and 1b
 */

#ifndef PROJECT1_TASK1_HPP
#define PROJECT1_TASK1_HPP
#include <iostream>
#include <vector>


class Task1
{
public:
    //default constructor
    Task1();
    int RecursiveFibionacciSequence(int NthLevel);
    vector <int> IterativeFibionacciSequence(int NthLevel);
    int GCDusingEuclidsAlgorithm(int FirstFibionacciNumber, int SecondFibionacciNumber, int &ModuloDivisionsCounter);
    void setCounter(int ValueToSetTo);
    int getCounter();


private:
    int CounterForNumberOfBasicOperations;
};


#endif //PROJECT1_TASK1_HPP
