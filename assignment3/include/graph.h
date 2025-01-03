/**
 * @file graph.h
 * @author Luka Karanovic, 665778833, F24N03, CSCI 260, VIU
 * @version 1.1.0
 * @date December 3, 2024
 *
 * Defines a Graph class which holds a vector of Vertex objects and Edge objects (both defined in include/vertex.h).
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef ASSN3_GRAPH_H
#define ASSN3_GRAPH_H

typedef struct Edge {
    double unitCost;    // The unitCost, or weight, of an edge. This manages how efficient an edge is.
    int capacity;       // The communication volume capacity of an edge.
    int load = 0;       // The communication volume load of an edge based on the demands given, always initialized to 0.
} Edge;

class Graph {
    private:
        vector<string> vertices;        // A vector containing all of the vertices of the graph. It is a string vector as no location information is needed, so we just need name.
        vector<vector<Edge>> adjMatrix; // A 2-D vector containing an adjacency matrix with all of the information relating to the edges in the graph.

        /**
        * Helper function that seeks out the lowest unitCost edge adjacent to the current vertex
        * in Dijkstra's algorithm, so that the edge can be traversed and current vertex can be updated.
        */
        int findMin(vector<double>& totalCost, vector<bool>& visited);

    public:

        /**
        * Regular constructor
        */
        Graph(vector<string> V, int size);

        /**
        * Destructor
        */
        ~Graph();

        /**
        * Returns the integer index of the vertex in the 'vertices' vector given a target name.
        */
        int findVertex(string name);

        /**
        * Inserts a new edge with two given vertices, a unit cost, and a volume capacity into the graph.
        */
        void insertEdge(int v1, int v2, double cost, int capacity);

        /**
        * Uses Dijkstra's algorithm to return the shortest unitCost path through a sequence of vertices travelled from source to destination.
        */
        vector<int> findPath(int source, int dest);

        /**
        * Helper function that prints out the adjacency matrix of a graph. Labels each row with the first letter of the vertex.
        */
        void printMatrix();

        /**
        * Updates the load for a given edge in the adjacency matrix.
        */
        void updateLoad(int demand, int v1, int v2);
            
        /**
        * Helps print results of the analysis to 'testing/techAnalysisResult.txt' for connections whose capacity needs to be increased.
        */
        void printResults(std::ostream& stream);

};


#endif