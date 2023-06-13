/* Creators: Alana Reyna and Cody Grimes
 * Project 1: Task 1a and 1b
 *
 */
#include "Task1.hpp"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Task  1a.)
//HOW DO WE COUNT THE RECURSIVE CALLS? COUNTER FOR EACH RECURSIVE CALL?
//Recursive Fibionacci sequence algowrithm
//Returns integer that is the resulting Fibionacci number
//Takes parameter to go to the nth number in the Fibionacci sequence

//DefaultConstructor
Task1::Task1()
{
    //Initialize private variables to zero
    CounterForNumberOfBasicOperations = 0;
}

void Task1::setCounter(int SetToThisValue)
{
    CounterForNumberOfBasicOperations = SetToThisValue;
}
int Task1::getCounter()
{
    return CounterForNumberOfBasicOperations;
}

Task1::int RecursiveFibionacciSequence (int NthNumberInSequence)
{
    //Base case
    if (NthNumberInSequence == 1)
    {
        return 1;
    }
    //Base case
    if (NthNumberInSequence == 0)
    {
        return 0;
    }
////////////////////////////////////////////
//WE NEED A CURSIVE COUNTER TO COUNT THE NUMBER OF ADDITIONS WE DO HERE? WHERE WOULD THAT LINE GO?
////////////////////////////////////////////
    //Where we do our additions

    //Note how we could have returned a tuple here that would've incremented a counter on each call
    //Increment our Task1 class private variable to count the number of times this recursive function does it's basic operation (adding two recursive calls together to get our Fibionocci number)
    NthNumberInSequence = RecursiveFibionacciSequence(NthNumberInSequence-1) + RecursiveFibionacciSequence(NthNumberInSequence-2);
    return NthNumberInSequence;
}




//Tastk 1b.)
//Using an iterative solution for the Fibionacci sequence, store the resulting numbers in the sequence into
//a data structure to use for Euclid's algowrithm. Using Fibiionacci numbers in a Eculid algowrithm will produce the worst case scenario
//for Euclid's algowrithm.
vector<int> Task1::IterativeFibionacciSequence (int NthNumberInSequence)
{

    vector<int> StoredFibionacciNumbers;

    //We know for sure that the first two elements of the Fibionacci sequence     will be 0 and 1, so lets push those back into our vector
    StoredFibionacciNumbers.push_back(0);
    StoredFibionacciNumbers.push_back(1);

    //We need to start at 2 since we manually put in the first two numbers in the Fibionacci sequence into the vector
    for (int i = 2; i<NthNumberInSequence; i++)
    {
        //Add the last sum with the last number we added to get that sum
        StoredFibionacciNumbers.push_back(StoredFibionacciNumbers.at(i-1) + StoredFibionacciNumbers.at(i-2));
    }

    //Return the vector of Fibionacci numbers
    return StoredFibionacciNumbers;
}




int Task1::GCDusingEuclidsAlgorithm(int FirstNumber, int SecondNumber, int &ModuloDivisionsCounter)
{
    int dividend;
    int divisor;

    //We need to figure out what number should be the divisor (the number we are dividing
    //by, tends to be smaller than the dividend) and which should be the dividend (the
    //number we are dividing, tends to be the larger number)
    //Thus lets assign our variables appropriately
    if (FirstNumber >= SecondNumber)
    {
        dividend = FirstNumber;
        divisor = SecondNumber;
    }
        //if our if condition fails then that means we'll need to do the reverse in this
        //else statement
    else
    {
        dividend = SecondNumber;
        divisor = FirstNumber;
    }

    //Formula for Euclid's algowrithm
    while (divisor != 0)
    {
        int remainder = dividend % divisor;
        //increment our counter of ModuloDivisions
        ModuloDivisionsCounter++;
        dividend = divisor;
        divisor = remainder;
    }

    return dividend;
}
