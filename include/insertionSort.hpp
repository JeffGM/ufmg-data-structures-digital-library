#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <vector>
using namespace std;

class InsertionSort{
private:
    vector<int>* elements;
    int movimentationCounter = 0;
    int comparisonCounter = 0;
public:
    int getComparisonCounter();
    int getMovimentationCounter();

    void setVector(vector<int>* Elements);
    void sort(int lef, int rig);
};

#endif
