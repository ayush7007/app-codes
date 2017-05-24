#include<iostream>
#include<unordered_map>
using namespace std;

void findpair(int a[],int Size)
{
    unordered_map<int,int> mymap;

    for(int i=0;i<Size;i++)
    {
        if(mymap.find(-1*a[i])!=mymap.end())
        {
            int freq=mymap[-1*a[i]];
            for(int j=0;j<freq;j++)
            {
                cout<<a[i]<<" "<<-1*a[i]<<endl;
            }
        }


        mymap[a[i]]=mymap[a[i]]+1;
    }
}


int main()
{
    int arr[]={2,3,4,8,-2,-1,-3,3,8,-8,-4};
    findpair(arr,11);

    return 0;

}

