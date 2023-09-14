#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

using namespace std;

namespace graphObject {
    // This class represents a directed graph using
    // adjacency list representation
    class Graph {
    private:
        // No. of vertices
        int V;

        // Pointer to an array containing adjacency lists
        vector<list<int> > adj;

        // Visited vertex map
        map<int, bool> visited;

        // Core function BFS traversal from a given source s
        void BFSIterative(int s);

        // Core function DFS traversal from a given source s
        void DFSIterative(int s);

        // Core function DFS recursive traversal from a given source s
        void DFSRecursive(int s);

        void visit(int v);

        void initializeVisited();

    public:
        // Constructor
        explicit Graph(int V);

        [[nodiscard]] int getV() const;

        [[nodiscard]] const vector<list<int>>& getAdj() const;

        [[nodiscard]] const list<int>& getAdjAt(int v) const;

        [[nodiscard]] const map<int, bool>& getVisited() const;

        // Function to add an edge to graph
        void addEdge(int v, int w);

        void transpose();

        // Function to display adjacency list directly
        void displayAdjacency();

        // Prints BFS traversal from a given source s
        void BFS(int s);

        // Prints DFS traversal from a given source s
        void DFS(int s);

        // Prints DFS traversal from a given source s, recursive version
        void DFSR(int s);
    };

    Graph transposeGraph(const Graph& g);
} // graphObject

#endif //GRAPH_H
