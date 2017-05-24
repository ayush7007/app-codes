
#include <iostream>
#include<algorithm>
using namespace std;


int maxWater(int arr[],int n)
{
    sort(arr,arr+n);
    int k=arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=k;


    int * left=new int[n];
    int * right=new int[n];

    int trap=0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
       left[i] = max(left[i-1], arr[i]);

    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
       right[i] = max(right[i+1], arr[i]);

     for (int i = 0; i < n; i++)
       trap += min(left[i],right[i]) - arr[i];

       delete [] left;
       delete [] right;

    return trap;

}
int main(){

    int n;
    cin>>n;
    int * arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<< maxWater(arr,n);

    delete [] arr;
	return 0;
}
