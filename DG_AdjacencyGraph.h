#ifndef DG_ADJACENCYGRAPH_H
#define DG_ADJACENCYGRAPH_H
#include "DG_Vertex.h"
#include "DG_Edge.h"
#include <vector>
#include<queue>
#include<string.h>
#include <unordered_set>
#include <unordered_map>
#include<stack>

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
                v->removeEdgeWith(adj->at(i));
            }
            delete adj;

            for(int i=0;i<vertices->size();i++)
            {
                Vertex* temp=vertices->at(i);
                if(temp!=v)
                {
                   temp->removeEdgeWith(v);
                }

            }

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
            return total;

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


        void addEdge(char* first, char* second,int weight)
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
            Edge * e =new Edge(v1,v2,weight);
            v1->addEdge(e);
     //       v2->addEdge(e);

        }


        void topoHelper(Vertex* v1,stack<Vertex*> &s, unordered_map<Vertex*,bool> &visited)
        {

                visited[v1]=1;
                vector<Vertex*>* adj=v1->getAdjacent();
                for(int i=0;i<adj->size();i++)
                {
                    if(visited[adj->at(i)]==0)
                    {
                    topoHelper(adj->at(i),s,visited);
                    }
                }
                s.push(v1);

        }

        void topologicalSort()
        {
            if(vertices->size()==0)
            {
                return;
            }

            unordered_map<Vertex*,bool> visited;
            stack<Vertex*> s;

            for(int i=0;i<vertices->size();i++)
            {
                if(visited[vertices->at(i)]==0)
                {
                    topoHelper(vertices->at(i),s,visited);
                }

            }

            while(!s.empty())
            {
                Vertex* v=s.top();
                s.pop();
                cout<<v->name<<"  ";
            }
            cout<<endl;


        }

        bool cycleHelper(Vertex* v, unordered_set<Vertex*> &white, unordered_set<Vertex*> &gray, unordered_set<Vertex*> &black,unordered_map<Vertex*,Vertex*> &intro)
        {
            if(gray.find(v)!=gray.end())
            {
                Vertex* first=v;
                Vertex* second=intro[v];
                cout<<first->name<<"<--";
                while(second!=v)
                {
                    cout<<second->name<<"<--";
                    first=second;
                    second=intro[first];
                }
                cout<<second->name<<"<--"<<endl;
                return true;
            }

            if(black.find(v)!=black.end())
            {
                return false;
            }

            if(white.find(v)!=white.end())
            {
                    unordered_set<Vertex*>:: iterator it=white.find(v);
                    Vertex* temp= (*it);
                    white.erase(white.find(v));
                    gray.insert(temp);
                vector<Vertex*>* adj=v->getAdjacent();

                for(int i=0;i<adj->size();i++)
                {
                    intro[adj->at(i)]=v;
                   bool ans= cycleHelper(adj->at(i),white,gray,black,intro);
                    if(ans)
                    {
                        return true;
                    }

                }

                gray.erase(gray.find(v));
                black.insert(v);
                return false;
            }

        }



        bool detectCycle()
        {
            if(vertices->size()==0)
            {
                return false;
            }
            unordered_set<Vertex*> white;
            unordered_set<Vertex*> gray;
            unordered_set<Vertex*> black;
         unordered_map<Vertex*,Vertex*> intro;

            for(int i=0;i<vertices->size();i++)
            {
                white.insert(vertices->at(i));
            }


            while(!white.empty())
            {
               unordered_set<Vertex*>:: iterator  it=white.begin();
               intro[*it]=NULL;
                bool k=cycleHelper(*it,white,gray,black,intro);
                if(k)
                {
                    return true;
                }
            }


            return false;

        }

            private:
        static int maxPathHelper(Vertex *x)
        {
            int path=0;
            vector<Vertex*>* adj=x->getAdjacent();
            for(int i=0;i<adj->size();i++)
                {
                    path=max(path,x->weightWith(adj->at(i))+maxPathHelper(adj->at(i)));

                }
            return path;
        }

            public:
        int maxPath(char* name)
        {
             Vertex* v=getVertex(name);
             if(v==NULL)
             {
                 return 0;
             }
            return maxPathHelper(v);
        }


        void dijkstra( char * source)
        {
            Vertex* v=getVertex(name);
            if(v==NULL)
            {
                return;
            }
            priority_queue< pair<int,Vertex*> ,vector<pair<int,Vertex*> , greater<pair<int,Vertex*> > pq;

            unordered_map<Vertex*,int> distance;
            for(int i=0;i<vertices.size();i++)
            {
                distance[vertices[i]]=INT_MAX;
            }

            pq.push(make_pair(0,v));
            distance[v]=0;

            while(!pq.empty())
            {
                Vertex* small= pq.top().second;
                pq.pop();
                vector<Vertex*>* adj=small->getAdjacent();
                for(int i=0;i<adj->size();i++)
                {





                }


            }

        }



};
#endif

