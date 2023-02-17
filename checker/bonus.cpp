#include <iostream>
#include <vector>
#include <bitset>


void bonus(std::vector<std::vector<int>> &transitions,
            int &count_states, int &count_sources, 
            std::vector<int> &sources) {

    int l, c, r;
    std::cin >> l >> c >> r;

    // Numarul de stari este numarul de celule
    count_states = l * c;
    
    // Se creeaza matricea de tranzitii
    for (int i = 0; i < l; i++) {
        std::vector<int> line;
        for (int j = 0; j < c; j++) {
            int x;
            std::cin >> x;

            // Reprezentarea binara a celulei
            int current_state = i * c + j;
            std::string binary = std::bitset<4>(x).to_string();
            
            // EST
            if (binary[3] == '0' && j != c - 1) {
                line.push_back(current_state + 1);
            } else {
                line.push_back(current_state);
            }

            // NORD
            if (binary[2] == '0' && i != 0) {
                line.push_back(current_state - c);
            } else {
                line.push_back(current_state);
            }

            // VEST
            if (binary[1] == '0' && j != 0) {
                line.push_back(current_state - 1);
            } else {
                line.push_back(current_state);
            }

            // SUD
            if (binary[0] == '0' && i != l - 1) {
                line.push_back(current_state + c);
            } else {
                line.push_back(current_state);
            }
        }
        transitions.push_back(line);
    }

    // Robotii sunt starile sursa
    count_sources = r;
    for (int i = 0; i < count_sources; i++) {
        int x, y;
        std::cin >> x >> y;
        sources.push_back(x * c + y);
    }    
}


int main() {

    int count_states, count_sources;
    std::vector<std::vector<int>> transitions;
    std::vector<int> sources;
    bonus(transitions, count_states, count_sources, sources);

    std::cout << count_states << " ";
    std::cout << 4 << " ";
    std::cout << count_sources << std::endl;

    for (long unsigned int i = 0; i < transitions.size(); i++) {
        for (long unsigned int j = 0; j < transitions[i].size(); j++) {
            if (j % 4 == 0 && j != 0) {
                std::cout << std::endl;
            }
            std::cout << transitions[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < count_sources; i++) {
        std::cout << sources[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}