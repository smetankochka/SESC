#include <iostream>
#include <vector>

const int INF = 1e9;

int primMST(const std::vector<std::vector<int>> &graph) {
    int n = graph.size();
    std::vector<bool> used(n);
    std::vector<int> min_e(n, INF), sel_e(n, -1);
    int totalWeight = 0;
    min_e[0] = 0;
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!used[j] && (v == -1 || min_e[j] < min_e[v])) {
                v = j;
            }
        }
        totalWeight += min_e[v];
        used[v] = true;
        for (int to = 0; to < n; ++to) {
            if (graph[v][to] < min_e[to]) {
                min_e[to] = graph[v][to];
                sel_e[to] = v;
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m, a, b, c;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, INF));
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }
    int minWeight = primMST(graph);
    std::cout << minWeight << "\n";
    return 0;
}