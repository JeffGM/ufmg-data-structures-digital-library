#include "quickSort.hpp"
using namespace std;

//fixme: Add support to other types of pivots
int QuickSort::findPivot(int lef, int rig){
    return (lef + rig)/2;
}

tuple<int, int> QuickSort::partition(int lef, int rig, vector<int>* elements) {
        int pivotIndex = findPivot(lef, rig);
    int pivot = elements->at(pivotIndex);
    while(lef <= rig){
        while(elements->at(lef) < pivot) lef++;
        while(elements->at(rig) > pivot) rig--;
        
        if(lef <= rig){
            iter_swap(elements->begin() + lef, elements->begin() + rig);
            lef++;
            rig--;
        }


    }
    return make_tuple(lef, rig);
}
//fixme: insert new types of quicksort
void QuickSort::sort(vector<int>* elements){
    classicQuickSort(0, elements->size() -1, elements);
}

void QuickSort::classicQuickSort(int lef, int rig, vector<int>* elements){
    int relative_lef, relative_rig;
    tie(relative_lef, relative_rig) = partition(lef, rig, elements);

    if(relative_rig < rig){
        classicQuickSort(lef, relative_rig, elements);
        classicQuickSort(relative_lef, rig, elements);
    }
}