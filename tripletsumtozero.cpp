#include<iostream>
#include<unordered_map>
#include<algorithm>

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


void triplet(int  a[],int Size)
{

    sort(a,a+Size);

    for(int i=0;i<Size-2;i++)
    {
        int first=i+1;
        int last=Size-1;

        while(first<last)
        {


            if( a[i] + a[first] + a[last] == 0)
            {
               cout<<a[i]<<" "<<a[first]<<" "<<a[last]<<" "<<endl;
               first++;
               last--;
            }
            else if (a[i] + a[first] + a[last] < 0)
                first++;
            else //a[i] + a[first] + a[last]>0
                last--;
            }

        }

    }







int main()
{
    int arr[]={2,3,4,8,-2,-1,-3,3,8,-8,-4};
    triplet(arr,11);

    return 0;

}


N
