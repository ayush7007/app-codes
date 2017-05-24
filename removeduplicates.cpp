

#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

    pair<int*,int> removeduplicate(int a[],int n)
    {
        unordered_map<int,int> mymap;
        for(int i=0;i<n;i++)
        {
            if(mymap.find(a[i])!=mymap.end())
            {
                a[i]=-1;
            }

                mymap[a[i]]=mymap[a[i]]+1;

        }
        int Size=mymap.size();

        int* ret=new int[Size];
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1)
            {
                ret[j]=a[i];
                j++;
            }
        }

        return (pair<int*,int>(ret,j)) ;


    }


int main()
{


    int arr[]={6,3,3,0,0,6,6,1,0,8,8,0,3,8,0};


    pair<int*,int> mypair=removeduplicate(arr,15);

    for(int i=0;i< mypair.second ;i++){
        cout<<mypair.first[i]<<" ";
    }
    cout<<endl;
    return 0;
}











