#include "dijkstras.h"

int main () {
    Graph G;
    file_to_graph("src/medium.txt", G);
    // int destination = 0;
    vector<int> previous;
    vector<int> shortestPath = dijkstra_shortest_path(G, 0, previous);
    
    for (int i = 0; i < G.numVertices; i++) {
        vector<int> path = extract_shortest_path(shortestPath, previous, i);
        print_path(path, shortestPath[i]);
    }
}