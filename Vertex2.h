
#ifndef VERTEX2_H
#define VERTEX2_H
#include "Edge2.h"
#include <vector>
#include<string.h>

using namespace std;

class Vertex {

        vector<Edge*>* adjacent;

        public:
        char* name;
        Vertex(char* name)
        {
            this->name=new char[strlen(name)+1];
            strcpy(this->name,name);
            adjacent=new vector<Edge*>();
        }


        void addEdge(Edge * e)
        {
            adjacent->push_back(e);
        }

        int numEdges()
        {
            return adjacent->size();
        }


        bool isAdjacent(Vertex* otherVertex)
        {
            for(int i=0;i<adjacent->size();i++)
            {
                Edge * e=adjacent->at(i);
                if(e->first==otherVertex || e->second==otherVertex)
                {
                    return true;
                }

            }
            return false;
        }


        void removeEdgeWith(Vertex* otherVertex)
        {
            for(int i=0;i<adjacent->size();i++)
            {
                Edge * e=adjacent->at(i);
                if(e->first==otherVertex || e->second==otherVertex)
                {
                    adjacent->erase(adjacent->begin()+i);
                    return ;
                }

            }

        }

        vector<Vertex*>* getAdjacent()
        {
            vector<Vertex*>* vec=new vector<Vertex*>();

            for(int i=0;i<adjacent->size();i++)
            {
                 Edge * e=adjacent->at(i);
                 if(e->first==this)
                 {
                     vec->push_back(e->second);
                 }
                 else{
                    vec->push_back(e->first);
                 }


            }
            return vec;
        }

        void print()
        {
            cout<<name<<":";
            for(int i=0;i<adjacent->size();i++)
            {
                 Edge * e=adjacent->at(i);
                 if(e->first==this)
                 {
                     cout<<e->second->name<<",";
                 }
                 else{
                    cout<<e->first->name<<",";
                 }


            }
            cout<<endl;
        }

        ~Vertex()
        {
            delete adjacent;
            delete [] name;
        }


};

#endif
