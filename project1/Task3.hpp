//
// Created by Alana Reyna on 2/21/22.
//

#ifndef PROJECT1_TASK3_HPP
#define PROJECT1_TASK3_HPP

#include <string>
#include <vector>

class Task3
{
public:
    //default constructor
    Task3();
    //parameterized constructor
    Task3(string inputFileName);
    vector<int> SelectionSort();
    vector <int> InsertionSort();
    setterForNumberOfOperationsForSelectionSort(int SetNumberTo);
    int getterForNumberOfOperationsForSelectoinSort();
    setterForNumberOfOperationsForInsertionSort(int setNumberTo);
    int getterForNumberOfOperationsForInsertionSort();

private:
    vector <int> DataFromInputFile;
    int NumberOfOperationsForSelectionSort;
    int NumberOfOperationsForInsertionSort;

};


#endif //PROJECT1_TASK3_HPP
