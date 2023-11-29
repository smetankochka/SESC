#include <iostream>
#include <vector>

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int n, m, a, b, c;
    std::cin >> n >> m;
    std::vector<std::vector<Edge>> graph(n);
    for (int i = 0; i < M; ++i) {
        std::cin >> a >> b >> c;
        graph[a - 1].push_back({b - 1, c});
        graph[b - 1].push_back({b - 1, c});
    }
    int minWeight = primMST(graph);
    std::cout << minWeight << std::endl;
    return 0;
}