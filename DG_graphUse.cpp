#include<iostream>
#include"DG_AdjacencyGraph.h"

using namespace std;

int main()
{
    Graph g;


    char a[] = "Delhi";
	char b[] = "Noida";
	char c[] = "Gurgaon";
	char d[] = "Faridabad";
	char e[] = "Haryana";
	char f[] = "gujarat";
    char h[] = "shimla";
    char i[] = "punjab";

	g.addVertex(a);
	g.addVertex(b);
	g.addVertex(c);

	g.addVertex(d);
	g.addVertex(e);
    g.addVertex(f);
    g.addVertex(h);
    g.addVertex(i);

   // g.print();

	g.addEdge(a, c,10);
	g.addEdge(b, c,12);
	g.addEdge(b,d,15);
	g.addEdge(c, e,20);
	g.addEdge(d,f,10);
	g.addEdge(e,h,8);
	g.addEdge(e,f,9);

	g.addEdge(f,i,13);
	//g.addEdge(d,d,40);//self loop
    //g.addEdge(d,f,30);
	//g.removeVertex(b);


    g.print();
    cout<<endl;

   //cout<< g.detectCycle()<<endl;
    cout<<g.maxPath(a)<<endl;
   // g.topologicalSort();

    return 0;

}

