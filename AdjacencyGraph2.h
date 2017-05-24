#ifndef ADJACENCYGRAPH2_H
#define ADJACENCYGRAPH2_H
#include "Vertex2.h"
#include "Edge2.h"
#include <vector>
#include<queue>
#include<string.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Graph {

    vector<Vertex*>* vertices;


    Vertex* getVertex(char* name)
      {
          for(int i=0;i< vertices->size();i++)
            {
                Vertex* v=vertices->at(i);
                if(strcmp(v->name,name)==0)
                {
                    return v;
                }

            }
            return NULL;
      }



     public:
        Graph()
        {
            vertices=new vector<Vertex*>();
        }

        void print()
        {
            cout<<"Printing graph"<<endl;
            for(int i=0;i< vertices->size();i++)
            {
                vertices->at(i)->print();
                cout<<endl;
            }
            cout<<"Done Printing"<<endl;
        }

        void removeVertex(char* name)
        {
            Vertex* v=getVertex(name);
            if(v==NULL)
            {
                return;
            }
            vector<Vertex*>* adj =v->getAdjacent();
            for(int i=0;i<adj->size();i++)
            {
                adj->at(i)->removeEdgeWith(v);
            }
            delete adj;

            vector<Vertex*> :: iterator it=vertices->begin();

            while(it!=vertices->end())
            {
                if(*it==v)
                {
                    break;
                }
                it++;
            }

            vertices->erase( it );
        }

        int numEdges()
        {
            int total=0;
            for(int i=0;i<vertices->size();i++)
            {
                total=total+vertices->at(i)->numEdges();
            }
            return total/2;

        }



        int numVertices() {
			return vertices->size();
		}


        bool areAdjacent(char* first, char* second)
        {
            Vertex* v1=getVertex(first);
            Vertex* v2=getVertex(second);
            if(v1==NULL||v2==NULL)
            {
                throw "Vertex not found";
            }

            return v1->isAdjacent(v2)||v2->isAdjacent(v1);

        }

        void addVertex(char* name)
        {
            if(getVertex(name)!=NULL)
            {
                return;
            }

            Vertex* v=new Vertex(name);
            vertices->push_back(v);
        }


        void addEdge(char* first, char* second)
        {
            Vertex* v1=getVertex(first);
            Vertex* v2=getVertex(second);
            if(v1==NULL||v2==NULL)
            {
                throw "Vertex not found";
            }

            if(v1->isAdjacent(v2))
            {
                return;
            }
            Edge * e =new Edge(v1,v2);
            v1->addEdge(e);
            v2->addEdge(e);

        }


        void BFS()
        {
            if(vertices->size()==0)
            {
                return;
            }
            queue<Vertex*> q;
            unordered_map<Vertex*,bool> visited;


           // visited(vertices[0]);

            for(int i=0;i<vertices->size();i++)
            {
                    if(visited[vertices->at(i)]==0)
                    {
                        q.push(vertices->at(i));
                        visited[vertices->at(i)]=1;
                        while(!q.empty())
                        {
                            Vertex* v=q.front();
                            q.pop();
                            cout<<v->name<<" ";

                            vector<Vertex*>* adj=v->getAdjacent();
                            for(int j=0;j<adj->size();j++)
                            {
                                if(visited[adj->at(j)]==0)
                                {
                                    q.push(adj->at(j));
                                    visited[adj->at(j)]=1;
                                }

                            }

                            delete  adj;

                        }

                    }
            }
            cout<<endl;

        }




};
#endif
