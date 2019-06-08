#include "quickSort.hpp"
#include <iostream>
using namespace std;

chrono::duration<double, std::micro>  QuickSort::getElapsedTime(){
    return elapsed_time;
};

int QuickSort::getComparisonCounter(){
    return comparisonCounter;
}

int QuickSort::getMovimentationCounter(){
    return movimentationCounter;
}

int findMedian(vector<int>* elements){
  InsertionSort sorter;

  sorter.setVector(elements);
  sorter.sort(0, elements->size() - 1);

  return elements->at(elements->size()/2);
}

void QuickSort::iterativeQuickSort(int lef, int rig){
    stack<int> partitionStack;
    int relative_lef, relative_rig;

    partitionStack.push(lef);
    partitionStack.push(rig);

    movimentationCounter += 2;

    while( !partitionStack.empty() ){
        comparisonCounter++;

        rig = partitionStack.top();
        partitionStack.pop();

        movimentationCounter += 2;

        lef = partitionStack.top();
        partitionStack.pop();

        movimentationCounter += 2;

        tie(relative_lef, relative_rig) = partition(lef, rig, elements);

        comparisonCounter++;
        if(relative_lef > lef){
            partitionStack.push(lef);
            partitionStack.push(relative_rig);

            movimentationCounter += 2;
        }

        comparisonCounter++;
        if(rig > relative_rig){
            partitionStack.push(relative_lef);
            partitionStack.push(rig);

            movimentationCounter += 2;
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
                vector<int>* aux = new vector<int> {elements->at(lef), elements->at((lef + rig)/2) , elements->at(rig)};
                median  = findMedian(aux);

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
        comparisonCounter++;

        while(elements->at(lef) < pivot) lef++; comparisonCounter++;
        while(elements->at(rig) > pivot) rig--; comparisonCounter++;

        comparisonCounter++;
        if(lef <= rig){
            iter_swap(elements->begin() + lef, elements->begin() + rig);
            movimentationCounter += 2;
            lef++;
            rig--;
        }

    }
    return make_tuple(lef, rig);
}
//fixme: insert new types of quicksort
void QuickSort::sort(){
    comparisonCounter = 0;
    movimentationCounter = 0;
    chrono::high_resolution_clock::time_point timeBeforeExecution = chrono::high_resolution_clock::now();

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

    chrono::high_resolution_clock::time_point timeAfterExecution = chrono::high_resolution_clock::now();
    elapsed_time = chrono::duration_cast<chrono::duration<double>>(timeAfterExecution - timeBeforeExecution);
}

void QuickSort::classicQuickSort(int lef, int rig){
    int relative_lef, relative_rig;
    tie(relative_lef, relative_rig) = partition(lef, rig, elements);

    comparisonCounter++;
    if(relative_rig < rig){
        classicQuickSort(lef, relative_rig);
        classicQuickSort(relative_lef, rig);
    }
}
void QuickSort::insertionQuickSort(int lef, int rig){
    int relative_lef, relative_rig;
    int current_percentage = 100*(rig - lef)/elements->size();
    tie(relative_lef, relative_rig) = partition(lef, rig, elements);

    comparisonCounter++;
    if(insertionPercentage >= current_percentage){
        InsertionSort sorter;
        sorter.setVector(elements);
        sorter.sort(lef, relative_rig);
        sorter.sort(relative_lef, rig);

        comparisonCounter += sorter.getComparisonCounter();
        movimentationCounter += sorter.getMovimentationCounter();
    }else{
        comparisonCounter++;
        if(relative_rig < rig){
            insertionQuickSort(lef, relative_rig);
            insertionQuickSort(relative_lef, rig);
        }
    }
}

void QuickSort::setVector(vector<int>* Elements){
    elements = Elements;
}