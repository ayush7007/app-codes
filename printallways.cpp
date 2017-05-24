#include<iostream>


using namespace std;

void printallways(int k,int output[],int size2)
{
    if(k==1)
    {
        output[size2]=1;
        for(int i=0;i<=size2;i++)
        {
            cout<<output[i]<<",";
        }
        cout<<endl;
        return;
    }

    if(size2>0){
        for(int j=0;j<size2;j++)
        {
            cout<<output[j]<<",";
        }
        cout<<k<<","<<endl;
        }

    for(int i=1;i<k;i++)
    {
        output[size2]=k-i;
        printallways(i, output,size2+1);

    }

}


    int main()
    {
        int output[20];
        printallways(5,output,0);

        return 0;
    }



