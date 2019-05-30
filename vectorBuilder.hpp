#ifndef VECTOR_BUILDER_H
#define VECTOR_BUILDER_H

#include <vector>
#include <string>

using namespace std;

class VectorBuilder{
private:
    int vectorLength;
    int vectorOrder;
public:
    void setVectorLength(int VectorLength);
    void setVectorOrder(string VectorOrder);
    vector<int>* buildVector();
};

#endif
