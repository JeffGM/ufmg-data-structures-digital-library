#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include <vector>
#include <tuple>

using namespace std;

class QuickSort{
private:
    int pivotType;
    int quickSortType;
    int insertionPercentage;
    
public:
    void setQuickSortType(string quickSortType);

    int findPivot(int lef, int rig, vector<int>* elements);
    void sort(vector<int>* elements);

    tuple<int, int> partition(int lef, int rig, vector<int>* elements);

    void classicQuickSort(int lef, int rig, vector<int>* elements);
};

#endif