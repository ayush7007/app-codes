#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;



int allStrings(char input[], int k, char output[][100]) {
    // Write your code here
    if(k==0)
    {
        output[0][0]='\0';
        return 1;
    }

    int x=allStrings(input,k-1,output);

    int length=strlen(input);

    for(int i=1;i<length;i++)
    {
        for(int j=0;j<x;j++)
        {
            int l;
            for( l=0;output[j][l]!='\0';l++)
            {
                output[i*x+j][l]=output[j][l];
            }
            output[i*x+j][l]='\0';
        }
    }

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<x;j++)
        {
            int l;
            for(l=0;output[i*x+j][l]!='\0';l++)
            {
            }
            output[i*x+j][l]=input[i];
            output[i*x+j][l+1]='\0';
        }
    }

    return x*length;


}


vector<vector<char *>*> * out=new vector<vector<char *>*>();
	set<vertex *> smallvisited;

	vector<vector<char *>*> *ConnectedCompo(){
		if(vertices.size()==0){
			return 0;
		}
		for(int i=0;i<vertices.size();i++){
			if(smallvisited.count(vertices[i])==0){
				set<vertex *> visit;
				vector<vector<char *>*> * answer=helper(vertices[i],visit);
			}
		}
		return out;

	}
	vector<vector<char *>*>* helper(vertex *v1,set<vertex *> &visit){

		vector<char *>* temp=new vector<char *>();
		extrahelper(v1,visit);
		set<vertex *>:: iterator it=visit.begin();
		while(it!=visit.end()){
				char *namecopy = new char[strlen((*it)->name)+1];
				strcpy(namecopy,(*it)->name);
				temp->push_back(namecopy);
				it++;
		}
		out->push_back(temp);
		return out;

	}
	void extrahelper(vertex *v1, set<vertex *> &visit){
		visit.insert(v1);
		smallvisited.insert(v1);
		vector<vertex *>  *adjacent=v1->getAdjacentVertices();
		for(int i=0;i<adjacent->size();i++){
			if(visit.count(adjacent->at(i))==0){
				extrahelper(adjacent->at(i),visit);
			}
		}
	}


int main()
{

    /*char output[50][100];
    char input[]="abc";

    int f= allStrings(input,2,output);

    for(int i=0;i<f;i++)
    {
            cout<<output[i]<<endl;
    }
    */
  //  vector< int > V = { 1, 2, 3, 4, 5, ... };

 //   priority_queue< int > Q( V.begin(), V.end());


    priority_queue< int,vector<int>,greater<int> > heap;

    heap.push(7);
    heap.push(23);
    heap.push(21);
    heap.push(3);
    heap.push(8);
    heap.push(34);
    heap.push(6);
    heap.push(10);
    heap.push(5);

    while(!heap.empty())
    {
        cout<<heap.top()<<endl;
        heap.pop();
    }




    return 0;
}
