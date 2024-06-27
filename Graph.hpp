#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>
#include <list>

using namespace std;

struct Node
{
    int data;
    typedef pair<int, Node*> ad;
    list<ad>* lis;

    Node(int data) : data{ data }, lis{ new list<ad> } {}
};

class Graph {
private:
    int V;
    map<int, Node*> adjList;

public:
    Graph(int N) : V{ N } { populateGraph(N); }
    ~Graph() {};
    void populateGraph(int N);
    void addEdge(int source, int dest, int w);
    pair<int, Graph> Kruskal();
    Graph copyGraph();
    void copyEdge(int source, int dest, int w);
    void printGraph();
    void removeEdge(int source, int dest, int w);
    void SMST();
    map<int, Node*> getAdjList() { return adjList; };
};
#endif