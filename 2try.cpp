#include<iostream>


#include<string.h>

using namespace std;

int allStrings(char input[], int k, char output[][100]) {
    // Write your code here
    if(k==0)
    {
        output[0][0]='\0';
        return 1;
    }
    int x=allStrings(input,k-1,output);
    int l=strlen(input);
    int i,j,m,n;
    for(i=1;i<l;i++)
    {
        for(j=0;j<x;j++)
        {
            for(m=0;output[j][m];m++)
            {
                output[i*x+j][m]=output[j][m];
            }
            output[i*x+j][m]='\0';
        }
    }
    for(i=0;i<l;i++)
    {
        for(j=0;j<x;j++)
        {
            for(m=0;output[i*x+j][m];m++)
            {
            }
            output[i*x+j][m]=input[i];
            output[i*x+j][m+1]='\0';
        }
    }
    return x*l;

}

int main()
{

    char output[50][100];
    char input[]="abc";

    int k= allStrings(input,2,output);

    for(int i=0;i<k;i++)
    {
            cout<<output[i]<<endl;
    }
    return 0;
}
