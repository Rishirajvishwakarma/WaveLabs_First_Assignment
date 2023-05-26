
#include <iostream>
#include <vector>

int path_root(std::vector<int>& systems, int i) {
    if (systems[i] != i)
        systems[i] = path_root(systems, systems[i]);
    return systems[i];
}

void path_node(std::vector<int>& systems, std::vector<int>& rank, int i, int j) {
    int systemsI = path_root(systems, i);
    int systemsJ = path_root(systems, j);

    if (systemsI == systemsJ)
        return;

    if (rank[systemsI] < rank[systemsJ])
        systems[systemsI] = systemsJ;
    else if (rank[systemsI] > rank[systemsJ])
        systems[systemsJ] = systemsI;
    else {
        systems[systemsJ] = systemsI;
        rank[systemsI]++;
    }
}

int check_connection(int n, std::vector<std::vector<int>>& connections) {
    if (connections.size() < n - 1)
        return -1;

    std::vector<int> systems(n);
    std::vector<int> rank(n, 0);
    int components = n;

    for (int i = 0; i < n; i++)
        systems[i] = i;

    for (const auto& connection : connections) {
        int nodeA = connection[0];
        int nodeB = connection[1];

        if (path_root(systems, nodeA) != path_root(systems, nodeB)) {
            path_node(systems, rank, nodeA, nodeB);
            components--;
        }
    }

    return components - 1;
}

int main() {
    int n = 4;
    std::vector<std::vector<int>> connections{{0, 1}, {0, 2}, {1, 2}};

    int minConnections = check_connection(n, connections);
    std::cout << "Minimum number of connections needed: " << minConnections << std::endl;

    return 0;
}
