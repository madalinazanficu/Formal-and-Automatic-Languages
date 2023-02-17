### Zanficu Madalina 333CA - TEMA LFA

#### task1.cpp: Accessible
Pentru a determina nodurile accesibile, am pornit mai multe parcurgeri     |
DFS din fiecare nod sursa. Astfel nodurile care ajung sa fie vizitate      |
din surse sunt stari accesibile.                                           |
                                                                           |
#### task2.cpp: Synchronize                                                |
Pentru acest task, am urmarit algoritmul 2 si teoremele 1.14 si 1.15       |
din Bibliografie: https://www.math.uni.wroc.pl/~kisiel/auto/Homing.pdf     |
In functia synchronize declar multimea initiala de stari ce contine        |
toate starile de start. Le retin intr-un set pentru a nu avea duplicate.   |
Algoritmul presupune alegerea a 2 stari din acest pool de stari, si        |
gasirea unei secvente de tranzitii care sa duca s1 si t1 in aceeasi stare. |
                                                                           |
Pentru gasirea secventei, in functia find_sequence aplic DFS pe            |      
starea state. State este un string ce contine s1 si t1 in codificare.      |
Astfel algoritmul DFS se aplica atat pe s1 si t1 simultan.                 |
Conditia de oprire este cand s1 si t1 se vor ajunge in aceeasi stare,      |
astfel consider secventa de tranzitii o secventa valida (good_transition). |
Secventa este retinuta in sequence, iar in cazul in care secventa nu       |
este una valida, la intoarcerea din recusrivitate, se vor sterge tranzitii |
de la finalul lui sequence.                                                |
                                                                           |
Dupa gasirea unei secvente valide de tranzitii, toate nodurile ramase      |
in multimea initiala vor parcurge secventa de tranzitii, iar set-ul se     |
va updata.                                                                 |
**Algoritmul se continua pana cand am ramas doar cu o singura stare.**     |
                                                                           |
#### bonus.cpp: Bonus                                                      |
Am transformat inputul primit in inputul pentru problema synchronize.      |
Astfel numarul total de stari este ecgivalent cu l * c, iar numarul        |
total de roboti simbolizeaza starile sursa.                                |
Pentru decodificare tranzitiilor am considerat astfel:                     |
Fiecare celula inseamna de fapt o stare, iar starea fiecarui bit           |
semnifica tranzitiile starii.                                              |
De exemplu daca matricea de celule ar arata astfel:                        |
Starea s4 care are tranzitii spre toate starile vecine (s1, 23, s5, s7).   |

s0   s1   s2
s3  0000  s5
s6   s7   s8











