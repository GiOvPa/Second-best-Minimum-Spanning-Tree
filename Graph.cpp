#include <iostream>
#include <limits.h>
#include <vector>

#include "Graph.hpp"
#include "QuickUnion.hpp"
#include "QuickUnion.cpp"
#include "Heap.hpp"
#include "Heap.cpp"

using namespace std;

void Graph::populateGraph(int N) {
    for (int i = 1; i <= N; i++) adjList.insert(make_pair(i, new Node(i)));
}

pair<int, Graph> Graph::Kruskal() {
    Heap hp;
    for (auto node : adjList) {
        if (node.second->lis != nullptr) {
            for (auto adj : *(node.second->lis)) {
                hp.insert({ adj.first, { node.first, adj.second->data } });
            }
        }
    }

    QuickUnion qu(V);
    Graph MST(V);

    int cost_MST = 0;
    int numEdges = 0;
    pair<int, pair<int, int>> edge;

    while (numEdges < V - 1 && !hp.isEmpty()){
        edge = hp.extractMin();
        int source = edge.second.first;
        int destination = edge.second.second;

        if (!qu.connected(source - 1, destination - 1)) {
            MST.addEdge(source, destination, edge.first);
            qu.merge(source - 1, destination - 1);
            cost_MST += edge.first;
            numEdges++;
        }
    }

    if (numEdges == V - 1) return {cost_MST, MST};
    else return {-1, MST};
}

void Graph::SMST(){
    pair<int, Graph> MST = Kruskal();
    int mincost = MST.first;
    if (mincost == -1){
        cout << "Nessuna soluzione" << endl;
        return;
        }
    Graph copiedG = copyGraph();

    int minco = INT_MAX;
    for (auto pair : MST.second.adjList){
        if (pair.second->lis != nullptr){
            for (auto adj : *(pair.second->lis)){
                int src = pair.first;
                int dest = adj.second->data;
                int w = adj.first;

                copiedG.removeEdge(src, dest, w);
                int cost = copiedG.Kruskal().first;
                if (cost != -1) minco = min(minco, cost);
                copiedG.addEdge(src, dest, w);
            }
        }
    }

    if (minco == INT_MAX) cout << "Nessun secondo miglior costo" << endl;
    else cout << minco <<endl;
}

Graph Graph::copyGraph(){
    Graph copiedG(V);
    for (auto pair : adjList){
        int node = pair.first;
        Node* newNode = new Node(node);
        copiedG.adjList[node] = newNode; 
        for (auto edge : *(pair.second->lis)){
            int des = edge.second->data;
            int w = edge.first;
            copiedG.copyEdge(node, des, w);
        }
    }
    return copiedG;
}

void Graph::printGraph() {
    for (auto i = adjList.begin(); i != adjList.end(); ++i) {
        cout << i->first << " : ";
        for (auto edge : *i->second->lis) cout << "(" << edge.second->data << ", " << edge.first << ")" << " -> ";
        cout << endl;
    }
}

void Graph::addEdge(int source, int dest, int w) {
    Node* s = adjList[source];
    Node* d = adjList[dest];
    
    s->lis->push_back({w, d});
    d->lis->push_back({w, s});
}

void Graph::copyEdge(int source, int dest, int w){
    Node* s = adjList[source];
    Node* d = adjList[dest];
    
    s->lis->push_back({w, d});
}

void Graph::removeEdge(int source, int dest, int w){
    Node* ad = adjList[source];
    for (auto it = ad->lis->begin(); it != ad->lis->end(); ++it){
        if (it->second->data == dest && it->first == w){
            ad->lis->erase(it);
            break;
        }
    }

    Node* adDest = adjList[dest];;
    for (auto it = adDest->lis->begin(); it != adDest->lis->end(); ++it) {
        if (it->second->data == source && it->first == w) {
            adDest->lis->erase(it);
            break;
        }
    }
}
