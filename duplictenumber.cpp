#include<iostream>
#include<unordered_map>

using namespace std;

int findDuplicate(int arr[],int Size)
{
    unordered_map<int,int> mymap;
    for(int i=0;i<Size;i++)
        {
            mymap[arr[i]]=mymap[arr[i]]+1;
        }

    unordered_map<int,int>::iterator it=mymap.begin();

     while(it!=mymap.end())
     {
         if(it->second==2)
         {
             return it->first;
         }
         it++;
     }

}

int findduplicteeasy(int arr[],int Size)
{
    int sum=0;
    for(int i=0;i<Size;i++)
    {
        sum=sum+arr[i];
    }

    int exact=0;
     for(int i=0;i<Size-1;i++)
    {
        exact=exact+i;
    }

    return sum-exact;

}

int main()
{
    int arr[]={0,1,2,5,3,4,6,7,8,9,11,10,11};
    int i=findDuplicate(arr,13);
    cout<<i<<endl;
    cout<<findduplicteeasy(arr,13)<<endl;

    return 0;

}
