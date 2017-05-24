
#ifndef EDGE2_H
#define EDGE2_H
#include"Vertex2.h"

class Vertex;

class Edge{
    public:
    Vertex* first;
    Vertex* second;

        Edge(Vertex* v1,Vertex* v2)
        {
                this->first=v1;
                this->second=v2;
        }

};
#endif // EDGE2_H
