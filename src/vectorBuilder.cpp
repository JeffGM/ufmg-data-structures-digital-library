#include "vectorBuilder.hpp"
#include <stdlib.h>
#include <algorithm>


using namespace std;
void VectorBuilder::setVectorLength(int VectorLength){
    vectorLength = VectorLength;
}

void VectorBuilder::setVectorOrder(string VectorOrder){
    if(VectorOrder == "Ale")
        vectorOrder = 1;
    else if(VectorOrder == "OrdC")
        vectorOrder = 2;
    else if(VectorOrder == "OrdD")
        vectorOrder = 3;
}

vector<int>* VectorBuilder::buildVector(){
    vector<int>* largeVector = new vector<int>();

    largeVector->reserve(vectorLength);

    switch(vectorOrder){
        case 1:
            for(int i = 0; i < vectorLength; i++)
                largeVector->push_back(i + 1);
            random_shuffle(largeVector->begin(), largeVector->end());
            break;
        case 2:
            for(int i = 0; i < vectorLength; i++)
                largeVector->push_back(i + 1);
            break;
        case 3:
            for(int i = vectorLength; i >= 0; i--)
                largeVector->push_back(i);
            break;
    }
    return largeVector;
}
