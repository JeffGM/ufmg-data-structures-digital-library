#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
using namespace std;

class InsertionSort{
private:
    vector<int>* elements;
public:
    void setVector(vector<int>* Elements);
    void sort(int lef, int rig);
};

#endif INSERTION_SORT_H
