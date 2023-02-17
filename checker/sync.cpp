#include "sync.h"

void read_input(std::vector<std::vector<int>> &transitions, 
          std::vector<int> &sources, int &n, int &m, int &s) {

    std::cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        std::vector<int> line;
        for (int j = 0; j < m; j++) {
            int x;
            std::cin >> x;
            line.push_back(x);
        }
        transitions.push_back(line);
    }
    
    for (int i = 0; i < s; i++) {
        int x;
        std::cin >> x;
        sources.push_back(x);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        std::cout << "Add task parameter" << endl;
        return 0;
    }
    std::string task = argv[1];
    int n, m, s;
    std::vector<std::vector<int>> transitions;
    std::vector<int> sources;
    read_input(transitions, sources, n, m, s);
    if (task == "accessible") {
        task1::accessible(transitions, sources, n, m, s);
    } else if (task == "synchronize") {
        task2::synchronize(transitions, sources, n, m, s);
    }
    return 0;
}