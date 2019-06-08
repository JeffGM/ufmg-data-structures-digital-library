#include "quickSort.hpp"
#include <iostream>
using namespace std;

int findMedian(int a, int b, int c){
  InsertionSort sorter;

  vector<int>* elements = new vector<int> {a,b,c};

  sorter.setVector(elements);
  sorter.sort(0, elements->size() - 1);

  return elements->at(1);
}
void QuickSort::iterativeQuickSort(int lef, int rig){
    stack<int> partitionStack;
    int relative_lef, relative_rig;

    partitionStack.push(lef);
    partitionStack.push(rig);

    while( !partitionStack.empty() ){
        rig = partitionStack.top();
        partitionStack.pop();

        lef = partitionStack.top();
        partitionStack.pop();


        tie(relative_lef, relative_rig) = partition(lef, rig, elements);

        if(relative_lef > lef){
            partitionStack.push(lef);
            partitionStack.push(relative_rig);
        }

        if(rig > relative_rig){
            partitionStack.push(relative_lef);
            partitionStack.push(rig);
        }

    }
}

//fixme: Add support to other types of pivots
int QuickSort::findPivot(int lef, int rig){
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
        default:
            return (lef + rig)/2;
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
void QuickSort::sort(){
    switch(quickSortType){
        case 1:
            classicQuickSort(0, elements->size() -1);
            break;
        case 2:
            insertionQuickSort(0, elements->size() -1);
            break;
        case 3:
            iterativeQuickSort(0, elements->size() -1);
            break;
    }
}

void QuickSort::classicQuickSort(int lef, int rig){
    int relative_lef, relative_rig;
    tie(relative_lef, relative_rig) = partition(lef, rig, elements);

    if(relative_rig < rig){
        classicQuickSort(lef, relative_rig);
        classicQuickSort(relative_lef, rig);
    }
}
void QuickSort::insertionQuickSort(int lef, int rig){
    int relative_lef, relative_rig;
    int current_percentage = 100*(rig - lef)/elements->size();
    tie(relative_lef, relative_rig) = partition(lef, rig, elements);

    if(insertionPercentage >= current_percentage){
        InsertionSort sorter;
        sorter.setVector(elements);
        sorter.sort(lef, relative_rig);
        sorter.sort(relative_lef, rig);
    }else{
        if(relative_rig < rig){
            insertionQuickSort(lef, relative_rig);
            insertionQuickSort(relative_lef, rig);
        }
    }
}

void QuickSort::setVector(vector<int>* Elements){
    elements = Elements;
}