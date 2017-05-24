#include<iostream>
using namespace std;

void printSubsetSumToKHelper(int input[],int size1,int si,int output[],int size2,int sum,int tempsum)
{

    if(size1==0)
    {
        if(tempsum==sum)
        {
        for(int i=0;i<size2;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        }
        return;
    }

    printSubsetSumToKHelper(input,size1-1,si+1,output,size2,sum,tempsum);

    output[size2]=input[si];

    printSubsetSumToKHelper(input,size1-1,si+1,output,size2+1,sum,tempsum+input[si]);

}

void printSubsetSumToK(int input[], int size,int k)
{
    int output[20];
    printSubsetSumToKHelper(input,size,0,output,0,k,0);

}


int main()
{

    int input[]={3,2,1,3,4};

    printSubsetSumToK(input,5,6);

    return 0;
}




