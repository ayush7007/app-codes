
#include <iostream>

using namespace std;

void mergearray(int a[],int si,int ei)
{

    int mid=si+(ei-si)/2;
    int l1=mid-si+1;
    int l2=ei-mid;


    int left[l1],right[l2];

    for(int i=0;i<l1;i++)
    {
        left[i]=a[si+i];
    }
    for(int i=0;i<l2;i++)
    {
        right[i]=a[mid+1+i];
    }

    int i=0,j=0,k=si;
    while(i<l1&&j<l2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            k++;
            i++;
        }
        else{
            a[k]=right[j];
            k++;
            j++;
        }
    }
    while(i<l1)
    {
        a[k]=left[i];
        k++;
        i++;
    }
    while(j<l2)
    {
        a[k]=right[j];
        k++;
        j++;
    }

}

void mergesortH(int a[],int starti,int endi)
{
    if(starti>=endi)
    {
        return;
    }

    int mid=starti+(endi-starti)/2;

    mergesortH(a,starti,mid);
    mergesortH(a,mid+1,endi);
    mergearray(a,starti,endi);

}

void mergesort(int input[],int size)
{
    mergesortH(input,0,size-1);
}

int main()
{
  int input[100],size1;
  cout<<"Enter the value of size"<<endl;
  cin>>size1;
  for(int i=0;i<size1;i++)
  {
      cin>>input[i];
  }
  mergesort(input,size1);

 for(int i=0;i<size1;i++)
 {

    cout<<input[i]<<" ";
 }
    return 0;
}


