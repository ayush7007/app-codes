#include<iostream>
#include<algorithm>
using namespace std;

int fac(int n)
{

    if(n==1||n==0)
    {
        return 1;
    }

    return n*fac(n-1);

}

int greaternumbers(int *a,int n)
{
    if(n==1)
    {
        return 0;
    }

    int Count=0;
    int k=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        {
            Count++;
        }
    }

    int permu=Count*fac(n-1)+greaternumbers(a+1,n-1);
    return permu;

}

int greaternumbersrep(int a[],int n)
{





}





int main()
{
    int arr[]={2,4,1,3};
    cout<<greaternumbers(arr,4);

    return 0;

}
