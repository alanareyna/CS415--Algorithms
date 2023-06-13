//
// Created by Alana Reyna on 3/22/22.
//

#ifndef PROJECT2_GRAPH_HPP
#define PROJECT2_GRAPH_HPP
#include <iostream>
#include <list>
using namespace std;

class Graph {
public:
  //Constructor                                                                                                                                                                                           
    Graph();
    //Parameterized constructor                                                                                                                                                                             
    Graph(string InputFileName);
    void AddEdge(Data&, Data&);
    void AddVertexNode(Data);
  void TopologicalSort();
  int MaxRental();
  vector <Data *> TopologicalSort(vector<Data *> clients);
  void FindGraphEdgeConnections();
    void PrintGraph();

private:
  int NumberOfEdges;
    int NumberOfVertexNodes;
    vector <Data> AdjacencyList;
    //Do we need these?                                                                                                                                                                                     
    GraphNode* StartNode;
    GraphNode* EndNode;
};


#endif //PROJECT2_GRAPH_HPP
