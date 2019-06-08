#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <numeric>

#include "vectorBuilder.hpp"
#include "quickSort.hpp"
#include "insertionSort.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    string variation, vectorType;
    int vectorSize, repetions = 20;
    bool printUsedVector = false;

    if(argc < 4 || argc > 5){
        cerr << "Quantidade de parametros incorreta: 3 requeridos " << argc -1 << " fornecidos";
        return 1;
    }

    variation = argv[1];
    vectorType = argv[2];
    vectorSize = stoi(argv[3]);

    if(argc == 5)
        if( strcmp(argv[4] , "-p") == 0)
            printUsedVector = true;

    int medianTimeSpend;
    int averageComparisonsMade;
    int averageMovimentationsMade;
    VectorBuilder constructor;
    QuickSort sorter;
    vector<int>* vet;
    vector<int> usedVector;
    vector<int> timeSpend, comparisonsMade, movimentationsMade;
    stack<vector<int>> usedVectors;

    constructor.setVectorLength(vectorSize);
    constructor.setVectorOrder(vectorType);
    sorter.setQuickSortType(variation);

    while(repetions > 0){
        vet = constructor.buildVector();

        if(printUsedVector)
            usedVectors.push(*vet);

        sorter.setVector(vet);
        sorter.sort();

        comparisonsMade.push_back(sorter.getComparisonCounter());
        movimentationsMade.push_back(sorter.getMovimentationCounter());
        timeSpend.push_back(sorter.getElapsedTime().count());

        repetions--;
    }

    averageMovimentationsMade = accumulate( movimentationsMade.begin(), movimentationsMade.end(), 0.0);
    averageMovimentationsMade /= movimentationsMade.size();

    averageComparisonsMade = accumulate( comparisonsMade.begin(), comparisonsMade.end(), 0.0);
    averageComparisonsMade /=  comparisonsMade.size();

    medianTimeSpend = findMedian(&timeSpend);

    cout << variation << " ";
    cout << vectorType << " ";
    cout << vectorSize << " ";
    cout << averageComparisonsMade << " ";
    cout << averageMovimentationsMade << " ";
    cout << medianTimeSpend << endl;

    for(int i = 0; i < usedVectors.size(); i++){
        usedVector = usedVectors.top();
        usedVectors.pop();

        for(int j = 0; j < usedVector.size(); j++){
            cout << usedVector[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
