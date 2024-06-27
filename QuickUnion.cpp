#include "QuickUnion.hpp"
#include <iostream>

using namespace std;

QuickUnion::QuickUnion(int n){
    sz.resize(n);
    uf.resize(n);
    for (size_t i = 0; i < n; i++){
        uf[i] = i;
        sz[i] = 1;
    } 
}

int QuickUnion::find(int val){
    while(uf[val] != val) val = uf[val];
    return val;
}

bool QuickUnion::connected(int el1, int el2){
    int root1 = find(el1);
    int root2 = find(el2);

    return root1 == root2;
}

void QuickUnion::printUF(){
    for (int el : uf){
        cout << el << " | ";
    }
    cout << endl;
}

void QuickUnion::printSZ(){
    for (int el : sz){
        cout << el << " | ";
    }
    cout << endl;
}

void QuickUnion::merge(int s1, int s2){
    int root_s1 = find(s1);
    int root_s2 = find(s2);

    if (root_s1 == root_s2) return;  // Già nello stesso insieme
    if (sz[root_s1] < sz[root_s2]){
        uf[root_s1] = root_s2;
        sz[root_s2] += sz[root_s1];
    }else{
        uf[root_s2] = root_s1;
        sz[root_s1] += sz[root_s2];
    }
}