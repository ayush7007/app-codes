

#ifndef DG_EDGE_H
#define DG_EDGE_H
#include"DG_Vertex.h"

class Vertex;

class Edge{
    public:
    Vertex* first;
    Vertex* second;
    int weight;

        Edge(Vertex* v1,Vertex* v2,int weight)
        {
                this->weight=weight;
                this->first=v1;
                this->second=v2;
        }

};
#endif // EDGE2_H
