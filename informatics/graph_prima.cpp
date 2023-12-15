#include <iostream>
#include <vector>

const int INF = 1e9;

struct Edge {
    int to;
    int weight;
};

int primMST(const std::vector<std::vector<Edge>> &graph) {
    int n = graph.size();
    std::vector<bool> inMST(n, false);
    std::vector<int> minWeight(n, INF);
    int totalWeight = 0;
    minWeight[0] = 0;
    for (int i = 0; i < n; ++i) {
        int minVertex = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (minVertex == -1 || minWeight[j] < minWeight[minVertex])) {
                minVertex = j;
            }
        }
        inMST[minVertex] = true;
        totalWeight += minWeight[minVertex];
        for (const Edge &e: graph[minVertex]) {
            int v = e.to;
            int weight = e.weight;
            if (!inMST[v] && weight < minWeight[v]) {
                minWeight[v] = weight;
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m, a, b, c;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({b - 1, c});
    }
    int minWeight = primMST(graph);
    std::cout << minWeight << "\n";
    return 0;
}
//WRONG!!!!!!