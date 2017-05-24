#include<iostream>

using namespace std;

int subsetSumToKHelper(int input[], int n, int outputtemp[][50]) {

if(n==0)
{
    outputtemp[0][0]=0;
    outputtemp[0][1]=0;
    return 1;
}

int k=subsetSumToKHelper(input,n-1,outputtemp);

for(int i=0;i<k;i++)
{
    for(int j=0;j<=outputtemp[i][1]+1;j++)
    {
        outputtemp[i+k][j]=outputtemp[i][j];
    }


    outputtemp[i+k][1]++;
    outputtemp[i+k][0]=outputtemp[i+k][0]+input[n-1];

int numelements=outputtemp[i+k][1];
outputtemp[i+k][numelements+1]=input[n-1];
}

return 2*k;

}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here

    int outputtemp[1000][50];

    int m=subsetSumToKHelper(input,n,outputtemp);
    int z=0;
    for(int i=m-1;i>0;i--)
    {

        if(outputtemp[i][0]==k)
        {
            for(int j=1;j<=outputtemp[i][1]+1;j++)
            {
                output[z][j-1]=outputtemp[i][j];
            }
            z++;
        }

    }

    return z;

}




int main()
{

    int input[]={16,14,2,14,15,16,23,45};


    int output[1000][50];

    int k=subsetSumToK(input,8,output,2);

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


