
#include<iostream>
#include<string>

using namespace std;




int allCodesReturnH(int a[],int Size,char output[][100])
{

    if(Size==0)
    {

        output[0][0]='\0';
        return 1;
    }

    if(Size==1)
    {

        output[0][0]='a'-1+a[0];
        output[0][1]='\0';
        return 1;
    }

      char smallOutput1[20][100];
      char smallOutput2[20][100];

    int k=allCodesReturnH(a,Size-1,smallOutput1);

    int m=allCodesReturnH(a,Size-2,smallOutput2);

    for(int i=0;i<k;i++)
    {
        int j=0;
        for(;smallOutput1[i][j]!='\0';j++)
        {
            output[i][j]=smallOutput1[i][j];
        }
        output[i][j]='a'-1+a[Size-1];
        output[i][j+1]='\0';
    }


    int num=10*a[Size-2]+a[Size-1];
    int z=0;
    if(num<=26)
    {
            for(int i=0;i<m;i++)
    {
        int j=0;
        for(;smallOutput2[i][j]!='\0';j++)
        {
            output[i+k][j]=smallOutput1[i][j];
        }
        output[i+k][j]='a'-1+num;
        output[i+k][j+1]='\0';
    }
    z=m;
    }

    return k+z ;

}

int allCodesReturn(int n, char output[][100]) {

      int rev=0;

    if(n==0)
    {
        return 0;
    }

    while(n!=0)
    {
        int nextdigit=n%10;

        n=n/10;
        rev=rev*10+nextdigit;
    }


int m=0;
int a[100];
while(rev)
{
    a[m]=rev%10;
    rev=rev/10;
    m++;
}

    return allCodesReturnH( a, m,output);

}

int main()
{

    char output[100][100];

    int k= allCodesReturn(11243,output);

    for(int i=0;i<k;i++)
    {
            cout<<output[i]<<endl;
    }
    return 0;
}



