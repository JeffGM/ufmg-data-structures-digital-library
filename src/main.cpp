#include <iostream>
#include <vector>
#include "vectorBuilder.hpp"
using namespace std;

int main()
{
    vector<int>* vet;

    VectorBuilder constructor;
    constructor.setVectorLength(500000);
    constructor.setVectorOrder("OrdC");
    vet = constructor.buildVector();

    for(int i = 0; i < vet->size(); i++)
        cout << (*vet)[i] << endl;

    cout << "Hello world!" << endl;
    return 0;
}
