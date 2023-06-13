/* Creators: Alana Reyna and Cody Grimes
 * Project 1
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include "gnuplot-iostream.h"
#include "Task1.hpp"
#include "Task2.hpp"
#include "Task3.hpp"
using namespace std;


int main() {
    // prompt user with the option to use user mode or scatter plot mode
    int mode;
    cout << "Choose the mode you want to enter" << endl;
    cout << "Enter '1' for user testing mode and 2 for Scatter plot mode: " << endl;
    cin >> mode;
    // if mode = 1, then enter user mode, if mode = 2, enter scatter plot mode
    if (mode == 1)
    {
        // TASK 1a:
        int k;
        cout << "Enter value of k for task1: " << endl;
        cin >> k;
        // create new Object of task1
        Task1 Task1_Object;


        //WE NEED TO CAPTURE RUNTIME FOR RECURSIVEFIBIONOCCISEQUENCE HERE GLOBAL VARIABLE? COUNTER PASS BY REFERENCE?

        //Capture the returned Kth number in the Fibinocci Sequence
        //Declaring our capture variable
        int CaptureVariableForRecursiveFibioncciSequence;
        //Calculate the runtime for the recursive Fibinocci Sequence and the kth number in the sequence
        CaptureVariableForRecursiveFibioncciSequence = Task1_Object.RecursiveFibionacciSequence(k);

        // output the result of the resursive fibinocci sequence
        cout << "Recursive Fibinocci Result: " << CaptureVariableForRecursiveFibioncciSequence << endl;



        // output the result of the resursive fibinocci sequence
        cout << "Does this work in showing Recursive Fibinocci Result?: " << Task1_Object.RecursiveFibionacciSequence(k) << endl;





        // TASK 1b:
        //For our iterative fibinocci sequence function, it returns a vector of all fibiniocci numbers up to the Kth value. Let's capture that returned vector
        vector<int> CaptureIterativeFibinocciSequenceVector;
        CaptureIterativeFibinocciSequenceVector = Task1_Object.IterativeFibionacciSequence(k);



        //We will also need a vector to hold our results from each EuclidsAlgoritm call
        vector<int>GreatestCommonDenominatorResult;
        //And we will need a vector that holds the number of modulo division operations it took to generate those corresponding results
        vector<int>NumberOfModuloOperationsForEachGCD;

        //Now that we have our vector of FibionacciNumbers, we can use it to input into our Euclid's algorithm function in order to compute the worse case time complexity
        //
        for (int i = 0; i < CaptureIterativeFibinocciSequenceVector.size(); i++)
        {
//Declare an int value that will hold our counter. It should be initialized to zero since we haven't done any modulo divions yet (note how we want it to reset back to zero with every for loop iteration)
            int ModuloDivisionCounter = 0;

            //bounds issue here? i+1 going out of scope towards end of for loop?
            GreatestCommonDenominatorResult.push_back(Task1_Object.GCDusingEuclidsAlgorithm(i+1, i, ModuloDivisionCounter));
            NumberOfModuloOperationsForEachGCD.push_back(ModuloDivisionCounter);

        }

        ///////////////////////////////////////////////////////////////////
        // create new vector to store iterative fibinocci sequence
        vector<int> IterFibResult;
        IterFibResult.push_back(IterativeFibionacciSequence(k));

        // create new vector to store result of GCD
        vector<int> GCD_result;
        for (auto it = IterFibResult.begin(); it != IterFibResult.end(); ++it){
            GCD_result.push_back(Task1_Object.GCDusingEuclidsAlgorithm(it + 1, it));
        }
        // output the result of the GCD function
        cout << "GCD result: " << GCD_result;

        // TASK 2:
        // create new Object of task2
        Task2 Task2_Object;
        const int a;
        int n;
        cout << "Value of 'a' for Task2: " << endl;
        cin >> a;
        cout << "Value of 'n' for Task2: " << endl;
        cin >> n;

        // Decrease by one
        cout << "Result of Decrease by One: " << Task2_Object.decreaseByOne(a, n) << endl;

        // Decrease by constant
        cout << "Result of Decrease by Constant: " << Task2_Object.decreaseByConst(a, n) << endl;

        // Divide and Conquer
        cout << "Result of Divide and Conquer: " << Task2_Object.divideAndConquer(a, n) << endl;






        // TASK 3:
        Task3 Task3_Object;
        // task 3
        string line;
        string n;

        cout << "Enter a number between 10 - 100 in an increment of 10: " << endl;
        cin >> n;

        //Clever way of opening appropriate file we want with the correct amount of data inputs
        string BestCaseFileToOpen = "data" + n + "_sorted.txt";
        string AverageCaseFileToOpen = "data" + n + ".txt";
        string WorstCaseFileToOpen = "data" + n + "_rSorted.txt";

        //Pass this string to a Task3 object upon creation
        Task3 Task3_ObjectBestCaseScenario(BestCaseFileToOpen);
        Task3 Task3_ObjectAverageCaseScenario(AverageCaseFileToOpen);
        Task3 Task3_ObjectWorstCaseScenario(WorstCaseFileToOpen);

        //Note that selection sort and insertion sort will both need vectors to store
        //their sorted data.
        //We'll need a pair of vectors for each object we have
        //???????Do we actually need to keep the sorted values???????
        vector<int> Task3_ObjectBestCaseScenarioSelectionSort;
        vector<int> Task3_ObjectBestCaseScenarioInsertionSort;

        vector<int> Task3_ObjectAverageCaseScenarioSelectionSort;
        vector<int> Task3_ObjectAverageCaseScenarioInsertionSort;

        vector<int> Task3_ObjectWorstCaseScenarioSelectionSort;
        vector<int> Task3_ObjectWorstCaseScenarioInsertionSort;

        int BestCaseScenarioNumberOfComparisonsSelectionSort;
        int BestCaseScenarioNumberOfComparisonsInsertionSort;
        int AverageCaseScenarioNumberOfComparisonsSelectionSort;
        int AverageCaseScenarioNumberOfComparisonsInsertionSort
        int WorstCaseScenarioNumberOfComparisonsSelectionSort;
        int WorstCaseScenarioNumberOfComparisonsInsertionSort;

        //Run the functions and capture their returned vectors

        //We must also collect their number of comparisons being made in each algowrithm
        Task3_ObjectBestCaseScenarioSelectionSort = Task3_ObjectBestCaseScenario.SelectionSort();
        BestCaseScenarioNumberOfComparisonsSelectionSort = Task3_ObjectBestCaseScenario.getterForNumberOfOperationsForSelectionSort();

        Task3_ObjectBestCaseScenarioInsertionSort = Task3_ObjectBestCaseScenario.InsertionSort();
        BestCaseScenarioNumberOfComparisonsInsertionSort = Task3_ObjectBestCaseScenario.getterForNumberOfOperationsForInsertionSort();

        Task3_ObjectAverageCaseScenarioSelectionSort = Task3_ObjectAverageCaseScenario.SelectionSort();
        AverageCaseScenarioNumberOfComparisonsSelectionSort.getterForNumberOfOperationsForSelectionSort();

        Task3_ObjectAverageCaseScenarioInsertionSort = Task3_ObjectAverageCaseScenario.InsertionSort(); AverageCaseScenarioNumberOfComparisonsInsertionSort.getterForNumberOfOperationsForInsertionSort();

        Task3_ObjectWorstCaseScenarioSelectionSort = Task3_ObjectWorstCaseScenario.SelectionSort(); WorstCaseScenarioNumberOfComparisonsSelectionSort.getterForNumberOfOperationsForSelectionSort();

        Task3_ObjectWorstCaseScenarioInsertionSort = Task3_ObjectWorstCaseScenario.InsertionSort();
        WorstCaseScenarioNumberOfComparisonsInsertionSort = Task3_ObjectWorstCaseScenario.getterForNumberOfOperationsForInsertionSort();



        //Distinct scatter plots need to be made for best-case, average-case, and worst-case scenarios




    }
        // mode 2: scatterplot mode
    else {
        // task 1a

        // task 1b

        // task 2
        // create new plot
        gnuplot task2;
        // a is constant, we set the value of a
        int a = 5;
        // x = value of n
        // y = M(n) - the number of multiplications
        task2("set term postscript eps");
        task2("set output \"task2.eps\" ");
        task2("set xlabel 'n'");
        task2("set ylabel 'Number of operations'");
        task2("plot \'./task2.dat' u 1:2 w p title 'Exponentiation Algorithms'");

        ifstream inputFile;
        inputFile.open("Task2.dat");

        if (!inputFile.is_open()) {
            std::cout << "File unable to open" << std::endl;
            exit(-1);
        }


        /* do we need this?
        int tempInt;
        vector<int> task2_values;
        while (inputFile >> tempInt) {
          task2_values.push_back(tempInt);
          }
        */

    }
    return 0;
}