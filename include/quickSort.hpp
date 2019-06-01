#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>
#include <tuple>

using namespace std;

class QuickSort{
public:

    int findPivot(int lef, int rig);
    tuple<int, int> partition(int lef, int rig, vector<int>* elements);
    void sort(vector<int>* elements);

    void classicQuickSort(int lef, int rig, vector<int>* elements);
};

#endif