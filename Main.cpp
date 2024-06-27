#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.hpp"
#include "Graph.cpp"

using namespace std;

int main() {
    ifstream inputFile("input.txt"); // Apriamo il file in modalità di lettura

    if (!inputFile) { // Verifichiamo se l'apertura del file è riuscita
        cerr << "Impossibile aprire il file!" << endl;
        return 1;
    }

    int numGraphs;
    inputFile >> numGraphs; // Leggiamo il numero di grafi

    for (int i = 0; i < numGraphs; ++i) {
        int V, E;
        inputFile >> V >> E; // Leggiamo il numero di nodi e archi per il grafo corrente
        Graph g(V);
        cout << "Caso #" << i+1 << ": ";

        // Leggiamo gli archi
        for (int j = 0; j < E; ++j) {
            int source, destination, weight;
            inputFile >> source >> destination >> weight;
            g.addEdge(source, destination, weight);
        }
        g.SMST();
    }

    inputFile.close(); // Chiudiamo il file dopo aver finito
    
    return 0;
}
