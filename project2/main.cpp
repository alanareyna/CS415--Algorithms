#include <iostream>
#include <list>
#include <fstream>
#include "graph.hpp"
using namespace std;

int main() {
    string filename;
    list<int> dataFromInputFile;
    cout << "Enter the file to read data:" << endl;
    cin >> filename;

    ifstream inputFileStreamObject;

    inputFileStreamObject.open(filename);

    if(!inputFileStreamObject.is_open()){
        cout << "Make sure that " << filename << " exists and is readable. Terminating..." << endl;
    }
    else {
        cout << "Reading file..." << endl;
    }

    int temp;
    inputFileStreamObject >> temp;

    while (!inputFileStreamObject.eof()){
        dataFromInputFile.insert(temp);
        inputFileStreamObject >> temp;
    }
    inputFileStreamObject.close();
}