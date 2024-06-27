#ifndef QUICKUNION_HPP
#define QUICKUNION_HPP

#include <vector>

class QuickUnion {
private:
    std::vector<int> uf;
    std::vector<int> sz;

public:
    QuickUnion(int n);
    ~QuickUnion()    {};
	void merge(int s1, int s2);
	int find(int val);
    bool connected(int el1, int el2);
    void printUF();
    void printSZ();
};

#endif