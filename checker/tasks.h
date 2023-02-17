#pragma once 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <stack>
#include <string>


namespace task1 {
    void accessible(std::vector<std::vector<int>> &transitions,
                     std::vector<int> &sources, int n, int m, int s);
    
    void dfs(int node, std::vector<std::vector<int>> &transitions, 
        std::vector<bool> &visited);
}


namespace task2 {
    void synchronize(std::vector<std::vector<int>> &transitions,
                 std::vector<int> &sources, int n, int m, int s);

    void find_sequence(std::string state,
                  std::vector<std::vector<int>> &transitions,
                  std::unordered_set<std::string> &visited,
                  std::string &sequence,
                  bool &good_transition);
}
