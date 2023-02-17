#include "tasks.h"

using namespace task2;
using namespace std;

/*
* Se adauga toate starile de start intr-o multime de stari - states
* Din acest pool de stari se extrag cate 2 stari (s1 si t1) din care
* se va construi o secventa de tranzitii care sa le duca in aceeasi stare
* Dupa executarea find_sequence, se va aplica secventa de tranzitii
* pe toate starile ramase in multimea states.
* Se va repeta pana cand in multimea states ramane o singura stare
*/
void task2::synchronize(std::vector<std::vector<int>> &transitions,
                 std::vector<int> &sources, int n, int m, int s) 
{
    std::set<int> states;
    if (s == 0) {
        for (int i = 0; i < n; i++) {
            states.insert(i);
        }
    } else {
        states.insert(sources.begin(), sources.end());
    }
    

    std::string sequence;
    while (states.size() > 1) {
        int s1 = *states.begin();
        states.erase(s1);
        int t1 = *states.begin();

        // Se cauta o secventa de tranzitii care sa duca s1 si t1 in aceeasi stare
        std::string current_seq;
        string current_state = to_string(s1) + to_string(t1);
        std::unordered_set<string> visited;
        bool good_transition = false;
        find_sequence(current_state, transitions, visited,
                    current_seq, good_transition);


        // Se aplica secventa de tranzitii pe toate starile ramase
        std::set<int> new_states;
        for (std::set<int>::iterator it = states.begin(); it != states.end(); it++) {
            int old_state = *it;
            
            for (char &c : current_seq) {
                int transition = c - '0';
                old_state = transitions[old_state][transition];
            }
            new_states.insert(old_state);
        }

        // Se actualizeaza starile
        states = new_states;
        sequence += current_seq;
    }
    for (char &c : sequence) {
        std::cout << c << "\n";
    }
}

/*
* Se cauta o secventa de tranzitii care sa duca state (s1, t1) in aceeasi stare
* Se aplica algoritmul DFS astfel: 
* Se iau in ordine toate tranzitiile posibile pe s1 si t1
* Daca ambele tranzitii merg in aceeasi stare, se opreste DFS-ul
*/
void task2::find_sequence(std::string state,
                  std::vector<std::vector<int>> &transitions,
                  std::unordered_set<string> &visited,
                  std::string &sequence,
                  bool &good_transition) {
    
    visited.insert(state);
    int s1 = state[0] - '0';
    int t1 = state[1] - '0';

    // Conditia de oprire pentru DFS, secventa de tranzitii poate fi aplicata
    if (s1 == t1) {
        good_transition = true;
        return;
    }        

    // Se face aceeasi tranzitie pe s1 si t1
    for (long unsigned int i = 0; i < transitions[s1].size(); i++) {
        int s2 = transitions[s1][i];
        int t2 = transitions[t1][i];
        if (s2 > t2) {
            std::swap(s2, t2);
        }

        // Se tranziteaza in noua stare s2 pentru s1 si t2 pentru t1
        std::string new_state = to_string(s2) + to_string(t2);
        if (visited.find(new_state) == visited.end()) {

            // Se adauga tranzitia in secventa
            sequence += to_string(i);

            // DFS in noile stari
            find_sequence(new_state, transitions, visited, sequence, good_transition);

            // Nu s-a gasit o tranzitie buna, se scoate din secventa
            if (good_transition == false) {
                sequence.pop_back();
            }
        }
    }
}