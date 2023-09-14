#include "graphObject.h"

using namespace std;
using namespace graphObject;

// Driver code
int main() {
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 2);
    g.addEdge(3, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 2);

    g.displayAdjacency();

    cout << endl;

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << endl;

    cout << "Following is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);

    cout << endl;

    cout << "Following is Depth First Traversal (recursive version)"
         << "(starting from vertex 2) \n";

    g.DFSR(2);

    cout << endl;

    cout << "Printing transposed graph, using external helper function" << endl;

    auto gT = transposeGraph(g);
    gT.displayAdjacency();

    cout << endl;

    cout << "Printing transposed graph, using internal transpose function" << endl;

    g.transpose();

    g.displayAdjacency();

    cout << endl;

    cout << "Printing double-transposed graph, using internal transpose function" << endl;

    g.transpose();

    g.displayAdjacency();

    return 0;
}