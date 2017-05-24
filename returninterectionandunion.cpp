#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

pair<vector<int>*,vector<int>*> retIandU(int a[],int n,int b[],int m)
    {
            unordered_map<int,bool> mymap;

            for(int i=0;i<n;i++)
            {
                mymap[a[i]]=true;
            }

            vector<int>* intersect=new vector<int>;
            for(int i=0;i<m;i++)
            {
                if(mymap.find(b[i])!=mymap.end())
                {
                    intersect->push_back(b[i]);
                }
            }

            vector<int>* uni=new vector<int>;
            for(int i=0;i<n;i++)
            {
                uni->push_back(a[i]);
            }


            for(int i=0;i<m;i++)
            {
                if(mymap.find(b[i])==mymap.end())
                {
                    uni->push_back(b[i]);
                }


            }


            return pair<vector<int>*,vector<int>*>(intersect,uni);

    }




int main()
{
    int arr[]={2,3,4,5,6};
    int brr[]={1,3,5,7,8};

    pair<vector<int>*,vector<int>*> mypair= retIandU(arr,5,brr,5);
    cout<<"Intersection"<<endl;

    vector<int>::iterator it=mypair.first->begin();
    while(it!=mypair.first->end())
    {
        cout<<*it<<" ";
        it++;
    }

    cout<<endl<<"Union"<<endl;

    vector<int>::iterator it1=mypair.second->begin();
    while(it1!=mypair.second->end())
    {
        cout<<*it1<<" ";
        it1++;
    }

    cout<<endl;

    delete mypair.first;
    delete mypair.second;

    return 0;

}



