#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>
#include <tuple>
#include <stack>
#include <chrono>
#include "insertionSort.hpp"

using namespace std;

int findMedian(vector<int>* elements);

class QuickSort{
private:
    int pivotType;
    int quickSortType;
    int comparisonCounter;
    int movimentationCounter;
    int insertionPercentage;

    vector<int>* elements;
    chrono::duration<double, std::micro> elapsed_time;
public:
    void setQuickSortType(string quickSortType);

    int findPivot(int lef, int rig);
    void setVector(vector<int>* Elements);

    chrono::duration<double, std::micro> getElapsedTime();
    int getComparisonCounter();
    int getMovimentationCounter();

    void sort();
    tuple<int, int> partition(int lef, int rig, vector<int>* elements);

    void classicQuickSort(int lef, int rig);
    void insertionQuickSort(int lef, int rig);
    void iterativeQuickSort(int lef, int rig);
};
#endif