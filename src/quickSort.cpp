#include "quickSort.hpp"
#include <iostream>
using namespace std;

int findMedian(int a, int b, int c){
    int temp;
    
    if(a > b){
        temp = b;
        b = a;
        a = temp;
    }
    if(b > c){
        temp = c;
        c = b;
        b = temp;

        if(a > b){
            temp = b;
            b = a;
            a = temp;
        }
    }

    return b;
}

//fixme: Add support to other types of pivots
int QuickSort::findPivot(int lef, int rig, vector<int>* elements){
    switch(pivotType){
        case 1:
            return (lef + rig)/2;
        case 2:
            if(rig >= 0 && lef < elements->size()){
                int median;
                median  = findMedian(elements->at(lef), elements->at((lef + rig)/2) , elements->at(rig));

                if(elements->at(lef) == median)
                    return lef;
                else if(elements->at((lef + rig)/2) == median)
                    return (lef + rig)/2;
                else
                    return rig;
            }else{
                return 0;
            }
        case 3:
            if(lef < elements->size())
                return lef;
            else
                return elements->size() -1;
    }
    
}

void QuickSort::setQuickSortType(string QuickSortType){
    if(QuickSortType == "QC"){
        quickSortType = 1;
        pivotType = 1;
    }else if(QuickSortType == "QM3"){
        quickSortType = 1;
        pivotType = 2;
    }else if(QuickSortType == "QPE"){
        quickSortType = 1;
        pivotType = 3;
    }else if(QuickSortType == "QI1"){
        quickSortType = 2;
        insertionPercentage = 1;
    }else if(QuickSortType == "QI5"){
        quickSortType = 2;
        insertionPercentage = 5;
    }else if(QuickSortType == "QI10"){
        quickSortType = 2;
        insertionPercentage = 10;
    }else if(QuickSortType == "QNR"){
        quickSortType = 3;
    }
};


tuple<int, int> QuickSort::partition(int lef, int rig, vector<int>* elements) {
    int pivotIndex = findPivot(lef, rig, elements);
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