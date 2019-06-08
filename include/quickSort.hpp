#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>
#include <tuple>
#include <stack>
#include "insertionSort.hpp"

using namespace std;

class QuickSort{
private:
    int pivotType;
    int quickSortType;
    int insertionPercentage;
    vector<int>* elements;
public:
    void setQuickSortType(string quickSortType);

    int findPivot(int lef, int rig);
    void setVector(vector<int>* Elements);
    void sort();

    tuple<int, int> partition(int lef, int rig, vector<int>* elements);

    void classicQuickSort(int lef, int rig);
    void insertionQuickSort(int lef, int rig);
    void iterativeQuickSort(int lef, int rig);
};
#endif