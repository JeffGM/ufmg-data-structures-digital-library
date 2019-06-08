#include "insertionSort.hpp"
void InsertionSort::setVector(vector<int>* Elements) {
    elements = Elements;
}


int InsertionSort::getComparisonCounter(){
    return comparisonCounter;
}

int InsertionSort::getMovimentationCounter(){
    return movimentationCounter;
}
void InsertionSort::sort(int lef, int rig){
    int i, j;

    for(i = lef +1 , j = lef; i < rig + 1; i++ ){
        comparisonCounter++;

        while(elements->at(i) >= elements->at(j) && j < i ) j++; comparisonCounter++;;

        comparisonCounter++;
        if(i > j){
            auto insertionPos = elements->begin() + j;
            elements->insert(insertionPos, elements->at(i));
            auto deletionPos = elements->begin() + i + 1;
            elements->erase(deletionPos);

            movimentationCounter += 2;
        }
        j = lef;
    }
}
