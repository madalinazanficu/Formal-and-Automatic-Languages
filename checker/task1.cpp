#include "tasks.h"

using namespace task1;
using namespace std;

void task1::accessible(std::vector<std::vector<int>> &transitions,
                     std::vector<int> &sources, int n, int m, int s) {

    std::vector<bool> visited(n, false);
    for (long unsigned int i = 0; i < sources.size(); i++) {
        dfs(sources[i], transitions, visited);
        visited[sources[i]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == true) {
            std::cout << i << "\n";
        }
    }
}

void task1::dfs(int node, std::vector<std::vector<int>> &transitions, 
        std::vector<bool> &visited) {

    visited[node] = true;
    for (long unsigned int i = 0; i < transitions[node].size(); i++) {
        int neigh = transitions[node][i];
        if (visited[neigh] == false) {
            dfs(neigh, transitions, visited);
        }
    }
}