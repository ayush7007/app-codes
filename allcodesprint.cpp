
#include<iostream>
#include<string>

using namespace std;



void allCodesH(int a[],int size1,char output[],int size2)
{
    if(size1==0)
    {
        cout<<output<<endl;
        return;
    }


         char first='a'-1+a[0];
         output[size2]=first;
         output[size2+1]='\0';
         allCodesH(a+1,size1-1, output,size2+1);
         output[size2]='\0';


     if(size1>1)
     {

         int num=10*a[0]+a[1];
         if(num<=26)
         {
         char second='a'-1+num;
        output[size2]=second;
         output[size2+1]='\0';
         allCodesH(a+2,size1-2, output,size2+1);
         output[size2]='\0';
         }

     }

}

void allCodes(int n)
{

      int rev=0;

    if(n==0)
    {
        return ;
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


    char output[20]="";
    allCodesH( a,m,output,0);

}

int main()
{

     allCodes(123);


    return 0;
}



