#include "Heap.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

void Heap::heapifyUp(int ind){
    while (ind > 0 && heap[parent(ind)].first > heap[ind].first){
        swap(heap[ind], heap[parent(ind)]);
        ind = parent(ind);
    }
}

void Heap::heapifyDown(int ind){
    int small = ind;
    int left = left_son(ind);
    int right = right_son(ind);

    if (left < heap.size() && heap[left].first < heap[small].first) small = left;
    if (right < heap.size() && heap[right].first < heap[small].first) small = right;
    if (small != ind) {
        swap(heap[ind], heap[small]);
        heapifyDown(small);
    }
}

int Heap::parent(int i){
    return (i-1)/2;
}

int Heap::left_son(int i) {
    return 2 * i + 1;
}


int Heap::right_son(int i) {
    return 2 * i + 2;
}

void Heap::insert(pair<int, pair<int, int>> val) {
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}

pair<int, pair<int, int>> Heap::getMin() {
    if (heap.empty()) throw out_of_range("Heap is empty");
        return heap[0];
    }

pair<int, pair<int, int>> Heap::extractMin() {
    if (heap.empty()) throw out_of_range("Heap is empty");
    pair<int, pair<int, int>> min = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return min;
}

void Heap::printHeap(){
    if (heap.empty()) {
        cout << "Heap vuota" << endl;
        return;
    }

    for (auto item : heap){
        cout << "(" << item.first << ", (" << item.second.first << ", " << item.second.second << ")) ";
    }
    cout << endl;
}

bool Heap::isEmpty(){
    return heap.empty();
}