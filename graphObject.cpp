//
// Created by tianj on 9/14/2023.
//

#include "graphObject.h"

namespace graphObject {
    Graph::Graph(int V) {
        this->V = V;
        adj.resize(V);
        initializeVisited();
    }

    int Graph::getV() const {
        return V;
    }

    const vector<list<int>>& Graph::getAdj() const {
        return adj;
    }

    const map<int, bool>& Graph::getVisited() const {
        return visited;
    }

    const list<int>& Graph::getAdjAt(int v) const {
        if (v >= V) {
            cout << "Invalid vertex" << endl;
            exit(-1);
        }
        return adj[v];
    }

    void Graph::addEdge(int v, int w) {
        if (v >= V || w >= V) {
            cout << "Invalid edge" << endl;
            return;
        }
        // Add w to v’s list.
        adj[v].push_back(w);
    }

    void Graph::transpose() {
        Graph gT = transposeGraph(*this);
        *this = gT;
    }

    void Graph::displayAdjacency() {
        int rowIndex = 0;

        for (auto& i : adj) {
            cout << "Row " << rowIndex << " --> ";
            if (i.empty()) {
                cout << "empty";
            } else {
                for (auto& j : i) {
                    cout << j << " ";
                }
            }
            cout << endl;
            rowIndex++;
        }
    }

    inline void Graph::visit(int v) {
        visited[v] = true;
    }

    inline void Graph::initializeVisited() {
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
    }

    void Graph::BFSIterative(int s) {
        // Create a queue for BFS
        list<int> queue;

        // Mark the current node as visited and enqueue it
        queue.push_back(s);

        while (!queue.empty()) {

            // Dequeue a vertex from queue and print it
            s = queue.front();
            queue.pop_front();

            if (!visited[s]) {
                cout << s << " ";
                visit(s);
            }

            // Get all adjacent vertices of the dequeued
            // vertex s.
            // If an adjacent has not been visited,
            // then mark it visited and enqueue it
            for (auto adjacent: adj[s]) {
                if (!visited[adjacent]) {
                    queue.push_back(adjacent);
                }
            }
        }
    }

    void Graph::BFS(int s) {
        initializeVisited();
        BFSIterative(s);
        initializeVisited();
    }

    void Graph::DFSIterative(int s) {
        // Create a stack for DFS
        stack<int> stack;

        // Push the current source node.
        stack.push(s);

        while (!stack.empty()) {
            // Pop a vertex from stack and print it
            s = stack.top();
            stack.pop();

            // Stack may contain same vertex twice. So
            // we need to print the popped item only
            // if it is not visited.
            if (!visited[s]) {
                cout << s << " ";
                visit(s);
            }

            // Get all adjacent vertices of the popped vertex s
            // If an adjacent has not been visited, then push it
            // to the stack.
            for (auto adjacent: adj[s]) {
                if (!visited[adjacent]) {
                    stack.push(adjacent);
                }
            }
        }
    }

    void Graph::DFS(int s) {
        initializeVisited();
        DFSIterative(s);
        initializeVisited();
    }

    void Graph::DFSRecursive(int s) {
        // Mark the current node as visited and
        // print it
        cout << s << " ";
        visit(s);

        // Recur for all the vertices adjacent
        // to this vertex
        // create implicit stack
        for (auto adjacent: adj[s]) {
            if (!visited[adjacent]) {
                DFSRecursive(adjacent);
            }
        }
    }

    void Graph::DFSR(int s) {
        initializeVisited();
        DFSRecursive(s);
        initializeVisited();
    }

    Graph transposeGraph(const Graph& g) {
        Graph gT(g.getV());
        for (int i = 0; i < g.getV(); i++) {
            for (auto j : g.getAdjAt(i)) {
                gT.addEdge(j, i);
            }
        }
        return gT;
    }
} // graphObject