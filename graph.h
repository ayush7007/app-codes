#include<include>
#include<string>



class Edge;

class Vertex{
    string name;
    vector<Edges*> edge;

    Vertex(string name)
    {
        this -> name = new string(name);

    }
    friend class Edge;
    friend class Graph;

      void removeEdgeWith(Vertex* v)
    {

        for(int i=0;i<edges.size();i++)
        {

            if(edges[i]->v2==v)
            {
                delete edges[i];
                edges.erase(edges.begin()+i);
                break;
            }
        }


    }


    vector<Vertex*> getAllAdjacentVertices()
    {
        vector<Vertex*>* output=new vector<Vertex*>;

        for(int i=0;i<edge.size();i++)
        {
            output->push_back(edge[i]->v2);
        }
        return output;
    }





};


class Edge{
    vertex* v1;
    vertex* v2;

        Edge(Vertex & v1,Vertex &v2):v1(v1),v2(v2)
        {

        }
    friend class Graph;


};



class Graph{

    vector<Vertex*> vertices;

    vertex* getCity(string const&city)
    {
        for(int i=0;i<vertices.size();i++)
        {
            if(vertices[i]->name==city)
            {
                return vertices[i];
            }
        }
        return NULL;
    }

    public:

        void addCity(string const & cityname)
        {
            if(containsCity(cityname))
            {
                return;
            }
            Vertex* newVertex=new Vertex(cityname);
            vertices.push_back(newVertex);
        }

        bool containsCity(string const& cityname)
        {
                return getCity(cityname)!=NULL;
        }

        void deleteCity(string cityname)
        {
            int index=isvertexpresent(cityname);
            if(index==-1)
            {
                cout << "Vertex not exists ! " << endl;
                return;
            }

            Vertex* v=vertices[index];
            vector<Vertex*> adj = v -> getAllAdjacentVertices();
            for(int i = 0; i < adj.size(); i++) {
                adj[i] -> removeEdgeWith(v);
            }

            vertices.erase(vertices.begin() + index);
            delete v;

        }




};
