
#include<iostream>
#include<string>

using namespace std;


int getAllCodesH(char a[],int Size,char output[][100])
{

    if(Size==0)
    {

        output[0][0]='\0';
        return 1;
    }

    if(Size==1)
    {
        int temp=a[0]-'0';
        output[0][0]='a'-1+temp;
        output[0][1]='\0';
        return 1;
    }

      char smallOutput1[20][100];
      char smallOutput2[20][100];

    int k=getAllCodesH(a,Size-1,smallOutput1);

    int m=getAllCodesH(a,Size-2,smallOutput2);

    for(int i=0;i<k;i++)
    {
        int j=0;
        for(;smallOutput1[i][j]!='\0';j++)
        {
            output[i][j]=smallOutput1[i][j];
        }
        int temp=a[Size-1]-'0';
        output[i][j]='a'-1+temp;
        output[i][j+1]='\0';
    }


    int num=10*(a[Size-2]-'0')+(a[Size-1]-'0');
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

int getAllCodes(char input[], char output[][100]) {
    // Write your code here
    int i=0;
    while(input[i]!='\0')
    {
        i++;
    }
   return  getAllCodesH(input,i,output);

}


int main()
{
    char input[]="1123";
    char output[100][100];

    int k= getAllCodes(input,output);

    for(int i=0;i<k;i++)
    {
            cout<<output[i]<<endl;
    }
    return 0;
}




