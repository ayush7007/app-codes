

#include<iostream>
#include<algorithm>

using namespace std;

    void pushzero(int a[],int n)
    {
     int i=0,j=0;

     while(i<n)
     {
         if(a[i]!=0)
         {
             swap(a[i],a[j]);
             i++;
             j++;
         }
         else{
            i++;
         }

     }

    }


int main()
{


    int arr[9]={6,0,0,1,0,8,0,3,0};


    pushzero(arr,9);

    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}










