#include "insertionSort.hpp"
void InsertionSort::setVector(vector<int>* Elements) {
    elements = Elements;
}

void InsertionSort::sort(int lef, int rig){
    int i, j;

    for(i = lef +1 , j = lef; i < rig + 1; i++ ){

        while(elements->at(i) >= elements->at(j) && j <= i ) j++;

        if(i > j){
            auto insertionPos = elements->begin() + j;
            elements->insert(insertionPos, elements->at(i));
            auto deletionPos = elements->begin() + i + 1;
            elements->erase(deletionPos);


        }
        j = lef;
    }

}