#include<iostream>
#include"AdjacencyGraph2.h"

using namespace std;

int main()
{
    Graph g;


    char a[] = "Delhi";
	char b[] = "Noida";
	char c[] = "Gurgaon";
	char d[] = "Faridabad";
	char e[] = "Harayana";
	char f[]= "punjab";
	char h[]= "gujarat";

	g.addVertex(a);
	g.addVertex(b);
	g.addVertex(c);
    g.addVertex(h);
	g.addVertex(d);
	g.addVertex(e);
    g.addVertex(f);

   // g.print();

	g.addEdge(a, b);
	g.addEdge(b, c);
	g.addEdge(c, d);
	g.addEdge(d, e);
	g.addEdge(a, c);
	g.addEdge(b,e);
    g.addEdge(h,f);

    g.print();
    cout<<endl<<endl;

    g.BFS();

    return 0;

}
