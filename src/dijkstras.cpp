#include "dijkstras.h"
#include <queue>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;
    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    previous.resize(n, -1);
    
    priority_queue<pair<int, int>> minHeap;
    minHeap.push({source, 0});

    distances[source] = 0;
    
    while (!minHeap.empty()) {
        int u = minHeap.top().first;
        minHeap.pop();

        if (visited[u]) continue;

        visited[u] = true;
        for (Edge edge : G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if (!visited[v] && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination) {
    vector<int> shortestPath;
    for (int vertex = destination; vertex != -1; vertex = previous[vertex]) {
        shortestPath.push_back(vertex);
    }
    reverse(shortestPath.begin(), shortestPath.end());
    return shortestPath;
}

void print_path(const vector<int>& v, int total) {
    for (int vertex : v) {
        cout << vertex << " ";
    }
    cout << "\nTotal cost is " << total << "\n";
}