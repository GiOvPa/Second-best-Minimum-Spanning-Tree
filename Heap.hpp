#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>

using namespace std;

class Heap{
private:
    vector<pair<int, pair<int, int>>> heap;
    
    void heapifyUp(int ind);
    void heapifyDown(int ind);

public:
    Heap() {};
    ~Heap() {};
    int parent(int i);
    int right_son(int i);
    int left_son(int i);
    void insert(pair<int, pair<int, int>> val);
    pair<int, pair<int, int>> getMin();
    pair<int, pair<int, int>> extractMin();
    bool isEmpty();
    void printHeap();
};

#endif