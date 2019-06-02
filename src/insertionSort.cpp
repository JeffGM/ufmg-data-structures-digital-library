#include "insertionSort.hpp"
void InsertionSort::setVector(vector<int>* Elements) {
    elements = Elements;
}

void InsertionSort::sort(int lef, int rig){
    int i, j;

    for(i = lef + 1, j = lef; i < rig; i++ ){

        while(elements->at(i) > elements->at(j) ) j++;

        if(i > j){
            auto insertionPos = elements->begin() + lef + j;
            elements->insert(insertionPos, elements->at(i));
            auto deletionPos = elements->begin() + lef + i + 1;
            elements->erase(deletionPos);
        }
        j = lef;
    }

}