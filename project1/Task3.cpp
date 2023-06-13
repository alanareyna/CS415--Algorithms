//
// Created by Alana Reyna on 2/21/22.
//
#include "Task3.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

//Default constructor
Task3::Task3()
{
    DataFromInputFile = new vector<int>();
    int NumberOfOperationsForSelectionSort = 0;
    int NumberOfOperationsForInsertionSort = 0;
}

//PARAMETERIZED CONSTRUCTOR NEEDS TO READ IN INPUT DATA FROM FILE
//AND STORE IN A VECTOR
Task3::Task3(string nameOfInputFile)
{
    //Open input file and store data into private vector
    //This private vector will be used by SelectionSort and InsertionSort functions

    //initialize our private class vector
    DataFromInputFile = new vector<int>();

//initialize private variables (zero because we have not done any operations yet to increment these private "counters")
    int NumberOfOperationsForSelectionSort = 0;
    int NumberOfOperationsForInsertionSort = 0;

    //Creating an input file stream object called "inputFileStreamObject"
    ifstream inputFileStreamObject;

    inputFileStreamObject.open(nameOfInputFile, std::ios::in);

    //Throw an error back to the user if we are unable to open the file
    if( ! inputFileStreamObject.is_open())
    {

        std::cout << "Make sure that " << nameOfInputFile << " exists and is readable. Terminating.";
        exit(2);
    }
    else
    {
        cout << "We are able to read the file. Reading..." << endl;
    }

    //Now that we are able to read the file, fill the vector
    while (!inputFileStreamObject.eof())
    {
        inputFileStreamObject >> DataFromInputFile.pushback();
    }

}

Task3::setterForNumberOfOperationsForSelectionSort(int SetNumberTo)
{
    NumberOfOperationsForSelectionSort = SetNumberTo;
}
int Task3::getterForNumberOfOperationsForSelectionSort()
{
    return NumberOfOperationsForSelectionSort;
}

Task3::setterForNumberOfOperationsForInsertionSort(int setNumberTo)
{
    NumberOfOperationsForInsertionSort = setNumberTo;
}
int Task3::getterForNumberOfOperationsForInsertionSort()
{
    return NumberOfOperationsForInsertionSort;
}

//Using selection sort we move through our vector to sort and keep track of the smallest value (our minimum).
Task3::SelectionSort(vector<int> VectorToSort)
{
    int MinimumValueInVector;
    for (int i = 0; i<VectorToSort.size(); i++)
    {
        //Find the minumum element in the unsorted array
        IndexOfMinimumValueInVector = i;
        for (j = i+1; j<VectorToSort.size();j++)
        {
            if (VectorToSort.at(j)<MinimumValueInVector)
            {
                MinimumValueInVector = VectorToSort.at(j);
                setterForNumberOfOperationsForSelectionSort(getterForNumberOfOperationsForSelectinSort() + 1);
            }
            swap(VectorToSort.at(IndexOfMinimumValueInVector),VectorToSort.at(i))
            setterForNumberOfOperationsForSelectionSort(getterForNumberOfOperationsForSelectinSort() + 1);
        }
    }
    return VectorToShort;
}

//Using insertion sort we will sort as we insert elements into the correct
//positions as we walk through the array
Task3::InsertionSort(vector<int> VectorToSort)
{
    //Move through array
    for (int i = 0; i < VectorToSort.size(); i++)
    {
        //Let j be the iteration we are at, equal with i in our for loop
        int j = i;
        setterForNumberOfOperationsForInsertionSort(getterForNumberOfOperationsForInsertionSort() + 1);
        //starting from where "i" is at, decrement j once to walk back to see if the element behind us is indeed greater than the value we are at (if it is, we will swap)
        while (j > 0 && VectorToSort.at(j-1) > VectorToSort.at(j))
        {
            //If the element "immediately behind us" is indeed greater than            the element we're at, swap the two elements
            swap(VectorToSort.at(j-1),VectorToSort.at(j))
            setterForNumberOfOperationsForInsertionSort(getterForNumberOfOperationsForInsertionSort() + 1);
            //Decrement j to keep checking elements behind us
            j--;
        }
    }
}