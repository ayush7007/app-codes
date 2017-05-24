#include<iostream>
using namespace std;

void subsetSumToKHelper(int input[],int size1,int si,int outputarray[],int size2,int sum,int tempsum,int output[][50],int outputsize[])
{

    if(size1==0)
    {
        if(tempsum==sum)
        {
            int temp=outputsize[0];
            output[temp][0]=size2;

        for(int i=0;i<size2;i++)
        {
            output[temp][i+1]=outputarray[i];
        }
        outputsize[0]++;
        }
        return;
    }

    subsetSumToKHelper(input,size1-1,si+1,outputarray,size2,sum,tempsum,output,outputsize);

    outputarray[size2]=input[si];

    subsetSumToKHelper(input,size1-1,si+1,outputarray,size2+1,sum,tempsum+input[si],output,outputsize);

}

int subsetSumToK(int input[],int n, int output[][50],int k)
{
    int outputarray[20];
    int outputsize[1]={0};
    subsetSumToKHelper(input,n,0,outputarray,0,k,0,output,outputsize);

    return outputsize[0];
}
int main()
{

    int input[]={3,2,1,4};

    int output[1000][50];

    int k=subsetSumToK(input,4,output,6);

    for(int i=0;i<k;i++)
    {
        for(int j=1;j<=output[i][0];j++)
        {
            cout<<output[i][j];
        }
        cout<<endl;
    }
    return 0;
}






